/*
  ==============================================================================

    CyDelay.cpp
    Created: 15 Apr 2025 4:35:30pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyDelay.h"
#include "JuceHeader.h"
#include "CyAudioHelpers.h"

CyDelay::CyDelay()
:   mSampleRate(-1),
    mFeedbackSample(0.0),
    mTimeSmoothed(0),
    mDelayIndex(0)
{
    
}

CyDelay::~CyDelay()
{
    
}

void CyDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void CyDelay::reset()
{
    mTimeSmoothed = 0.0f;
    juce::zeromem(mBuffer, sizeof(double) * maxBufferSize);
}

void CyDelay::process(float *inAudio,
                      float inTime,
                      float inFeedback,
                      float inWetDry,
                      float inType,
                      float* inModBuffer,
                      float *outBuffer,
                      int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);

    for(int i = 0; i < inNumSamplesToRender; ++i) {
        if((int)inType == cDelayType_Delay) {
            mTimeSmoothed = mTimeSmoothed - KParameterSmoothingCoeff_Fine*(mTimeSmoothed-inTime);
        } else {
            const double delayTimeModulation = (0.03 + (0.002 * inModBuffer[i]));
            mTimeSmoothed = mTimeSmoothed - KParameterSmoothingCoeff_Fine*(mTimeSmoothed-(delayTimeModulation));
        }
        // remove discontinuity in waveform
        const double delayTimeModulation = (inTime + (0.002 * inModBuffer[i]));
        mTimeSmoothed = mTimeSmoothed - KParameterSmoothingCoeff_Fine * (mTimeSmoothed-(    delayTimeModulation));
        const double delayTimeInSamples = (mTimeSmoothed * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        mFeedbackSample = sample;
        outBuffer[i] = (inAudio[i]*dry + sample*wet);
        mDelayIndex = mDelayIndex + 1;
        if(mDelayIndex >= maxBufferSize) {
            mDelayIndex = mDelayIndex - maxBufferSize;
        }
    }
    
}

double CyDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if(readPosition < 0.0f) {
        readPosition = readPosition + maxBufferSize;
    }
    int index_y0 = (int)readPosition-1;
    
    if(index_y0 <= 0) {
        index_y0 = index_y0 + maxBufferSize;
    }
    int index_y1 = readPosition;
    
    if(index_y1 > maxBufferSize) {
        index_y1 = index_y1 - maxBufferSize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;

    double outSample = cy_linear_interp(sample_y0, sample_y1, t);
    return outSample;
}
