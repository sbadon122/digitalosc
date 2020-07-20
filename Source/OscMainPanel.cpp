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
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mTimerSlider = std::make_shared<OscSlider>(mProcessor->parameters,OSCParameterID[oParameter_Timer], OSCParameterLabel[oParameter_Timer]);
    
    mAboutButton = std::make_shared<OscButton>(mProcessor->parameters,OSCParameterID[oParameter_ShowCredits], OSCParameterLabel[oParameter_ShowCredits]);

    mOscCenterPanel = std::make_unique<OscCenterPanel>(inProcessor, mTimerSlider);
    mOscCenterPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mOscCenterPanel.get());
    
    mOscTopBar = std::make_unique<OscTopBar>(inProcessor, mTimerSlider, mAboutButton);
    mOscTopBar->setTopLeftPosition(0,0);
    addAndMakeVisible(mOscTopBar.get());
    
   mTimerSlider->onValueChange = [this] {
        mOscCenterPanel->setTimer(mTimerSlider->getValue());
   };
    
   mAboutButton->onClick = [this] {
       mOscCenterPanel->setCredits(mAboutButton->getToggleState());
   };
    
    
}

OscMainPanel::~OscMainPanel()
{
    
}

void OscMainPanel::paint(Graphics& g)
{
    
}
