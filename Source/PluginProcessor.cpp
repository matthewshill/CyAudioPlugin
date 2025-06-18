/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "CyParameters.h"
//==============================================================================
CyAudioPluginAudioProcessor::CyAudioPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this,
                                     nullptr,
                                     juce::Identifier("Params"),
                                     createParameterLayout())
#endif
{
    initializeDSP();
}

juce::AudioProcessorValueTreeState::ParameterLayout CyAudioPluginAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
//    for(int i = 0; i < cParameter_TotalNumParameters; ++i) {
//        layout.add(std::make_unique<juce::AudioParameterFloat>(
//                                         juce::ParameterID(CyParameterID[i], i),
//                                         CyParameterID[i],
//                                         juce::NormalisableRange<float>(0.0f,1.0f),
//                                         0.5));
//    }
  
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                     juce::ParameterID("InputGain", cParameter_InputGain),
                                     CyParameterID[cParameter_InputGain],
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                        juce::ParameterID("OutputGain", cParameter_OutputGain),
                                       "OutputGain",
                                       juce::NormalisableRange<float>(0.0f,1.0f),
                                       0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                      juce::ParameterID("ModulationRate", cParameter_ModulationRate),
                                     "ModulationRate",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                      juce::ParameterID("ModulationDepth", cParameter_ModulationDepth),
                                     "ModulationDepth",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                    juce::ParameterID("Time", cParameter_DelayTime),
                                     "Time",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                    juce::ParameterID("Feedback", cParameter_DelayFeedback),
                                     "Feedback",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                    juce::ParameterID("WetDry", cParameter_DelayWetDry),
                                     "WetDry",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
                                    juce::ParameterID("Type", cParameter_DelayWetDry),
                                     "Type",
                                     juce::NormalisableRange<float>(0.0f,1.0f),
                                     0.5));
    
    return layout;
}

CyAudioPluginAudioProcessor::~CyAudioPluginAudioProcessor()
{
}

//==============================================================================
const juce::String CyAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CyAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CyAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CyAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CyAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CyAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CyAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CyAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CyAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void CyAudioPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void CyAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for(int i = 0; i < 2; ++i) {
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]->setSampleRate(sampleRate);
    }
}

void CyAudioPluginAudioProcessor::releaseResources()
{
    for(int i = 0; i < 2; ++i) {
        mDelay[i]->reset();
        mLfo[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CyAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CyAudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        mInputGain[channel]->process(channelData,
                                *parameters.getRawParameterValue("InputGain"),
                                channelData,
                                buffer.getNumSamples());

        mLfo[channel]->process(0.0f,
                               *parameters.getRawParameterValue("ModulationDepth"),
                               buffer.getNumSamples());
        mDelay[channel]->process(channelData,
                                 *parameters.getRawParameterValue("Time"),
                                 *parameters.getRawParameterValue("Feedback"),
                                 *parameters.getRawParameterValue("WetDry"),
                                 *parameters.getRawParameterValue("Type"),
                                 mLfo[channel]->getBuffer(),
                                 channelData, buffer.getNumSamples());
        mOutputGain[channel]->process(channelData, *parameters.getRawParameterValue("OutputGain"), channelData, buffer.getNumSamples());
    }
}

//==============================================================================
bool CyAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* CyAudioPluginAudioProcessor::createEditor()
{
    return new CyAudioPluginAudioProcessorEditor (*this);
}

void CyAudioPluginAudioProcessor::initializeDSP()
{
    for(int i = 0; i < 2; ++i) {
        mInputGain[i] = std::make_unique<CyGain>();
        mDelay[i] = std::make_unique<CyDelay>();
        mLfo[i] = std::make_unique<CyLfo>();
    }
}

//==============================================================================
void CyAudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void CyAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CyAudioPluginAudioProcessor();
}
