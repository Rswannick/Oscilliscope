/*
  ==============================================================================

    InfoWindow.cpp
    Created: 16 Jan 2022 3:53:43pm
    Author:  Ryan Swannick
==============================================================================
*/

#include "InfoWindow.h"

InfoComponent::InfoComponent()
{
    
    auto bounds = getLocalBounds();
    close.setLookAndFeel(&cSettings.cLAF.lWindow);
    addAndMakeVisible(settingsPort);
    addAndMakeVisible(cSettings);
    settingsPort.setViewedComponent(&cSettings, false);
    settingsPort.setScrollBarsShown(true, false);
    settingsPort.setSize(bounds.getWidth(),bounds.getHeight());
    cSettings.setSize(bounds.getWidth(),bounds.getHeight());
    
    addAndMakeVisible(close);
    close.onClick = [this] { closeWindow(); };
            
}

InfoComponent::~InfoComponent()
{
    close.setLookAndFeel(nullptr);
}

void InfoComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds();
    
    g.setColour(juce::Colours::black);
    g.fillAll();
    
    g.setColour(juce::Colours::white);
    g.drawRect(bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight());
        

}

void InfoComponent::resized()
{
    auto bounds = getLocalBounds();
    
    auto screenSize = juce::Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
    float width = screenSize.getWidth();
    float height = screenSize.getHeight();
    
    settingsPort.setBounds(0, bounds.getHeight() * .01, bounds.getWidth() * .999, bounds.getHeight() * .95);
    cSettings.setBounds(0, 0, bounds.getWidth(), height * .75);
    close.setBounds(0, 0, 25, 25);

    
}

void InfoComponent::closeWindow()
{
    setVisible(false);
    
    if (juce::JUCEApplication::isStandaloneApp())
    {
        auto pluginHolder = juce::StandalonePluginHolder::getInstance();
        
        pluginHolder->deviceManager.setAudioDeviceSetup(cSettings.otherDeviceManager.getAudioDeviceSetup(), true);
        
        xmlDevices = pluginHolder->deviceManager.createStateXml();
        
        if (xmlDevices.get() != nullptr)
        {
            deviceEmpty = xmlDevices->toString();
        }
        
    }
}
