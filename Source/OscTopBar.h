/*
  ==============================================================================

    OscTopBar.h
    Created: 25 Jun 2020 6:58:52pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscBasePanel.h"
#include "OscButton.h"
#include "OscNumInput.h"
//==============================================================================
/*
*/
class OscTopBar    : public OscBasePanel
{
public:
    OscTopBar(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer);
    ~OscTopBar();

    void paint (Graphics& g) override;

private:
    std::shared_ptr<Slider> mTimerSlider;
    std::unique_ptr<OscButton> mFreezeButton;
    std::unique_ptr<OscNumInput> mNumInput;
    

    
};
