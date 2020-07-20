/*
  ==============================================================================

    OscHelperFunctions.h
    Created: 2 Jul 2020 9:50:43am
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

inline float oscLinearInterpolation(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}
