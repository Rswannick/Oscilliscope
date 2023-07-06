/*
  ==============================================================================

    ScopeComponent.h
    Created: 10 Sep 2022 8:37:38pm
    Author:  IK Multimedia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../PluginProcessor.h"

template <typename SampleType>

class ScopeComponent  : public juce::Component,
                        private juce::Timer
{
    
public:
    using Queue = AudioBufferQueue<SampleType>;

    //==============================================================================
    ScopeComponent (Queue& queueToUse)
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
        
        //Background
        g.fillAll (juce::Colours::black);
    
        //Center Lines
        g.setColour(juce::Colours::darkgrey);
        g.drawLine(area.getWidth()/2, 0, area.getWidth()/2, area.getBottom());
        g.drawLine(0, area.getHeight()/2, area.getRight(), area.getHeight()/2);
        
        juce::Array<float> freqs
        {
            10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
            200, 500, 1000,
            2000, 5000, 10000,
            20000, 50000, 100000
        };
        
        auto renderArea = getLocalBounds();
        auto left = renderArea.getX();
        auto right = renderArea.getRight();
        auto top = renderArea.getY();
        auto bottom = renderArea.getBottom();
        
        g.setColour(juce::Colours::dimgrey);
        juce::Array<float> xs;
        
        for( auto x : xs )
        {
            g.drawVerticalLine(x, top, bottom);
        }
        
        juce::Array<float> gain
        {
            -12, -9, -6, -3,  0, 3, 6, 9, 12
        };
        
        for (auto gDb : gain )
        {
            auto y = juce::jmap(gDb, -12.f, 12.f, float(bottom), float(top));
            auto x = juce::jmap(gDb, -12.f, 12.f, float(left), float(right));
            g.setColour(gDb == 0.f ? juce::Colours::darkgrey : juce::Colours::darkgrey);
            g.drawHorizontalLine(y, left, right);
            g.drawVerticalLine(x, top, bottom);
        }
        
        // Oscilloscope
        g.setColour (juce::Colours::yellowgreen);
        auto scopeRect = juce::Rectangle<SampleType> { SampleType (0), SampleType (0), w, h / 2 };
        plot (sampleData.data(), sampleData.size(), g, scopeRect, SampleType (1), h / 4);
        
        //Overlay
        g.setColour(juce::Colours::grey);

        juce::Rectangle<int> overlay;
        overlay.setBounds(0, getHeight() * .10, getWidth(), getHeight() * .10);
        g.fillRect(overlay);
        
        juce::String rmsStringLong = std::to_string(rmsValue);
        juce::String rmsStringShort = rmsStringLong.substring(0, 6);
        g.setFont(overlay.getHeight() * .50);
        g.setColour(juce::Colours::white);
        g.drawFittedText("RMS: " + rmsStringShort + " db",overlay.getWidth() * .01, overlay.getY(), overlay.getWidth(), overlay.getHeight(), juce::Justification::left, 1);
        g.drawFittedText("PEAK: " + rmsStringShort + " db", overlay.getWidth() * .35, overlay.getY(), overlay.getWidth(), overlay.getHeight(), juce::Justification::left, 1);
        
        

    }

    //==============================================================================
    void resized() override {}
    
    float mPhase = { 1.0 };
    float mThick = { 1.0 };
    float mFreq = { 1.0 };
    float mRotation = { 0.0 };
    
    float mVOffset = { 1.0 };
    float mHOffset = { 1.0 };
    float mVolts = { 1.0 };
    float mSeconds = { 1.0 };
    
    float rmsValue = { 0 };
    float peakValue = { 0 };
    

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
        
        float w = rect.getWidth() * mSeconds;
        auto h = rect.getHeight();
        auto right = rect.getRight() * mHOffset;
        auto center = rect.getBottom() * mVOffset;
        auto gain = ((h * scaler) * mVolts) * mPhase;
        
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

        pd.addLineSegment(line1, mThick * 1.10);
        pd.applyTransform(juce::AffineTransform::rotation(mRotation, getWidth() * .50, getHeight() * .50));
        shadow1.drawForPath(g, pd);

        p.addLineSegment(line1, mThick);
        p.applyTransform(juce::AffineTransform::rotation(mRotation, getWidth() * .50, getHeight() * .50));
        g.setColour(juce::Colours::yellowgreen);
            
        g.fillPath(p);
            
        }

    }
};

class OScopeComponent  : public juce::Component
{
public:
    OScopeComponent(OscilliscopeAudioProcessor&);
    ~OScopeComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    OscilliscopeAudioProcessor& audioProcessor;
    ScopeComponent<float> scopeComponent;
    

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OScopeComponent)
};



