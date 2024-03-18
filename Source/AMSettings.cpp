/*
  ==============================================================================

    InfoWindow.cpp
    Created: 16 Jan 2022 3:53:43pm
    Author:  Ryan Swannick 
  ==============================================================================
*/

#include "AMSettings.h"

SettingsComponent::SettingsComponent()
{
    
    openAudioDevice();
    
    auto logoBtn = juce::ImageCache::getFromMemory (BinaryData::Logo_png, BinaryData::Logo_pngSize);

    logo.setImages(false, true, true, logoBtn, 1, juce::Colours::white, logoBtn, 0, juce::Colours::grey, logoBtn, 1, juce::Colours::yellow);
    addAndMakeVisible(logo);
    
    logo.onClick = [this] { openLogo(); };

}

SettingsComponent::~SettingsComponent()
{
    
    if (juce::JUCEApplication::isStandaloneApp())
    {
        otherDeviceManager.closeAudioDevice();
        audioSettings.reset();
    }

}

void SettingsComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawText("AUDIO MIDI SETUP", bounds.getWidth() * .10, bounds.getHeight() * .01, bounds.getWidth() * .75, bounds.getHeight() * .10, juce::Justification::centred);
}

void SettingsComponent::resized()
{
    auto bounds = getLocalBounds();
    
    if (juce::JUCEApplication::isStandaloneApp())
    {
        audioSettings->setBounds (0, getHeight() * .05, bounds.getWidth() * .80, bounds.getHeight() * .80);
        logo.setBounds(bounds.getWidth() * .25, audioSettings->getBottom() * .90, bounds.getWidth() * .50, bounds.getHeight() * .25);
        audioSettings->setLookAndFeel(&cLAF.newLAF);
    }

}

void SettingsComponent::closeWindow()
{
    
//    audioSettings->deviceManager.restartLastAudioDevice();
    
    setVisible(false);
    juce::LookAndFeel::setDefaultLookAndFeel (nullptr);
}

void SettingsComponent::openLogo()
{
    juce::URL link("http://bit.ly/3v1Q3Hd");
    link.launchInDefaultBrowser();

}

void SettingsComponent::openAudioDevice()
{
    if (juce::JUCEApplication::isStandaloneApp())
    {

        otherDeviceManager.initialise(2, 2, nullptr, true);
        juce::LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName ("Avenir Next");
        juce::LookAndFeel::getDefaultLookAndFeel().setDefaultLookAndFeel(&cLAF.newLAF);
        audioSettings.reset(new juce::AudioDeviceSelectorComponent(otherDeviceManager, 0, 2, 0, 2, false, false, false, false) );
        addAndMakeVisible(audioSettings.get());
        
        juce::File docs = juce::File::getSpecialLocation(juce::File::userDocumentsDirectory);
        juce::String path = docs.getFullPathName();
        juce::String plateverb = "/OSC Audio/sumFX/audiosettings.recall";
        juce::String state = path + plateverb;
        
        auto save = state;
        juce::File propertiesFile (save);
        std::unique_ptr<juce::XmlElement> xml (parseXML(propertiesFile));
        
        const juce::XmlElement* xml2 (xml.get());
        
        if (save.isNotEmpty())
        {
            oldDeviceName = save.toStdString();
            otherDeviceManager.initialise(1, 2, xml2, true);
        }
        
    }
}
