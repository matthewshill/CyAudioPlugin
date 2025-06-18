/*
  ==============================================================================

    CyCenterPanel.cpp
    Created: 11 Jun 2025 4:31:24pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyCenterPanel.h"

CyCenterPanel::CyCenterPanel(CyAudioPluginAudioProcessor* p) : CyPanelBase(p)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    cyMenuBar = std::make_unique<CyCenterPanelMenuBar>(p);
    cyMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(cyMenuBar.get());
    
    cyFXPanel= std::make_unique<CyFXPanel>(p);
    cyFXPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(cyFXPanel.get());
    
    cyMenuBar->addFxTypeComboBoxListener(cyFXPanel.get());
};

CyCenterPanel::~CyCenterPanel()
{
    
    cyMenuBar->removeFxTypeComboBoxListener(cyFXPanel.get());
};
