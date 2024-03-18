/*
  ==============================================================================

    OScopeComponent2.h
    Created: 18 Sep 2022 5:04:01pm
    Author:  Ryan Swannick

  ==============================================================================
*/


#pragma once
#include <JuceHeader.h>
#include "../PluginProcessor.h"

#ifndef JUCE_IOS
#define JUCE_IOS 0 // Define a default value if JUCE_IOS is not defined
#endif

template <typename SampleType>

class ScopeComponent2  : public juce::Component,
                        private juce::Timer
{
    
public:
    using Queue = AudioBufferQueue<SampleType>;

    //==============================================================================
    ScopeComponent2 (Queue& queueToUse)
        : audioBufferQueue (queueToUse)
    {
        sampleData.fill (SampleType (0));
        setFramesPerSecond (120);
    }

    //==============================================================================
    void setFramesPerSecond (int framesPerSecond)
    {
        jassert (framesPerSecond > 0 && framesPerSecond < 1000);
        startTimerHz (framesPerSecond);
    }

    //==============================================================================
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
        auto h = (SampleType) area.getHeight();
        auto w = (SampleType) area.getWidth();
        
        // Oscilloscope
        g.setColour (juce::Colours::yellowgreen);
        auto scopeRect = juce::Rectangle<SampleType> { SampleType (0), SampleType (0), w, h / 2 };
        plot (sampleData.data(), sampleData.size(), g, scopeRect, SampleType (1), h / 4);

    }

    //==============================================================================
    void resized() override {}
    
    float mPhase2 = { 1.0 };
    float mThick2 = { 1.0 };
    float mFreq2 = { 1.0 };
    float mRotation2 = { 0.0 };
    
    float mVOffset2 = { 1.0 };
    float mHOffset2 = { 1.0 };
    float mVolts2 = { 1.0 };
    float mSeconds2 = { 1.0 };
    
    float rmsValue2 = { 0 };
    float peakValue2 = { 0 };
    

private:
    
    //==============================================================================
    Queue& audioBufferQueue;
    std::array<SampleType, Queue::bufferSize> sampleData;

    juce::dsp::FFT fft { Queue::order };
    using WindowFun = juce::dsp::WindowingFunction<SampleType>;
    WindowFun windowFun { (size_t) fft.getSize(), WindowFun::hann };
    std::array<SampleType, 2 * Queue::bufferSize> spectrumData;

    //==============================================================================
    void timerCallback() override
    {
        audioBufferQueue.pop (sampleData.data());
        juce::FloatVectorOperations::copy (spectrumData.data(), sampleData.data(), (int) sampleData.size());

        auto fftSize = (size_t) fft.getSize();

        jassert (spectrumData.size() == 2 * fftSize);
        windowFun.multiplyWithWindowingTable (spectrumData.data(), fftSize);
        fft.performFrequencyOnlyForwardTransform (spectrumData.data());

        static constexpr auto mindB = SampleType (-160);
        static constexpr auto maxdB = SampleType (0);

        for (auto& s : spectrumData)
            s = juce::jmap (juce::jlimit (mindB, maxdB, juce::Decibels::gainToDecibels (s) - juce::Decibels::gainToDecibels (SampleType (fftSize))), mindB, maxdB, SampleType (0), SampleType (1));

        repaint();
    }

    //==============================================================================
    void plot (const SampleType* data,
                      size_t numSamples,
                      juce::Graphics& g,
                      juce::Rectangle<SampleType> rect,
                      SampleType scaler = SampleType (1),
                      SampleType offset = SampleType (0))
    {
        
        float w = rect.getWidth() * mSeconds2;
        auto h = rect.getHeight();
        auto right = rect.getRight() * mHOffset2;
        auto center = rect.getBottom() * mVOffset2;
        auto gain = ((h * scaler) * mVolts2) * mPhase2;
        
        for (size_t i = 1; i < numSamples; ++i)
        {
        auto startX = juce::jmap (SampleType (i - 1), SampleType (0), SampleType (numSamples - 1), SampleType (right - w), SampleType (right));
        auto startY =  center - gain * data[i - 1];
        auto endX = juce::jmap (SampleType (i), SampleType (0), SampleType (numSamples - 1), SampleType (right - w), SampleType (right));
        auto endY = center - gain * data[i];
            
        juce::Path p, pd;
            
        juce::DropShadow shadow1;
        shadow1.colour = juce::Colours::white;
            
        juce::Line<float> line1;
        line1.setStart(startX, startY);
        line1.setEnd(endX, endY);

        pd.addLineSegment(line1, mThick2 * 1.10);
        pd.applyTransform(juce::AffineTransform::rotation(mRotation2, getWidth() * .50, getHeight() * .50));
        
        if (JUCE_IOS)
        {
            
        }
        else
        {
            shadow1.drawForPath(g, pd);
        }
        
        p.addLineSegment(line1, mThick2);
        p.applyTransform(juce::AffineTransform::rotation(mRotation2, getWidth() * .50, getHeight() * .50));
        g.setColour(juce::Colours::yellow);
            
        g.fillPath(p);
            
        }

    }
};

class OScopeComponent2  : public juce::Component
{
public:
    OScopeComponent2(OscilliscopeAudioProcessor&);
    ~OScopeComponent2() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    OscilliscopeAudioProcessor& audioProcessor;
    ScopeComponent2<float> scopeComponent2;
    

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OScopeComponent2)
};



