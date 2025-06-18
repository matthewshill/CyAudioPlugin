/*
  ==============================================================================

    CyGain.h
    Created: 15 Apr 2025 4:35:15pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

class CyGain
{
public:
    CyGain();
    ~CyGain();
    void process(float *inAudio, float inGain, float *outAudio, float inNumSamples);
private:
};
