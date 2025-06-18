/*
  ==============================================================================

    CyParameters.h
    Created: 13 Jun 2025 3:34:55pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

enum CyParameter
{
    cParameter_InputGain = 1,
    cParameter_DelayTime,
    cParameter_DelayFeedback,
    cParameter_DelayWetDry,
    cParameter_DelayType,
    cParameter_OutputGain,
    cParameter_ModulationRate,
    cParameter_ModulationDepth,
    cParameter_TotalNumParameters
};

static juce::String CyParameterID [cParameter_TotalNumParameters] =
{
    "Placeholder",
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth",
};
