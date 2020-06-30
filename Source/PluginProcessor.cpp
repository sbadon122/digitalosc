/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "OscInterfaceDefines.h"
#include "OscParameterDefines.h"
//==============================================================================
OscJucePluginAudioProcessor::OscJucePluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
parameters(*this, nullptr, juce::Identifier("OscilloDOPE"), createParameterLayout()),
circularBufferReadHead(0)
{
    waveformLeft = new float[CIRCULAR_BUFFER_LENGTH];
    waveformRight = new float[CIRCULAR_BUFFER_LENGTH];
    timerParameter = new AudioParameterFloat(OSCParameterID[oParameter_Timer],
                                                        OSCParameterLabel[oParameter_Timer],
                                                        OSCParameterMinValue[oParameter_Timer],
                                                        OSCParameterMaxValue[oParameter_Timer],
                                                        OSCParameterDefaultValue[oParameter_Timer]);
    addParameter(timerParameter);
}

OscJucePluginAudioProcessor::~OscJucePluginAudioProcessor()
{
    delete[] waveformLeft;
    delete[] waveformRight;
    delete timerParameter;
}

//==============================================================================
const String OscJucePluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OscJucePluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OscJucePluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OscJucePluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OscJucePluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OscJucePluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OscJucePluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OscJucePluginAudioProcessor::setCurrentProgram (int index)
{
}

const String OscJucePluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void OscJucePluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void OscJucePluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    circularBufferReadHead = 0;
    zeromem(waveformLeft, sizeof(float)*CIRCULAR_BUFFER_LENGTH);
    zeromem(waveformRight, sizeof(float)*CIRCULAR_BUFFER_LENGTH);
}

void OscJucePluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OscJucePluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OscJucePluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
    
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

   
        std::atomic<float>* freezeStateVal =  parameters.getRawParameterValue(OSCParameterID[oParameter_Freeze]);
        auto* leftChannel = buffer.getReadPointer(0);
        auto* rightChannel = buffer.getReadPointer(1);
        auto ratio = buffer.getNumSamples()/400.0f;
        for(int i = 0; i<buffer.getNumSamples();i+=ratio)
        {
            
            if(*freezeStateVal != 1.f){
                waveformLeft[circularBufferReadHead] = leftChannel[i];
                waveformRight[circularBufferReadHead] = rightChannel[i];
                circularBufferReadHead++;
                if(circularBufferReadHead > CIRCULAR_BUFFER_LENGTH)
                {
                    circularBufferReadHead -= CIRCULAR_BUFFER_LENGTH;
                }
            }
        }
    
}

//==============================================================================
bool OscJucePluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* OscJucePluginAudioProcessor::createEditor()
{
    return new OscJucePluginAudioProcessorEditor (*this);
}

//==============================================================================
void OscJucePluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OscJucePluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

float* OscJucePluginAudioProcessor::getWaveformLeft()
{
    return waveformLeft;
}

float* OscJucePluginAudioProcessor::getWaveformRight()
{
    return waveformRight;
}

AudioProcessorValueTreeState::ParameterLayout OscJucePluginAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for(int i = 0; i< oParameter_TotalNumParameters;i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(OSCParameterID[i],
                                          OSCParameterLabel[i],
                                          NormalisableRange<float> (OSCParameterMinValue[i], OSCParameterMaxValue[i]),
                                          OSCParameterDefaultValue[i]
                                          ));
    }
    
    return { params.begin(), params.end()};
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OscJucePluginAudioProcessor();
}
