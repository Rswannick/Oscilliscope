/*
  ==============================================================================

    OScopeComponent2.cpp
    Created: 18 Sep 2022 5:04:01pm
    Author:  IK Multimedia

  ==============================================================================
*/

#include "OScopeComponent2.h"

OScopeComponent2::OScopeComponent2(OscilliscopeAudioProcessor& p): audioProcessor (p), scopeComponent2 (audioProcessor.getAudioBufferQueue2())
{
    
    addAndMakeVisible(scopeComponent2);
    

}

OScopeComponent2::~OScopeComponent2()
{
    
}

void OScopeComponent2::paint (juce::Graphics& g)
{
        
}

void OScopeComponent2::resized()
{
    auto bounds = getLocalBounds();
    scopeComponent2.setBounds(bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight());

}

