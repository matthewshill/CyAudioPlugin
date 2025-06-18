/*
  ==============================================================================

    CyFxPanel.h
    Created: 11 Jun 2025 4:31:34pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"
#include "CyParameterSlider.h"

enum CyFXPanelStyle {
    CyFXPanelStyle_Delay,
    CyFXPanelStyle_Chorus,
    CyFXPanelStyle_TotalNumStyles
};

class CyFXPanel : public CyPanelBase, public juce::ComboBox::Listener
{
public:
    CyFXPanel(CyAudioPluginAudioProcessor* inProcessor);
    ~CyFXPanel();
    void setFXPanelStyle(CyFXPanelStyle inStyle);
    void paint(juce::Graphics &g) override;
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;

private:
    CyFXPanelStyle panelStyle;
    juce::OwnedArray<CyParameterSlider> cSliders;
};
