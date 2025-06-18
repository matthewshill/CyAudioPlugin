/*
  ==============================================================================

    CyTopPanel.cpp
    Created: 11 Jun 2025 4:32:56pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyTopPanel.h"

CyTopPanel::CyTopPanel(CyAudioPluginAudioProcessor* inProcessor)
: CyPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
};

CyTopPanel::~CyTopPanel() {
    
};

void CyTopPanel::paint(juce::Graphics& g) {
    CyPanelBase::paint(g);
    g.drawFittedText("MSH D-FX", 0,0, getWidth()-10, getHeight(), juce::Justification::centredRight, 1);
    
};
