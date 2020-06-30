/*
  ==============================================================================

    OscMainPanel.h
    Created: 25 Jun 2020 6:57:57pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscBasePanel.h"
#include "OscTopBar.h"
#include "OscCenterPanel.h"


class OscMainPanel : public OscBasePanel
{
public:
    OscMainPanel(OscJucePluginAudioProcessor* inProcessor);
    ~OscMainPanel();
    void paint(Graphics& g) override;
    
private:
    std::unique_ptr<OscTopBar> mOscTopBar;
    std::unique_ptr<OscCenterPanel> mOscCenterPanel;
    std::shared_ptr<Slider> mTimerSlider;
    
};
