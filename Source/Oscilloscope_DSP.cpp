/*
  ==============================================================================

    Oscilloscope_DSP.cpp
    Created: 10 Dec 2023 3:30:19pm
    Author:   Ryan Swannick

  ==============================================================================
*/

#include "Oscilloscope_DSP.h"

OscilloscopeDSP::OscilloscopeDSP()
{
    
}
OscilloscopeDSP::~OscilloscopeDSP()
{
    
}

void OscilloscopeDSP::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.numChannels = 1;
    spec.maximumBlockSize = samplesPerBlock;
    
    gainL.reset();
    gainR.reset();
    
    gainL.prepare(spec);
    gainR.prepare(spec);
}
void OscilloscopeDSP::processBlock (juce::AudioBuffer<float>& buffer)
{
    
    juce::dsp::AudioBlock<float> block1 (buffer);

    auto leftBlock = block1.getSingleChannelBlock(0);
    auto rightBlock = block1.getSingleChannelBlock(1);

    juce::dsp::ProcessContextReplacing<float> leftContext (leftBlock);
    juce::dsp::ProcessContextReplacing<float> rightContext (rightBlock);
    
    gainR.setGainDecibels(gainValue);
    gainL.setGainDecibels(gainValue);
    
    if (mBypass == 0)
    {
        if (buffer.getNumChannels() > 0)
        {
            double rmsV = juce::Decibels::gainToDecibels(buffer.getRMSLevel(0, 0, buffer.getNumSamples()));
            double peakV = juce::Decibels::gainToDecibels(buffer.getMagnitude(0, 0, buffer.getNumSamples()));
            rmsValue = rmsV;
            peakValue = peakV;
            gainL.process(leftContext);
            scopeDataCollector.process (buffer.getReadPointer (0), (size_t) buffer.getNumSamples());
        }
        if (buffer.getNumChannels() > 1)
        {
            double rmsV2 = juce::Decibels::gainToDecibels(buffer.getRMSLevel(1, 0, buffer.getNumSamples()));
            double peakV2 = juce::Decibels::gainToDecibels(buffer.getMagnitude(1, 0, buffer.getNumSamples()));
            rmsValue2 = rmsV2;
            peakValue2 = peakV2;
            gainR.process(rightContext);
            scopeDataCollector2.process (buffer.getReadPointer (1), (size_t) buffer.getNumSamples());
        }
    }
}
