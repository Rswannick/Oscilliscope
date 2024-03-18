/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Background/Background.h"
#include "Oscilloscope/OScopeComponent.h"
#include "Oscilloscope/OScopeComponent2.h"
#include "ChannelControls/CH1.h"
#include "ChannelControls/CH2.h"
#include "GlobalControls/Global.h"
#include "LAF.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef JUCE_IOS
#define JUCE_IOS 0 // Define a default value if JUCE_IOS is not defined
#endif

//==============================================================================
/**
*/

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

    void addComponents();
    void addListeners();
    void addLookAndFeel();
    void setGUISize();
    
    juce::Rectangle<int> setiOSBounds(juce::Rectangle<int> iOSBounds);
    
    float sizeX { 800 };
    float sizeY { (800  / (6.0/3.0) ) };
    
    //Open Settings Menu
    void openSettings();

private:
    OscilliscopeAudioProcessor& audioProcessor;
    
    //LookAndFeel
    LAFComponent cLAF;
    
    //Settings menu
    juce::ImageButton mSettings;
    
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
