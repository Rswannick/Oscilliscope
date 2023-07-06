/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Background/Background.h"
#include "Oscilloscope/OScopeComponent.h"
#include "Oscilloscope/OScopeComponent2.h"
#include "ChannelControls/CH1.h"
#include "ChannelControls/CH2.h"
#include "GlobalControls/Global.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef JUCE_IOS
#define JUCE_IOS 0 // Define a default value if JUCE_IOS is not defined
#endif

//==============================================================================
/**
*/

class Bypasslaf : public juce::LookAndFeel_V4 {
public:
    
    void drawToggleButton    (juce::Graphics & g,
                              juce::ToggleButton & button,
                              bool shouldDrawButtonAsHighlighted,
                              bool shouldDrawButtonAsDown
                              ) override
    {
        
        auto onButton = juce::ImageCache::getFromMemory (BinaryData::POWER_ON_png, BinaryData::POWER_ON_pngSize);
        auto offButton = juce::ImageCache::getFromMemory (BinaryData::POWER_OFF_png, BinaryData::POWER_OFF_pngSize);
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setSize(bounds.getWidth(), bounds.getHeight());

        if (button.getToggleState() == 0) {g.drawImage(onButton, rect); }
        else { g.drawImage(offButton, rect); }
        
    }

};

class Phaselaf : public juce::LookAndFeel_V4 {
public:
    
    void drawToggleButton    (juce::Graphics & g,
                              juce::ToggleButton & button,
                              bool shouldDrawButtonAsHighlighted,
                              bool shouldDrawButtonAsDown
                              ) override
    {
        
        auto onButton = juce::ImageCache::getFromMemory (BinaryData::PHASE_ON_png, BinaryData::PHASE_ON_pngSize);
        auto offButton = juce::ImageCache::getFromMemory (BinaryData::PHASE_OFF_png, BinaryData::PHASE_OFF_pngSize);
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setSize(bounds.getWidth(), bounds.getHeight());

        if (button.getToggleState() == 0) {g.drawImage(onButton, rect); }
        else { g.drawImage(offButton, rect); }
    }

};

class OscilliscopeAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener, juce::Button::Listener, juce::Timer
{
public:
    OscilliscopeAudioProcessorEditor (OscilliscopeAudioProcessor&);
    ~OscilliscopeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* slider) override;
    void buttonStateChanged(juce::Button *button) override;
    void buttonClicked(juce::Button *button) override;
    
    void timerCallback() override;
    
    float sizeX { 800 };
    float sizeY { (800  / (6.0/3.0) ) };

private:
    OscilliscopeAudioProcessor& audioProcessor;
    
    Bypasslaf lBypass;
    Phaselaf lPhase;
    
    BackgroundComponent cBackground;
    GlobalComponent cGlobal;
    CH1Component cCH1;
    CH2Component cCH2;
    OScopeComponent cOscope;
    OScopeComponent2 cOscope2;
    
    juce::ToggleButton
    mBypass,
    mPolarity;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscilliscopeAudioProcessorEditor)
};
