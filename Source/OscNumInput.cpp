/*
  ==============================================================================

    OscNumInput.cpp
    Created: 29 Jun 2020 8:08:24pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscNumInput.h"
#include "OscParameterDefines.h"

/**
Work In Progress Component
Please Ignore
*/

OscNumInput::OscNumInput(AudioProcessorValueTreeState& stateToControl,
                         OSCParameter paramStateID,
                         const String& componentName,
                         const String& componentLabel)
{
    //std::atomic<float>* inputVal = stateToControl.getRawParameterValue(0);
    upButton = std::make_unique<OscArrowButton>(stateToControl,paramStateID,"up"+componentName,true);
    downButton = std::make_unique<OscArrowButton>(stateToControl,paramStateID,"down"+componentName,false);
    mLabel = std::make_unique<Label>("label"+componentLabel, componentLabel);
    addAndMakeVisible(upButton.get());
    addAndMakeVisible(downButton.get());
    addAndMakeVisible(mLabel.get());
    
    
    upButton->setBounds(getWidth()/2.0, 0, getWidth()/2.0, getHeight()/2);
    downButton->setBounds(getWidth()/2.0, getHeight()/2, getWidth()/2.0, getHeight()/2);
    mLabel->setBounds(0, 0, getWidth()/2.0, getHeight());
    //mLabel->setText(""+inputVal, NotificationType::dontSendNotification);
}
OscNumInput::~OscNumInput()
{
    
}

void OscNumInput::paint (Graphics& g)
{
    
}
