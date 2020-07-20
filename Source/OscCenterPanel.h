/*
  ==============================================================================

    OscCenterPanel.h
    Created: 25 Jun 2020 7:22:06pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once


#include "OscBasePanel.h"
#include "OscButton.h"


class OscCenterPanel : public OscBasePanel, public Timer
{
public:
    OscCenterPanel(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer);
    ~OscCenterPanel();
    void paint(Graphics& g) override;
    void timerCallback() override;
    void setTimer(double newTimerValue);
    void setCredits(bool showVal);
    
private:
    
    void paintWaveform(Graphics& g);
    void paintCredits(Graphics& g);
    std::shared_ptr<Slider> mTimerSlider;
    std::atomic<float>* timerVal;
    std::atomic<float>* leftChannel;
    std::atomic<float>* rightChannel;
    float opacity;
    float timerSliderVal;
    
    bool showCredits;
};
