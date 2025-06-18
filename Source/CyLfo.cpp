/*
  ==============================================================================

    CyLfo.cpp
    Created: 15 Apr 2025 4:35:21pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyLfo.h"
#include "JuceHeader.h"

CyLfo::CyLfo()
{
    reset();
}

CyLfo::~CyLfo()
{
    
}

void CyLfo::reset() {
    cyPhase = 0.0f;
    juce::zeromem(cyBuffer, sizeof(float) * maxBufferSize);
}

void CyLfo::setSampleRate(double inSampleRate) {
    cySampleRate = inSampleRate;
}

float* CyLfo::getBuffer() {
    return cyBuffer;
}


void CyLfo::process(float inRate, float inDepth, int inNumSamples) {
    const float rate = juce::jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for(int i = 0; i < inNumSamples; ++i) {
        cyPhase = cyPhase  + (rate / cySampleRate);
        
        if(cyPhase > 1.0f) {
            cyPhase = cyPhase - 1.0f;
        }
        
        const float lfoPosition = sinf(cyPhase * CyPi2) * inDepth;
        cyBuffer[i] = lfoPosition;
    }
    

}
