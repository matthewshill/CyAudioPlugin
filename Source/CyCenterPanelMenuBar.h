/*
  ==============================================================================

    CyCenterPanelMenuBar.h
    Created: 11 Jun 2025 4:31:54pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "CyPanelBase.h"
#include "CyComboBox.h"

using namespace juce;

class CyCenterPanelMenuBar : public CyPanelBase
{
    public:
        CyCenterPanelMenuBar(CyAudioPluginAudioProcessor* p);
        ~CyCenterPanelMenuBar();
        void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
        void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);

    private:
    std::unique_ptr<CyParameterComboBox> cFxTypeComboBox;
};
