/*
  ==============================================================================

    CyDelay.h
    Created: 15 Apr 2025 4:35:30pm
    Author:  Matthew Hill

  ==============================================================================
*/
#include "CyAudioHelpers.h"

#pragma once

enum CyDelayType
{
    cDelayType_Delay = 0,
    cDelayType_Chorus
};

class CyDelay
{
public:
    CyDelay();
    ~CyDelay();
    
    void setSampleRate(double inSamples);
    void reset();
    
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModBuffer,
                 float* outBuffer,
                 int inNumSamplesToRender);
    double getInterpolatedSample(float inDelayTimeInSamples);
private:
    double mSampleRate;
    double mBuffer[maxBufferSize];
    double mFeedbackSample;
    float mTimeSmoothed;
    int mDelayIndex;
};
