/*
  ==============================================================================

    Global.h
    Created: 10 Sep 2022 7:13:26pm
    Author:  IK Multimedia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class MonoStereolaf : public juce::LookAndFeel_V4 {
public:
    
    void drawToggleButton    (juce::Graphics & g,
                              juce::ToggleButton & button,
                              bool shouldDrawButtonAsHighlighted,
                              bool shouldDrawButtonAsDown
                              ) override
    {
        
        auto onButton = juce::ImageCache::getFromMemory (BinaryData::MONO_ON_png, BinaryData::MONO_ON_pngSize);
        auto offButton = juce::ImageCache::getFromMemory (BinaryData::MONO_OFF_png, BinaryData::MONO_OFF_pngSize);
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setSize(bounds.getWidth(), bounds.getHeight());

        if (button.getToggleState() == 0) {g.drawImage(onButton, rect); }
        else { g.drawImage(offButton, rect); }
        
    }



};

class Gainlaf: public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::Gain_0000_png, BinaryData::Gain_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::Gain_0000_png, BinaryData::Gain_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::Gain_0002_png, BinaryData::Gain_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::Gain_0003_png, BinaryData::Gain_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::Gain_0004_png, BinaryData::Gain_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::Gain_0005_png, BinaryData::Gain_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::Gain_0006_png, BinaryData::Gain_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::Gain_0007_png, BinaryData::Gain_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::Gain_0008_png, BinaryData::Gain_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::Gain_0009_png, BinaryData::Gain_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::Gain_0010_png, BinaryData::Gain_0010_pngSize);

       juce::Array<juce::Image> imageArray
       {
           slider0, slider1, slider2, slider3, slider4, slider5, slider6, slider7, slider8, slider9, slider10
       };

       int mTD {0};
       float sV = slider.getValue();
        float sMin = slider.getMinimum();
        float sMax = slider.getMaximum();

       mTD = juce::jmap (sV, sMin, sMax, 0.f, 10.f);

       if (mTD > 0 && mTD <= 10) {g.drawImage(imageArray.getReference(mTD), sliderRect);}
       else if (mTD > 10) { g.drawImage(imageArray.getReference(10), sliderRect); }
       else{ g.drawImage(imageArray.getReference(1), sliderRect);}
    }
    
private:
};


class Rotationlaf: public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0000_png, BinaryData::Rotation_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0000_png, BinaryData::Rotation_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0002_png, BinaryData::Rotation_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0003_png, BinaryData::Rotation_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0004_png, BinaryData::Rotation_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0005_png, BinaryData::Rotation_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0006_png, BinaryData::Rotation_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0007_png, BinaryData::Rotation_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0008_png, BinaryData::Rotation_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0009_png, BinaryData::Rotation_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::Rotation_0010_png, BinaryData::Rotation_0010_pngSize);

       juce::Array<juce::Image> imageArray
       {
           slider0, slider1, slider2, slider3, slider4, slider5, slider6, slider7, slider8, slider9, slider10
       };

       int mTD {0};
       float sV = slider.getValue();
        float sMin = slider.getMinimum();
        float sMax = slider.getMaximum();

       mTD = juce::jmap (sV, sMin, sMax, 0.f, 10.f);

       if (mTD > 0 && mTD <= 10) {g.drawImage(imageArray.getReference(mTD), sliderRect);}
       else if (mTD > 10) { g.drawImage(imageArray.getReference(10), sliderRect); }
       else{ g.drawImage(imageArray.getReference(1), sliderRect);}
    }
    
private:
};

class Thicknesslaf: public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0000_png, BinaryData::Thickness_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0000_png, BinaryData::Thickness_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0002_png, BinaryData::Thickness_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0003_png, BinaryData::Thickness_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0004_png, BinaryData::Thickness_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0005_png, BinaryData::Thickness_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0006_png, BinaryData::Thickness_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0007_png, BinaryData::Thickness_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0008_png, BinaryData::Thickness_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0009_png, BinaryData::Thickness_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::Thickness_0010_png, BinaryData::Thickness_0010_pngSize);

       juce::Array<juce::Image> imageArray
       {
           slider0, slider1, slider2, slider3, slider4, slider5, slider6, slider7, slider8, slider9, slider10
       };

       int mTD {0};
       float sV = slider.getValue();
        float sMin = slider.getMinimum();
        float sMax = slider.getMaximum();

       mTD = juce::jmap (sV, sMin, sMax, 0.f, 10.f);

       if (mTD > 0 && mTD <= 10) {g.drawImage(imageArray.getReference(mTD), sliderRect);}
       else if (mTD > 10) { g.drawImage(imageArray.getReference(10), sliderRect); }
       else{ g.drawImage(imageArray.getReference(1), sliderRect);}
    }
    
private:
};

class GlobalComponent  : public juce::Component
{
public:
    GlobalComponent();
    ~GlobalComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;


    juce::Slider

    mGainSlider,
    mRotationSlider,
    mThicknessSlider;
    
    juce::ToggleButton
    
    mMonoStereo;
    

private:
    MonoStereolaf lMonoStereo;
    Gainlaf lGain;
    Rotationlaf lRotation;
    Thicknesslaf lThickness;
    

    void setSlider (juce::Slider& slider);


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GlobalComponent)
};



