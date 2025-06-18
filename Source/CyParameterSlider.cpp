/*
  ==============================================================================

    CyParameterSlider.cpp
    Created: 13 Jun 2025 4:31:35pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyParameterSlider.h"

CyParameterSlider::CyParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
                                     const juce::String& parameterID)
: juce::Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    cAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

CyParameterSlider::~CyParameterSlider()
{
    
}
