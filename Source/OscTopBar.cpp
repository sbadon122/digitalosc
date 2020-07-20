/*
  ==============================================================================

    OscTopBar.cpp
    Created: 25 Jun 2020 6:58:52pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscTopBar.h"
#include "OscInterfaceDefines.h"
#include "OscParameterDefines.h"

#define PADDING_CONSTANT 0.05f

//==============================================================================
OscTopBar::OscTopBar(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer, std::shared_ptr<OscButton> aboutButton):
OscBasePanel(inProcessor), mShowCreditsButton(aboutButton), mTimerSlider(sliderTimer)
{
    mFreezeButton = std::make_unique<OscButton>(inProcessor->parameters,OSCParameterID[oParameter_Freeze], OSCParameterLabel[oParameter_Freeze]);
    
    mAverageButton = std::make_unique<OscButton>(inProcessor->parameters,OSCParameterID[oParameter_Average], OSCParameterLabel[oParameter_Average]);
    
    mLeftChannelButton = std::make_unique<OscButton>(inProcessor->parameters,OSCParameterID[oParameter_LeftChannel], OSCParameterLabel[oParameter_LeftChannel]);
    
    mRightChannelButton = std::make_unique<OscButton>(inProcessor->parameters,OSCParameterID[oParameter_RightChannel], OSCParameterLabel[oParameter_RightChannel]);
    
    lookAndFeel = std::make_unique<OscLookAndFeel>();
    
    mTimerSlider->setLookAndFeel(lookAndFeel.get());


    
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mTimerSlider->setRange(OSCParameterMinValue[oParameter_Timer], OSCParameterMaxValue[oParameter_Timer], 1);
    addAndMakeVisible(mTimerSlider.get());
    addAndMakeVisible(mFreezeButton.get());
    addAndMakeVisible(mAverageButton.get());
    addAndMakeVisible(mLeftChannelButton.get());
    addAndMakeVisible(mRightChannelButton.get());
    addAndMakeVisible(mShowCreditsButton.get());
    
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

OscTopBar::~OscTopBar()
{
}

void OscTopBar::paint (Graphics& g)
{
    OscBasePanel::paint(g);
    const int sliderSize = 100;
    const int textBoxSize = 15;
    const float padding = getWidth()*PADDING_CONSTANT;
    mTimerSlider->setBounds(padding, padding*0.25, sliderSize, TOP_PANEL_HEIGHT-textBoxSize*0.5f);
    mTimerSlider->setTextBoxStyle(Slider::TextBoxAbove, true, textBoxSize*3, textBoxSize);
    g.setColour(OSCColour_1);
    g.setFont(font_1);
    
    const int label_w = 150;
    
    mFreezeButton->setBounds(2*padding+sliderSize, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
    mAverageButton->setBounds(2.5*padding+sliderSize + TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
    mLeftChannelButton->setBounds(3*padding+sliderSize + 2 * TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
    mRightChannelButton->setBounds(3.5*padding+sliderSize + 3 * TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
    g.drawFittedText("OscilloSCOPE", 4*padding+sliderSize + 4 * TOP_PANEL_WIDTH*.07, 0, label_w, getHeight(), Justification::left, 1);
    mShowCreditsButton->setBounds(3.5*padding+sliderSize + 3 * TOP_PANEL_WIDTH*.07 + label_w, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
}
