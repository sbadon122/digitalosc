/*
  ==============================================================================

    OscTopBar.h
    Created: 25 Jun 2020 6:58:52pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscCenterPanel.h"
#include "OscButton.h"
#include "OscSlider.h"
#include "OscLookAndFeel.h"
//==============================================================================
/*
*/
class OscTopBar    : public OscBasePanel
{
public:
    OscTopBar(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer, std::shared_ptr<OscButton> aboutButton);
    ~OscTopBar();

    void paint (Graphics& g) override;

private:
    std::unique_ptr<OscButton> mFreezeButton;
    std::unique_ptr<OscButton> mAverageButton;
    std::unique_ptr<OscButton> mLeftChannelButton;
    std::unique_ptr<OscButton> mRightChannelButton;
    std::shared_ptr<OscButton> mShowCreditsButton;
    std::shared_ptr<Slider>    mTimerSlider;
    std::unique_ptr<OscLookAndFeel> lookAndFeel;
    

    
};
