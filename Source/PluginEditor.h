/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <memory>
#include "PluginProcessor.h"
#include "CyMainPanel.h"
//==============================================================================
/**
*/
class CyAudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    CyAudioPluginAudioProcessorEditor (CyAudioPluginAudioProcessor&);
    ~CyAudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CyAudioPluginAudioProcessor& audioProcessor;
    std::unique_ptr<CyMainPanel> mainPanel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CyAudioPluginAudioProcessorEditor)
};
