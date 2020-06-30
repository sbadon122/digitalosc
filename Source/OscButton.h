/*
  ==============================================================================

    OscButton.h
    Created: 27 Jun 2020 12:41:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscButton : public Button
{
public:
    OscButton(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel);
    ~OscButton();
    
    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted,bool shouldDrawButtonAsDown) override;
    void paint(Graphics& g) override;
private:
    double calculateButtonHeight();
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> mAttachment;
    std::unique_ptr<Label> mLabel;
};
