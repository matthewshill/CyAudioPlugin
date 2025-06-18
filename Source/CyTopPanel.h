/*
  ==============================================================================

    CyTopPanel.h
    Created: 11 Jun 2025 4:32:56pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"

class CyTopPanel : public CyPanelBase
{
public:
    CyTopPanel(CyAudioPluginAudioProcessor* inProcessor);
    ~CyTopPanel();
    void paint(juce::Graphics& g) override;
private:
    
};
