/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CyAudioPluginAudioProcessorEditor::CyAudioPluginAudioProcessorEditor (CyAudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mainPanel = std::make_unique<CyMainPanel>(&audioProcessor);
    addAndMakeVisible(mainPanel.get());
    
    auto& params = audioProcessor.getParameters();
}

CyAudioPluginAudioProcessorEditor::~CyAudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void CyAudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void CyAudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
