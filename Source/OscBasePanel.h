/*
  ==============================================================================

    OscBasePanel.h
    Created: 24 Jun 2020 10:40:44pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once


#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class OscBasePanel
:   public Component
{
public:
    OscBasePanel(OscJucePluginAudioProcessor* inProcessor);
    ~OscBasePanel();
    void paint(Graphics& g) override;
    
    
protected:
    OscJucePluginAudioProcessor* mProcessor;
};
