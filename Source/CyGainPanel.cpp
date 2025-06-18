/*
  ==============================================================================

    CyGainPanel.cpp
    Created: 11 Jun 2025 4:32:14pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyGainPanel.h"
#include "CyParameters.h"
#include "CyHelperFunctions.h"

CyGainPanel::CyGainPanel(CyAudioPluginAudioProcessor* p) : CyPanelBase(p)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

CyGainPanel::~CyGainPanel()
{
    
}

void CyGainPanel::paint(juce::Graphics& g)
{
    CyPanelBase::paint(g);
    if(slider) {
        paintComponentLabels(g, slider.get());
    }
}


void CyGainPanel::setParameterID(int inParameterID) {
    slider = std::make_unique<CyParameterSlider>(cyProcessor->parameters, CyParameterID[inParameterID]);
    const int sliderSize = 54;
    slider->setBounds((getWidth() * 0.5) - (sliderSize * 0.5),
                      (getHeight() * 0.5) - (sliderSize * 0.5),
                      sliderSize, sliderSize);
    
    addAndMakeVisible(slider.get());
}


