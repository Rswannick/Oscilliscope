
/*
  ==============================================================================

    Background.cpp
    Created: 10 Sep 2022 7:16:16pm
    Author:  IK Multimedia

  ==============================================================================
*/

#include "OScopeComponent.h"

OScopeComponent::OScopeComponent(OscilliscopeAudioProcessor& p): audioProcessor (p), scopeComponent (audioProcessor.getAudioBufferQueue())
{
    
    addAndMakeVisible(scopeComponent);
    

}

OScopeComponent::~OScopeComponent()
{

}

void OScopeComponent::paint (juce::Graphics& g)
{
        
}

void OScopeComponent::resized()
{
    auto bounds = getLocalBounds();
    scopeComponent.setBounds(bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight());

}

