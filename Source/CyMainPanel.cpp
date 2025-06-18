/*
  ==============================================================================

    CyMainPanel.cpp
    Created: 11 Jun 2025 4:31:11pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyMainPanel.h"
#include "CyParameters.h"

CyMainPanel::CyMainPanel(CyAudioPluginAudioProcessor* inProcessor) : CyPanelBase(inProcessor) {
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    topPanel = std::make_unique<CyTopPanel>(inProcessor);
    topPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(topPanel.get());
    
    inputGainPanel = std::make_unique<CyGainPanel>(inProcessor);
    inputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    inputGainPanel->setParameterID(cParameter_InputGain);
    addAndMakeVisible(inputGainPanel.get());

    outputGainPanel = std::make_unique<CyGainPanel>(inProcessor);
    outputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH-GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    outputGainPanel->setParameterID(cParameter_OutputGain);
    addAndMakeVisible(outputGainPanel.get());
    
    centerPanel = std::make_unique<CyCenterPanel>(inProcessor);
    centerPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(centerPanel.get());
};

CyMainPanel::~CyMainPanel(){
    
};
