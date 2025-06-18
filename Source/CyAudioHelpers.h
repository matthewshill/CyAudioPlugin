/*
  ==============================================================================

    CyAudioHelpers.h
    Created: 15 Apr 2025 4:34:52pm
    Author:  Matthew Hill

  ==============================================================================
*/

#pragma once

#define kParameterSmoothingCoeff_Generic 0.04
#define KParameterSmoothingCoeff_Fine 0.02

const int maxBufferSize = 192000;
const static double CyPi = 3.14159265359;
const static double CyPi2 = 6.2831853072;

inline float cy_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}
