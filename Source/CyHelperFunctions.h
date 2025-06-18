/*
  ==============================================================================

    CyHelperFunctions.h
    Created: 13 Jun 2025 6:27:25pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

inline void paintComponentLabels(juce::Graphics& g, juce::Component* inComponent)
{
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    
    const juce::String label = inComponent->getName();
    const float cornerSize = 3.0f;
    
    g.setColour(juce::Colours::darkgrey);
    g.drawFittedText(label, x, y, w, h, juce::Justification::centred, 1);
}

