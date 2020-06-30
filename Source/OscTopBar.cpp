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
OscTopBar::OscTopBar(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer):
OscBasePanel(inProcessor),
mTimerSlider(sliderTimer)
{
    mFreezeButton = std::make_unique<OscButton>(inProcessor->parameters,OSCParameterID[oParameter_Freeze], OSCParameterLabel[oParameter_Freeze]);
    mNumInput = std::make_unique<OscNumInput>(inProcessor->parameters,oParameter_Timer,OSCParameterID[oParameter_Timer],OSCParameterLabel[oParameter_Timer]);
    
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    const float padding = getWidth()*PADDING_CONSTANT;
    mTimerSlider->setTopLeftPosition(padding, 0);
    mTimerSlider->setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    mTimerSlider->setRange(OSCParameterMinValue[oParameter_Timer], OSCParameterMaxValue[oParameter_Timer], 1);
    addAndMakeVisible(mTimerSlider.get());
    addAndMakeVisible(mFreezeButton.get());
    //addAndMakeVisible(mNumInput.get());
    mNumInput->setTopLeftPosition(padding, 0);
    
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
    mTimerSlider->setBounds(padding, 0, sliderSize, TOP_PANEL_HEIGHT-textBoxSize*0.5f);
    mTimerSlider->setTextBoxStyle(Slider::TextBoxBelow, true, textBoxSize*3, textBoxSize);
    //mNumInput->setBounds(0, 0, getWidth(), getHeight());
    g.setColour(OSCColour_1);
    g.setFont(font_1);
    
    const int label_w = 150;
    g.drawFittedText("OscilloDOPE", TOP_PANEL_WIDTH-label_w-padding, 0, label_w, getHeight(), Justification::right, 1);
    
    mFreezeButton->setBounds(2*padding+sliderSize, TOP_PANEL_HEIGHT*.2, TOP_PANEL_WIDTH*.07, TOP_PANEL_HEIGHT*.8);
}

