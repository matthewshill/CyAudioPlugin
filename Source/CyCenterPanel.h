/*
  ==============================================================================

    CyCenterPanel.h
    Created: 11 Jun 2025 4:31:24pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"
#include "CyCenterPanelMenuBar.h"
#include "CyFxPanel.h"

class CyCenterPanel: public CyPanelBase
{
public:
    CyCenterPanel(CyAudioPluginAudioProcessor* p);
    ~CyCenterPanel();
private:
    std::unique_ptr<CyCenterPanelMenuBar> cyMenuBar;
    std::unique_ptr<CyFXPanel> cyFXPanel;
};
