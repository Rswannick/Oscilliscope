/*
  ==============================================================================

    Global.cpp
    Created: 10 Sep 2022 7:13:26pm
    Author:  Ryan Swannick

  ==============================================================================
*/

#include "Global.h"

GlobalComponent::GlobalComponent()
{
    
    addAndMakeVisible(mMonoStereo);
    setSlider(mGainSlider);
    setSlider(mRotationSlider);
    setSlider(mThicknessSlider);
    mMonoStereo.setLookAndFeel(&lMonoStereo);
}

GlobalComponent::~GlobalComponent()
{
    
    mMonoStereo.setLookAndFeel(nullptr);
    mGainSlider.setLookAndFeel(nullptr);
    mRotationSlider.setLookAndFeel(nullptr);
    mThicknessSlider.setLookAndFeel(nullptr);
}

void GlobalComponent::paint (juce::Graphics& g)
{

}

void GlobalComponent::resized()
{
    //Set Local Bounds
    auto bounds = getLocalBounds();
    //Button Variables
    float buttonX = 0;
    float buttonY = bounds.getHeight() * .085;
    float buttonW = bounds.getWidth() * .0625;
    float buttonH = bounds.getHeight() * .70;
    //Slider Variables
    float sliderX = getWidth() * .325;
    float sliderY = 0;
    float sliderW = bounds.getWidth() * .04;
    float sliderH = bounds.getHeight() * .80;
    //Set Component Bounds in order from left to right
    mMonoStereo.setBounds(buttonX, buttonY, buttonW, buttonH);
    mGainSlider.setBounds(sliderX, sliderY, sliderW, sliderH);
    mRotationSlider.setBounds(mGainSlider.getRight() * 1.345, sliderY, sliderW, sliderH);
    mThicknessSlider.setBounds(mRotationSlider.getRight() * 1.34, sliderY, sliderW, sliderH);

}

void GlobalComponent::setSlider (juce::Slider& slider)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 50, 25);
    
    slider.setLookAndFeel(&lThickness);
    
    addAndMakeVisible (slider);
    
    mThicknessSlider.setValue(3.f);
    mGainSlider.setValue(0.f);
    mRotationSlider.setValue(0.0);

    mThicknessSlider.setRange(1.f, 5.f, .1f);
    mGainSlider.setRange(-24.f, 24.f, 0.1f);
    mRotationSlider.setRange(0.0, 3.14);
    
    mThicknessSlider.setDoubleClickReturnValue(true, 3.f);
    mGainSlider.setDoubleClickReturnValue(true, 0.f);
    mRotationSlider.setDoubleClickReturnValue(true, 0.f);
}


