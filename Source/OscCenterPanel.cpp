/*
  ==============================================================================

    OscCenterPanel.cpp
    Created: 25 Jun 2020 7:22:06pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscCenterPanel.h"
#include "OscInterfaceDefines.h"
#include "OscParameterDefines.h"

OscCenterPanel::OscCenterPanel(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer)
: OscBasePanel(inProcessor), mTimerSlider(sliderTimer), opacity(0.0f), showCredits(false)
{
    timerVal =  mProcessor->parameters.getRawParameterValue(OSCParameterID[oParameter_Timer]);
    leftChannel = mProcessor->parameters.getRawParameterValue(OSCParameterID[oParameter_LeftChannel]);
    rightChannel = mProcessor->parameters.getRawParameterValue(OSCParameterID[oParameter_RightChannel]);
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    startTimer(*timerVal);
    timerSliderVal = *timerVal;
}

OscCenterPanel::~OscCenterPanel()
{
    
}

void OscCenterPanel::paint(Graphics& g)
{
    
    paintWaveform(g);
    if(showCredits)
    {
        paintCredits(g);
    }
    
    
}



void OscCenterPanel::timerCallback()
{
    repaint();
}

void OscCenterPanel::setTimer(double newTimerValue)
{
    timerSliderVal = newTimerValue;
    startTimer(newTimerValue);
}

void OscCenterPanel::setCredits(bool showVal)
{
    if(!showVal)
    {
        opacity = 0.0f;
        startTimer(timerSliderVal);
    }
    else {
        startTimer(20.0f);
    }
    showCredits = showVal;

}

void OscCenterPanel::paintCredits(Graphics& g)
{
    
    if(opacity <= 1.0f )
    {
        g.setColour(OSCColour_3.withAlpha(opacity));
        opacity += 0.05;
    }
    else {
        g.setColour(OSCColour_3);
    }
    g.fillAll();
    if(opacity >=  1.0f)
    {
        g.setColour(Colours::white);
        g.drawFittedText("Audio Plugin by Sebastian Badon \n sebastianmbadon@gmail.com", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
    }
    
}

void OscCenterPanel::paintWaveform(Graphics& g)
{
    g.setColour(OSCColour_2);
     g.fillAll();
    
     float* waveformLeft = mProcessor->getWaveformLeft();
     float* waveformRight = mProcessor->getWaveformRight();
     const float increment = getWidth()/CIRCULAR_BUFFER_LENGTH;
     float width = 0;
     Path path1;
     Path path2;
     PathStrokeType stroke (2.0f);
     Boolean startNewLine = true;
     for(int i = 0; i<CIRCULAR_BUFFER_LENGTH;i++)
     {
         float height1 = jmap(waveformLeft[i], -1.0f, 1.0f,(float)getHeight(),  0.0f);
         float height2 = jmap(waveformRight[i], -1.0f, 1.0f,(float)getHeight(),  0.0f);
         if(startNewLine && *leftChannel && *rightChannel)
         {
             path1.startNewSubPath (juce::Point<float> (width, height1));
             path2.startNewSubPath (juce::Point<float> (width, height2));
             startNewLine = false;
         }
         else if(*leftChannel && *rightChannel){
             path1.lineTo (juce::Point<float> (width, height1));
             path2.lineTo (juce::Point<float> (width, height2));
             path1.closeSubPath();
             path2.closeSubPath();
             path1.startNewSubPath (juce::Point<float> (width, height1));
             path2.startNewSubPath (juce::Point<float> (width, height2));
         }
         else if(*leftChannel)
         {
             path1.lineTo (juce::Point<float> (width, height1));
             path1.closeSubPath();
             path1.startNewSubPath (juce::Point<float> (width, height1));
         }
         else if(*rightChannel)
         {
             path2.lineTo (juce::Point<float> (width, height1));
             path2.closeSubPath();
             path2.startNewSubPath (juce::Point<float> (width, height1));
         }
         
         width += increment;
         
     }
     g.setColour (OSCStroke_Colour2);
     g.strokePath (path1, stroke, AffineTransform());
     g.setColour (OSCStroke_Colour1);
     g.strokePath  (path2, stroke, AffineTransform());
}
