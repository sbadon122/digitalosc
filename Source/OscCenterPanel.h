/*
  ==============================================================================

    OscCenterPanel.h
    Created: 25 Jun 2020 7:22:06pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once


#include "OscBasePanel.h"


class OscCenterPanel : public OscBasePanel, public Timer
{
public:
    OscCenterPanel(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer);
    ~OscCenterPanel();
    void paint(Graphics& g) override;
    void timerCallback() override;
    void setTimer(double newTimerValue);
    
private:
    std::shared_ptr<Slider> mTimerSlider;
    
};
