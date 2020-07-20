/*
  ==============================================================================

    OscSlider.h
    Created: 30 Jun 2020 8:40:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscSlider : public Slider
{
public:
    OscSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel);
    ~OscSlider();
private:
    double calculateButtonHeight();
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
};
