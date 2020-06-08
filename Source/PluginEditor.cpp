/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OscJucePluginAudioProcessorEditor::OscJucePluginAudioProcessorEditor (OscJucePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    startTimer(10);
}

OscJucePluginAudioProcessorEditor::~OscJucePluginAudioProcessorEditor()
{
}

//==============================================================================
void OscJucePluginAudioProcessorEditor::paint (Graphics& g)
{
    
    g.setColour(Colours::darkgrey);
    g.fillAll();
    float* waveform = processor.getWaveform();
    const float increment = CIRCULAR_BUFFER_LENGTH/getWidth();
    double width = 0;
    Path path;
    PathStrokeType stroke (2.0f);
    g.setColour (Colours::purple.withAlpha (getAlpha()));
    Boolean startNewLine = true;
    for(int i = 0; i<CIRCULAR_BUFFER_LENGTH;i++)
    {
        float height = jmap(waveform[i], -1.0f, 1.0f,(float)getHeight(),  0.0f);
        if(startNewLine)
        {
            path.startNewSubPath (Point<float> (width, height));
            startNewLine = false;
        }
        else {
            path.lineTo (Point<float> (width, height));
            path.closeSubPath();
            path.startNewSubPath (Point<float> (width, height));
            //startNewLine =true;
        }
        width += increment;
        
    }
   
    g.strokePath (path, stroke, AffineTransform());
    
}

void OscJucePluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void OscJucePluginAudioProcessorEditor::timerCallback()
{
    repaint();
}
