/*
  ==============================================================================

    CyComboBox.cpp
    Created: 13 Jun 2025 4:31:43pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyComboBox.h"

CyParameterComboBox::CyParameterComboBox (juce::AudioProcessorValueTreeState& stateToControl,
                  const juce::String& parameterID)
: juce::ComboBox(parameterID)
{
    cAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}

CyParameterComboBox::~CyParameterComboBox()
{
    
}
