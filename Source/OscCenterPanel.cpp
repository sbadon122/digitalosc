/*
  ==============================================================================

    OscCenterPanel.cpp
    Created: 25 Jun 2020 7:22:06pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "OscCenterPanel.h"
#include "OscInterfaceDefines.h"

OscCenterPanel::OscCenterPanel(OscJucePluginAudioProcessor* inProcessor, std::shared_ptr<Slider> sliderTimer)
: OscBasePanel(inProcessor), mTimerSlider(sliderTimer)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    auto params = mProcessor->getParameters();
    AudioParameterInt* timerParameter = (AudioParameterInt*) params.getUnchecked(0);
    startTimer(timerParameter->get());
}

OscCenterPanel::~OscCenterPanel()
{
    
}

void OscCenterPanel::paint(Graphics& g)
{
     g.setColour(OSCColour_2);
     g.fillAll();
     float* waveformLeft = mProcessor->getWaveformLeft();
     float* waveformRight = mProcessor->getWaveformRight();
     const float increment = CIRCULAR_BUFFER_LENGTH/getWidth();
     double width = 0;
     Path path1;
     Path path2;
     PathStrokeType stroke (2.0f);
     
     Boolean startNewLine = true;
     for(int i = 0; i<CIRCULAR_BUFFER_LENGTH;i++)
     {
         float height1 = jmap(waveformLeft[i], -1.0f, 1.0f,(float)getHeight(),  0.0f);
         float height2 = jmap(waveformRight[i], -1.0f, 1.0f,(float)getHeight(),  0.0f);
         if(startNewLine)
         {
             path1.startNewSubPath (Point<float> (width, height1));
             path2.startNewSubPath (Point<float> (width, height2));
             startNewLine = false;
         }
         else {
             path1.lineTo (Point<float> (width, height1));
             path2.lineTo (Point<float> (width, height2));
             path1.closeSubPath();
             path2.closeSubPath();
             path1.startNewSubPath (Point<float> (width, height1));
             path2.startNewSubPath (Point<float> (width, height2));
         }
         width += increment;
         
     }
     g.setColour (OSCStroke_Colour2);
     g.strokePath (path1, stroke, AffineTransform());
     g.setColour (OSCStroke_Colour1);
     g.strokePath (path2, stroke, AffineTransform());
    
}

void OscCenterPanel::timerCallback()
{
    repaint();
}

void OscCenterPanel::setTimer(double newTimerValue)
{
    startTimer(newTimerValue);
}
