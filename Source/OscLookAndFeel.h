/*
 ==============================================================================
 
 OscLookAndFeel.h
 Created: 7 Jul 2020 7:05:06pm
 Author:  Sebastian Badon
 
 ==============================================================================
 */

#pragma once
#include <JuceHeader.h>
#include "OscInterfaceDefines.h"

#define BUTTON_SIZE_SCALER 0.6

class OscLookAndFeel : public LookAndFeel_V4 {
public:
    
    void drawButtonBackground (Graphics& g,
                                               Button& button,
                                               const Colour& backgroundColour,
                                               bool shouldDrawButtonAsHighlighted,
                                               bool shouldDrawButtonAsDown) override
    {
       if(shouldDrawButtonAsDown)
        {
            g.setColour(OSCButton_Colour2);
        }
        else {
            g.setColour(OSCButton_Colour1);
        }
        const double cornerSize = 2.5;
        const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat();
        g.fillRoundedRectangle(bounds, cornerSize);
    }
private:
};
