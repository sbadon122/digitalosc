/*
  ==============================================================================

    OscParameterDefines.h
    Created: 25 Jun 2020 10:33:41pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

enum OSCParameter
{
    oParameter_Timer = 0,
    oParameter_Freeze,
    oParameter_TotalNumParameters,
};

static String OSCParameterID [oParameter_TotalNumParameters] =
{
    "Timer",
    "Freeze",
};

static String OSCParameterLabel [oParameter_TotalNumParameters] =
{
    "Timer",
    "Freeze",
    
};

static float OSCParameterDefaultValue [oParameter_TotalNumParameters] =
{
    10.0f,
    0.f,
};


static float OSCParameterMinValue [oParameter_TotalNumParameters] =
{
    5.0f,
    0.f,
};

static float OSCParameterMaxValue [oParameter_TotalNumParameters] =
{
    100.0f,
    1.0f,
};
