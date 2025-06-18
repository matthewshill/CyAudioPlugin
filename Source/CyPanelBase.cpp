/*
  ==============================================================================

    CyPanelBase.cpp
    Created: 11 Jun 2025 4:32:26pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyPanelBase.h"

CyPanelBase::CyPanelBase(CyAudioPluginAudioProcessor* inProcessor) : cyProcessor(inProcessor) {
    
};

CyPanelBase::~CyPanelBase() {
    
};

void CyPanelBase::paint(juce::Graphics& g) {
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
};



