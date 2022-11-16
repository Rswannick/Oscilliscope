/*
  ==============================================================================

    CH2.h
    Created: 10 Sep 2022 7:14:03pm
    Author:  IK Multimedia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class CH2lafVOffset : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0000_png, BinaryData::CH2Voffset_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0000_png, BinaryData::CH2Voffset_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0002_png, BinaryData::CH2Voffset_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0003_png, BinaryData::CH2Voffset_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0004_png, BinaryData::CH2Voffset_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0005_png, BinaryData::CH2Voffset_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0006_png, BinaryData::CH2Voffset_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0007_png, BinaryData::CH2Voffset_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0008_png, BinaryData::CH2Voffset_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0009_png, BinaryData::CH2Voffset_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH2Voffset_0010_png, BinaryData::CH2Voffset_0010_pngSize);

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

class CH2lafHOffset : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0000_png, BinaryData::CH2Hoffset_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0000_png, BinaryData::CH2Hoffset_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0002_png, BinaryData::CH2Hoffset_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0003_png, BinaryData::CH2Hoffset_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0004_png, BinaryData::CH2Hoffset_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0005_png, BinaryData::CH2Hoffset_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0006_png, BinaryData::CH2Hoffset_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0007_png, BinaryData::CH2Hoffset_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0008_png, BinaryData::CH2Hoffset_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0009_png, BinaryData::CH2Hoffset_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH2Hoffset_0010_png, BinaryData::CH2Hoffset_0010_pngSize);

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

class CH2lafVolts : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0000_png, BinaryData::CH2Volts_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0000_png, BinaryData::CH2Volts_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0002_png, BinaryData::CH2Volts_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0003_png, BinaryData::CH2Volts_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0004_png, BinaryData::CH2Volts_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0005_png, BinaryData::CH2Volts_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0006_png, BinaryData::CH2Volts_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0007_png, BinaryData::CH2Volts_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0008_png, BinaryData::CH2Volts_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0009_png, BinaryData::CH2Volts_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH2Volts_0010_png, BinaryData::CH2Volts_0010_pngSize);

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

class CH2lafVSeconds: public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0000_png, BinaryData::CH2Seconds_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0000_png, BinaryData::CH2Seconds_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0002_png, BinaryData::CH2Seconds_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0003_png, BinaryData::CH2Seconds_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0004_png, BinaryData::CH2Seconds_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0005_png, BinaryData::CH2Seconds_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0006_png, BinaryData::CH2Seconds_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0007_png, BinaryData::CH2Seconds_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0008_png, BinaryData::CH2Seconds_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0009_png, BinaryData::CH2Seconds_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH2Seconds_0010_png, BinaryData::CH2Seconds_0010_pngSize);

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

class CH2Component  : public juce::Component
{
public:
    CH2Component();
    ~CH2Component() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::Slider

    mHOffsetSlider,
    mVOffsetSlider,
    mVoltsSlider,
    mSecondsSlider;

private:
    CH2lafVOffset lCH2VOffset;
    CH2lafHOffset lCH2HOffset;
    CH2lafVolts lCH2Volts;
    CH2lafVSeconds lCH2Seconds;
    
    void setSlider (juce::Slider& slider);


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CH2Component)
};



