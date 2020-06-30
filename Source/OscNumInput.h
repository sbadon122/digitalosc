/*
  ==============================================================================

    OscNumInput.h
    Created: 29 Jun 2020 8:08:24pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscArrowButton.h"
#include "PluginProcessor.h"

class OscNumInput : public Component
{
public:
    OscNumInput(AudioProcessorValueTreeState& stateToControl,
                OSCParameter paramStateID,
                const String& componentName,
                const String& componentLabel);
    ~OscNumInput();
    
    void paint (Graphics& g) override;
    
private:
    std::unique_ptr<OscArrowButton> upButton;
    std::unique_ptr<OscArrowButton> downButton;
    std::unique_ptr<Label>          mLabel;
};
