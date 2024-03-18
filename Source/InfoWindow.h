/*
  ==============================================================================

    InfoWindow.h
    Created: 16 Jan 2022 3:53:43pm
    Author:  Ryan Swannick
==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#include "AMSettings.h"
#include "juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"

//==============================================================================
/*
*/
class InfoComponent  : public juce::Component
{
public:
    InfoComponent();
    ~InfoComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void closeWindow();
    
    juce::TextButton close {" X "};
    
    SettingsComponent cSettings;

    std::unique_ptr<juce::XmlElement> xmlDevices;
    juce::String deviceEmpty; 
    
private:
    juce::Viewport settingsPort;
    juce::ImageComponent logo;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InfoComponent)
};







