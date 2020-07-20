/*
  ==============================================================================

    OscSlider.cpp
    Created: 30 Jun 2020 8:40:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscSlider.h"

#include <JuceHeader.h>

OscSlider::OscSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel)
{
    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
    setSliderStyle (Slider::IncDecButtons);
    setTextBoxIsEditable(true);
}

OscSlider::~OscSlider()
{

}

