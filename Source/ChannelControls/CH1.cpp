/*
  ==============================================================================

    CH1.cpp
    Created: 10 Sep 2022 7:13:43pm
    Author:  IK Multimedia

  ==============================================================================
*/

#include "CH1.h"

CH1Component::CH1Component()
{
    setSlider(mHOffsetSlider);
    setSlider(mVOffsetSlider);
    setSlider(mVoltsSlider);
    setSlider(mSecondsSlider);
    
    mVOffsetSlider.setLookAndFeel(&lCH1VOffset);
    mHOffsetSlider.setLookAndFeel(&lCH1HOffset);
    mVoltsSlider.setLookAndFeel(&lCH1Volts);
    mSecondsSlider.setLookAndFeel(&lCH1Seconds);

}

CH1Component::~CH1Component()
{

    mVoltsSlider.setLookAndFeel(nullptr);
    mVOffsetSlider.setLookAndFeel(nullptr);
    mSecondsSlider.setLookAndFeel(nullptr);
    mHOffsetSlider.setLookAndFeel(nullptr);

}

void CH1Component::paint (juce::Graphics& g)
{

    
}

void CH1Component::resized()
{

    auto bounds = getLocalBounds();
    
    float sliderX = 0;
    float sliderY = 0;
    float sliderW = bounds.getWidth() * .25;
    float sliderH = bounds.getHeight();
    
    mVOffsetSlider.setBounds(sliderX, sliderY, sliderW, sliderH);
    mVoltsSlider.setBounds(mVOffsetSlider.getRight(), sliderY, sliderW, sliderH);
    mHOffsetSlider.setBounds(mVoltsSlider.getRight(), sliderY, sliderW, sliderH);
    mSecondsSlider.setBounds(mHOffsetSlider.getRight(), sliderY , sliderW, sliderH);

    
}

void CH1Component::setSlider (juce::Slider& slider)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 50, 25);
    slider.setDoubleClickReturnValue(true, 1.f);
    slider.setRange(0.0f, 2.f, .1f);
    slider.setValue(1.f);
    addAndMakeVisible (slider);
    
}


