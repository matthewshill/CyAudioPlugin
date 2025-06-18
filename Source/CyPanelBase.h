/*
  ==============================================================================

    CyPanelBase.h
    Created: 11 Jun 2025 4:32:26pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "CyInterfaceDefines.h"

class CyPanelBase : public juce::Component {
public:
    CyPanelBase(CyAudioPluginAudioProcessor* inProcessor);
    ~CyPanelBase();
    void paint(juce::Graphics& g);
protected:
    CyAudioPluginAudioProcessor* cyProcessor;
    
};
