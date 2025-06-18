/*
  ==============================================================================

    CyCenterPanelMenuBar.cpp
    Created: 11 Jun 2025 4:31:54pm
    Author:  Matthew Hill

  ==============================================================================
*/
#include "CyCenterPanelMenuBar.h"
#include "CyParameters.h"

CyCenterPanelMenuBar::CyCenterPanelMenuBar(CyAudioPluginAudioProcessor* p) : CyPanelBase(p)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
    const int width = 85;
    cFxTypeComboBox = std::make_unique<CyParameterComboBox>(cyProcessor->parameters, CyParameterID[cParameter_DelayType]);
    cFxTypeComboBox->setBounds(getWidth()- width,0,width, getHeight());
    cFxTypeComboBox->addItem("DELAY", 1);
    cFxTypeComboBox->addItem("CHORUS", 2);
    auto* delayType = cyProcessor->parameters.getRawParameterValue("Type");
    cFxTypeComboBox->setSelectedItemIndex(delayType->load(), juce::dontSendNotification);
    addAndMakeVisible(cFxTypeComboBox.get());
}

CyCenterPanelMenuBar::~CyCenterPanelMenuBar() {
        
}

void CyCenterPanelMenuBar::addFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
    cFxTypeComboBox->addListener(inListener);
}

void CyCenterPanelMenuBar::removeFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
    cFxTypeComboBox->removeListener(inListener);
}
