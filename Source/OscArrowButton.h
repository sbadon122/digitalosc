/*
  ==============================================================================

    OscArrowButton.h
    Created: 29 Jun 2020 8:09:43pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscParameterDefines.h"
class OscArrowButton : public Button
{
public:
    OscArrowButton(AudioProcessorValueTreeState& stateToControl, OSCParameter paramStateID, const String& parameterID, bool isUpArrow);
    ~OscArrowButton();
    
    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted,bool shouldDrawButtonAsDown) override;
    void paint(Graphics& g) override;
private:
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> mAttachment;
    bool mUpArrow;
};
