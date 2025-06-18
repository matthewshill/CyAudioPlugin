/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CyGain.h"
#include "CyDelay.h"
#include "CyLfo.h"

//==============================================================================
/**
*/
class CyAudioPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    CyAudioPluginAudioProcessor();
    ~CyAudioPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    juce::AudioProcessorValueTreeState parameters;
    
private:
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void initializeDSP();
    
    std::unique_ptr<CyGain> mInputGain[2];
    std::unique_ptr<CyGain> mOutputGain[2];
    std::unique_ptr<CyDelay> mDelay[2];
    std::unique_ptr<CyLfo> mLfo[2];
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CyAudioPluginAudioProcessor)
};
