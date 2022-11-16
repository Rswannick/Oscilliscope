/*
  ==============================================================================

    Global.cpp
    Created: 10 Sep 2022 7:13:26pm
    Author:  IK Multimedia

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
    mGainSlider.setLookAndFeel(&lGain);
    mRotationSlider.setLookAndFeel(&lRotation);
    mThicknessSlider.setLookAndFeel(&lThickness);
    
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
    float buttonY = bounds.getHeight() * .075;
    float buttonW = bounds.getWidth() * .065;
    float buttonH = bounds.getHeight() * .90;
    //Slider Variables
    float sliderX = getWidth() * .325;
    float sliderY = 0;
    float sliderW = bounds.getWidth() * .05;
    float sliderH = bounds.getHeight() * .90;
    //Set Component Bounds in order from left to right
    mMonoStereo.setBounds(buttonX, buttonY, buttonW, buttonH);
    mGainSlider.setBounds(sliderX, sliderY, sliderW, sliderH);
    mRotationSlider.setBounds(mGainSlider.getRight() * 1.30, sliderY, sliderW, sliderH);
    mThicknessSlider.setBounds(mRotationSlider.getRight() * 1.32, sliderY, sliderW, sliderH);

}

void GlobalComponent::setSlider (juce::Slider& slider)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 50, 25);
    addAndMakeVisible (slider);
    
    mThicknessSlider.setValue(3.f);
    mGainSlider.setValue(0.f);
    mRotationSlider.setValue(0.0);

    mThicknessSlider.setRange(1.f, 5.f, .1f);
    mGainSlider.setRange(-24.f, 24.f, 1.f);
    mRotationSlider.setRange(0.0, 180.0);
    
    mThicknessSlider.setDoubleClickReturnValue(true, 3.f);
    mGainSlider.setDoubleClickReturnValue(true, 0.f);
    mRotationSlider.setDoubleClickReturnValue(true, 0.f);
    

}


