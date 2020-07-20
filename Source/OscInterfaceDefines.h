/*
  ==============================================================================

    OscInterfaceDefines.h
    Created: 25 Jun 2020 7:24:26pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define MAIN_PANEL_WIDTH    500
#define MAIN_PANEL_HEIGHT   300

#define TOP_PANEL_WIDTH     MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT    50

#define CIRCULAR_BUFFER_LENGTH 500

#define CENTER_PANEL_WIDTH  MAIN_PANEL_WIDTH
#define CENTER_PANEL_HEIGHT MAIN_PANEL_HEIGHT-TOP_PANEL_HEIGHT

const Colour OSCColour_1 = Colour(105,105,105);
const Colour OSCColour_2 = Colour(105,105,105).withAlpha(0.3f);
const Colour OSCColour_3 = Colour(53,53,53);
const Colour OSCStroke_Colour1 =  Colour(50,168,158).withAlpha (0.5f);
const Colour OSCStroke_Colour2 =  Colour(240,127,14).withAlpha (0.5f);
const Colour OSCButton_Colour1 =  Colour(240,127,14).withAlpha (0.5f);
const Colour OSCButton_Colour2 =  Colour(240,127,14).withAlpha (0.75f);
const Colour OSCButton_Colour3 =  Colour(240,127,14).withAlpha (0.25f);

const Font font_1 ( "Helvetic Neue", 14.0f, Font::bold);
const Font font_2 ( "Helvetic Neue", 8.0f, Font::bold);
