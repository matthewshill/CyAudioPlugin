/*
  ==============================================================================

    CyComboBox.h
    Created: 13 Jun 2025 4:31:43pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

class CyParameterComboBox : public juce::ComboBox
{
public:
    CyParameterComboBox (juce::AudioProcessorValueTreeState& stateToControl,
                      const juce::String& parameterID);
    ~CyParameterComboBox ();

private:
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> cAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CyParameterComboBox);
};
