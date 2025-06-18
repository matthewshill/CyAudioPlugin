/*
  ==============================================================================

    CyMainPanel.h
    Created: 11 Jun 2025 4:31:11pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"
#include "CyTopPanel.h"
#include "CyGainPanel.h"
#include "CyCenterPanel.h"

class CyMainPanel : public CyPanelBase
{
public:
    CyMainPanel(CyAudioPluginAudioProcessor* inProcessor);
    ~CyMainPanel();

private:
    std::unique_ptr<CyTopPanel> topPanel;
    std::unique_ptr<CyGainPanel> inputGainPanel;
    std::unique_ptr<CyGainPanel> outputGainPanel;
    std::unique_ptr<CyCenterPanel> centerPanel;
};
