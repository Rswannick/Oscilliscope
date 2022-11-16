/*
  ==============================================================================

    CH1.h
    Created: 10 Sep 2022 7:13:43pm
    Author:  IK Multimedia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class CH1lafVOffset : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0000_png, BinaryData::CH1Voffset_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0000_png, BinaryData::CH1Voffset_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0002_png, BinaryData::CH1Voffset_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0003_png, BinaryData::CH1Voffset_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0004_png, BinaryData::CH1Voffset_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0005_png, BinaryData::CH1Voffset_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0006_png, BinaryData::CH1Voffset_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0007_png, BinaryData::CH1Voffset_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0008_png, BinaryData::CH1Voffset_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0009_png, BinaryData::CH1Voffset_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH1Voffset_0010_png, BinaryData::CH1Voffset_0010_pngSize);

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
       else if (mTD > 10) { g.drawImage(imageArray.getReference(11), sliderRect); }
       else{ g.drawImage(imageArray.getReference(1), sliderRect);}
    }
    
private:
};

class CH1lafHOffset : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0000_png, BinaryData::CH1Hoffset_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0000_png, BinaryData::CH1Hoffset_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0002_png, BinaryData::CH1Hoffset_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0003_png, BinaryData::CH1Hoffset_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0004_png, BinaryData::CH1Hoffset_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0005_png, BinaryData::CH1Hoffset_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0006_png, BinaryData::CH1Hoffset_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0007_png, BinaryData::CH1Hoffset_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0008_png, BinaryData::CH1Hoffset_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0009_png, BinaryData::CH1Hoffset_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH1Hoffset_0010_png, BinaryData::CH1Hoffset_0010_pngSize);

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

class CH1lafVolts : public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0000_png, BinaryData::CH1Volts_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0000_png, BinaryData::CH1Volts_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0002_png, BinaryData::CH1Volts_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0003_png, BinaryData::CH1Volts_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0004_png, BinaryData::CH1Volts_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0005_png, BinaryData::CH1Volts_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0006_png, BinaryData::CH1Volts_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0007_png, BinaryData::CH1Volts_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0008_png, BinaryData::CH1Volts_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0009_png, BinaryData::CH1Volts_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH1Volts_0010_png, BinaryData::CH1Volts_0010_pngSize);

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

class CH1lafVSeconds: public juce::LookAndFeel_V4
{
public:
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        auto sliderBounds = slider.getLocalBounds();

        juce::Rectangle<float> sliderRect;
        sliderRect.setBounds(sliderBounds.getX(), sliderBounds.getY(), sliderBounds.getWidth(), sliderBounds.getHeight());

        auto slider0 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0000_png, BinaryData::CH1Seconds_0000_pngSize);
        auto slider1 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0000_png, BinaryData::CH1Seconds_0001_pngSize);
        auto slider2 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0002_png, BinaryData::CH1Seconds_0002_pngSize);
        auto slider3 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0003_png, BinaryData::CH1Seconds_0003_pngSize);
        auto slider4 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0004_png, BinaryData::CH1Seconds_0004_pngSize);
        auto slider5 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0005_png, BinaryData::CH1Seconds_0005_pngSize);
        auto slider6 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0006_png, BinaryData::CH1Seconds_0006_pngSize);
        auto slider7 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0007_png, BinaryData::CH1Seconds_0007_pngSize);
        auto slider8 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0008_png, BinaryData::CH1Seconds_0008_pngSize);
        auto slider9 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0009_png, BinaryData::CH1Seconds_0009_pngSize);
        auto slider10 = juce::ImageCache::getFromMemory (BinaryData::CH1Seconds_0010_png, BinaryData::CH1Seconds_0010_pngSize);

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
    CH1lafVOffset lCH1VOffset;
    CH1lafHOffset lCH1HOffset;
    CH1lafVolts lCH1Volts;
    CH1lafVSeconds lCH1Seconds;
    
    void setSlider (juce::Slider& slider);
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CH1Component)
};



