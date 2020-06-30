/*
  ==============================================================================

    OscMainPanel.cpp
    Created: 25 Jun 2020 6:57:57pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscMainPanel.h"
#include "OscInterfaceDefines.h"
#include "OscParameterDefines.h"

OscMainPanel::OscMainPanel(OscJucePluginAudioProcessor* inProcessor)
: OscBasePanel(inProcessor)
{
    auto params = mProcessor->getParameters();
    AudioParameterFloat* timerParameter = (AudioParameterFloat*) params.getUnchecked(0);
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mTimerSlider = std::make_shared<Slider>();
    mOscTopBar = std::make_unique<OscTopBar>(inProcessor, mTimerSlider);
    mTimerSlider->setRange(OSCParameterMinValue[oParameter_Timer], OSCParameterMaxValue[oParameter_Timer]);
    mOscTopBar->setTopLeftPosition(0,0);
    addAndMakeVisible(mOscTopBar.get());
    
    mOscCenterPanel = std::make_unique<OscCenterPanel>(inProcessor, mTimerSlider);
    mOscCenterPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mOscCenterPanel.get());
    mTimerSlider->onValueChange = [this, timerParameter] {
        mOscCenterPanel->setTimer(mTimerSlider->getValue());
        *timerParameter = mTimerSlider->getValue();
    };
    
    
}

OscMainPanel::~OscMainPanel()
{
    
}

void OscMainPanel::paint(Graphics& g)
{
    
}
