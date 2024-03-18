/*
  ==============================================================================

    InfoWindow.h
    Created: 16 Jan 2022 3:53:43pm
    Author:  Ryan Swannick
==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "LAF.h"

//==============================================================================
/*
*/
class SettingsComponent  : public juce::Component
{
public:
    SettingsComponent();
    ~SettingsComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void closeWindow();
    void openLogo();
    void openAudioDevice();
    
    juce::String oldDeviceName;
    
    juce::AudioDeviceManager otherDeviceManager;
    std::unique_ptr<juce::AudioDeviceSelectorComponent> audioSettings;

    LAFComponent cLAF;
private:
    juce::ImageButton logo;
    

    

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsComponent)
};







