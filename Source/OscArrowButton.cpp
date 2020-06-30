/*
  ==============================================================================

    OscArrowButton.cpp
    Created: 29 Jun 2020 8:09:43pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscArrowButton.h"
#include "OscInterfaceDefines.h"

/**
Work In Progress Component
Please Ignore
*/
OscArrowButton::OscArrowButton(AudioProcessorValueTreeState& stateToControl, OSCParameter paramStateID, const String& parameterID, bool isUpArrow) :
juce::Button(parameterID), mUpArrow(isUpArrow)
{
//    std::atomic<float>* inputVal = stateToControl.getRawParameterValue(0);
//    double minVal = OSCParameterMinValue[paramStateID];
//    double maxVal = OSCParameterMaxValue[paramStateID];
//    onClick = [this, inputVal, maxVal, minVal] {
//        if(mUpArrow && maxVal)
//        {
//            *inputVal = *inputVal + 1;
//        }
//        else if(!mUpArrow && minVal) {
//            *inputVal = *inputVal - 1;
//        }
//    };
}

OscArrowButton::~OscArrowButton()
{
        
}

void OscArrowButton::paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted,bool shouldDrawButtonAsDown)
{
   Path arrow;
   g.setColour(OSCButton_Colour1);
   if(mUpArrow)
   {
       arrow.addTriangle(0, getHeight(), getWidth()/2.0, 0, getWidth(), getHeight());
   }
   else
   {
       arrow.addTriangle(0, 0, getWidth()/2.0, getHeight(), getWidth(), 0);
   }
    
   g.fillPath(arrow);
}

void OscArrowButton::paint (Graphics& g)
{
    Button::paint(g);
}
