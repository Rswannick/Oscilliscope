/*
  ==============================================================================

    CH1.h
    Created: 10 Sep 2022 7:13:43pm
    Author: Ryan Swannick
  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#include "../LAF.h"

class CH1Component  : public juce::Component
{
public:
    CH1Component();
    ~CH1Component() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Slider

    mHOffsetSlider,
    mVOffsetSlider,
    mVoltsSlider,
    mSecondsSlider;
    
private:
    LAFComponent cLAF;
    
    void setSlider (juce::Slider& slider);
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CH1Component)
};



