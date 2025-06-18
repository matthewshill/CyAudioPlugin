/*
  ==============================================================================

    CyLfo.h
    Created: 15 Apr 2025 4:35:21pm
    Author:  Matthew Hill

  ==============================================================================
*/
#include "CyAudioHelpers.h"

#pragma once

class CyLfo
{
public:
    CyLfo();
    ~CyLfo();
    
    void reset();
    float* getBuffer();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, int inNumSamples);
    
private:
    double cySampleRate;
    float cyPhase;
    float cyBuffer[maxBufferSize];
};
