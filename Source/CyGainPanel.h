/*
  ==============================================================================

    CyGainPanel.h
    Created: 11 Jun 2025 4:32:14pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"
#include "CyParameterSlider.h"


class CyGainPanel : public CyPanelBase
{
public:
    CyGainPanel(CyAudioPluginAudioProcessor* inProcessor);
    ~CyGainPanel();
    
    void paint(juce::Graphics& g) override;
    
    void setParameterID(int inParamterID);
private:
    std::unique_ptr<CyParameterSlider> slider;
};
