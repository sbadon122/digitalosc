/*
  ==============================================================================

    OscButton.cpp
    Created: 27 Jun 2020 12:41:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscButton.h"
#include "OscInterfaceDefines.h"

#define BUTTON_SIZE_SCALER 0.6

OscButton::OscButton(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel) :
juce::Button(parameterID)
{
    mAttachment = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(stateToControl, parameterID, *this);
    mLabel = std::make_unique<Label>("label"+parameterID,parameterLabel);
    mLabel->setFont(font_2);
    setClickingTogglesState(true);
    addAndMakeVisible(mLabel.get());
    mLabel->setJustificationType(Justification::centred);
    
}

OscButton::~OscButton()
{
        
}

void OscButton::paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted,bool shouldDrawButtonAsDown)
{
    if(getToggleState())
    {
        g.setColour(OSCButton_Colour2);
    }
    else {
        g.setColour(OSCButton_Colour1);
    }
    const double cornerSize = 2.5;
    const double buttonHeight = calculateButtonHeight();
    g.fillRoundedRectangle(0,0,getWidth(), buttonHeight, cornerSize);
    
    
}

void OscButton::paint (Graphics& g)
{
    const double buttonHeight = calculateButtonHeight();
    Button::paint(g);
    g.setColour(OSCColour_2);
    mLabel->setBounds(0, buttonHeight, getWidth(), getHeight()-buttonHeight);
}

double OscButton::calculateButtonHeight()
{
    return getHeight()*BUTTON_SIZE_SCALER;
}
