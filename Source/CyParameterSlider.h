/*
  ==============================================================================

    CyParameterSlider.h
    Created: 13 Jun 2025 4:31:35pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class CyParameterSlider : public juce::Slider
{
public:
    CyParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
                      const juce::String& parameterID);
    ~CyParameterSlider();

private:
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CyParameterSlider);
};
