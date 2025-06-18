/*
  ==============================================================================

    CyGain.cpp
    Created: 15 Apr 2025 4:35:15pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyGain.h"
#include "JuceHeader.h"

CyGain::CyGain()
{
    
}

CyGain::~CyGain()
{
    
}

void CyGain::process(float *inAudio,
                float inGain,
                float *outAudio,
                float inNumSamplesToRender)
{
    float gainMapped = juce::jmap(inGain, 0.0f, 1.0f, -24.0f,  24.0f);
    gainMapped = juce::Decibels::gainToDecibels(gainMapped, -24.0f);
    
    for(int i = 0; i < inNumSamplesToRender; ++i) {
        outAudio[i] = inAudio[i] * gainMapped;
     }
}

