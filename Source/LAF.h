/*
  ==============================================================================

    InfoWindow.h
    Created: 16 Jan 2022 3:53:43pm
    Author:  Ryan Swannick
==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#ifndef JUCE_IOS
#define JUCE_IOS 0 // Define a default value if JUCE_IOS is not defined
#endif

class WindowLAF : public juce::LookAndFeel_V4
{
public:

void drawLabel(juce::Graphics &g, juce::Label &label) override
{
    auto bounds = label.getLocalBounds();

    g.setFont(bounds.getHeight() * .40);
    g.setColour(juce::Colours::white);
    
    juce::Rectangle<int> rect;
    rect.setBounds(bounds.getX(),bounds.getY(),bounds.getWidth(),bounds.getHeight());
    
    g.drawFittedText(label.getText().toStdString(), rect, juce::Justification::centred, 1);
}
    
void drawButtonBackground (juce::Graphics & g, juce::Button & button, const juce::Colour &backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override

    {
        //Intentionally empty.
    }
    
void drawButtonText (juce::Graphics & g, juce::TextButton & button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown ) override
        
    {
        if (button.isDown() == false)
        {
            g.setColour(juce::Colours::white);
            g.drawText(" X ", button.getX(), button.getY(), button.getWidth(), button.getHeight(), juce::Justification::centred);
        }
        if (button.isDown() == true)
        {
            g.setColour(juce::Colours::lightblue);
            g.drawText(" X ", button.getX(), button.getY(), button.getWidth(), button.getHeight(), juce::Justification::centred);
        }
    }

private:

};


class NewLAF : public juce::LookAndFeel_V4
{
public:
    
    
    void drawScrollbar(juce::Graphics& g, juce::ScrollBar& scrollbar, int x, int y, int width, int height, bool isScrollbarVertical, int thumbStartPosition, int thumbSize, bool isMouseOver, bool isMouseDown) override
    {
        // Define colors for the scrollbar
        juce::Colour thumbColor(0xff808080); // Grey color
        juce::Colour backgroundColour(0xff000000); // Black background

        // Fill the background
        g.setColour(backgroundColour);
        g.fillRect(x, y, width, height);

        // Draw the thumb (the actual scrollbar)
        g.setColour(thumbColor);
        if (isScrollbarVertical)
            g.fillRect(x, thumbStartPosition, width, thumbSize);
        else
            g.fillRect(thumbStartPosition, y, thumbSize, height);
    }
    
    void drawLabel(juce::Graphics &g, juce::Label &label) override
    {
        auto bounds = label.getLocalBounds();
        
        juce::Rectangle<float> textBox;
        textBox.setBounds(bounds.getCentreX() * .50, bounds.getY(), bounds.getWidth() * .70, bounds.getHeight() * 1.15);
        
        g.setColour(juce::Colours::white);
        
        g.setFont(label.getHeight() * .525);
                
        if (label.getText().contains("avoid"))
        {
            g.setFont(label.getHeight() * .50);
            g.drawFittedText("Audio muted to avoid feedback", label.getX(), label.getY() * .50, label.getWidth(), label.getHeight(), juce::Justification::left, 1);
        }
        else if (label.getText().contains("Input:") || label.getText().contains("Output:") || label.getText().contains("Feedback Loop:"))
        {
            
            juce::String text = label.getText();
            
            if (label.getText().contains("Input:"))
            { text = "In:"; }
            if ( label.getText().contains("Output:") )
            { text = "Out:"; }
            if (label.getText().contains("Feedback Loop:"))
            { text = ""; }
          
            g.drawFittedText(text, textBox.getX(), textBox.getY(), textBox.getWidth(), textBox.getHeight(), juce::Justification::left, 1);
        }
        else if (label.getText().contains("channels"))
        {
            //Don't write text
            if (JUCE_IOS)
            {
                juce::String text = label.getText();
                
                if (label.getText().contains("input"))
                { text = "In:"; }
                if ( label.getText().contains("output") )
                { text = "Out:"; }
              
                g.drawFittedText(text, textBox.getX(), textBox.getY(), textBox.getWidth(), textBox.getHeight(), juce::Justification::right, 1);
            }
        }
        else if (label.getText().contains("Active MIDI"))
        {
            g.drawFittedText(label.getText(), label.getX() - (label.getWidth() * .75), label.getBounds().getCentreY(), label.getWidth(), label.getHeight() * .25, juce::Justification::left, 1);
        }
        else if (label.getText().contains("Audio buffer size:"))
        {
            g.drawFittedText("Buffer:", textBox.getX() * .90, 0, label.getWidth(), label.getHeight(), juce::Justification::centred, 1);
        }
        else if (label.getText().contains("Sample rate"))
        {
            g.drawFittedText("S.R:", textBox.getX(), 0, label.getWidth(), label.getHeight(), juce::Justification::centred, 1);
        }
        else
        {
            g.drawFittedText(label.getText(), label.getX() + (label.getWidth() * .10), 0, label.getWidth(), label.getHeight(), juce::Justification::left, 1);
        }
        
    }
    
    void drawComboBoxTextWhenNothingSelected(juce::Graphics &g, juce::ComboBox &box, juce::Label &lbl) override
     {
         g.setColour(juce::Colours::white);
         
         if (JUCE_IOS)
         {  g.setFont(box.getHeight() * .25);
         }
         else
         {  g.setFont(box.getHeight() * .50); }
         
         g.drawText("LOAD FX", box.getX(), box.getY(), box.getWidth(), box.getHeight(), juce::Justification::centred);
     }
    
    void drawBubble(juce::Graphics &g, juce::BubbleComponent &bubble, const juce::Point<float> &tip, const juce::Rectangle<float> &body) override
    {
        
        bubble.setColour(juce::BubbleComponent::ColourIds::backgroundColourId, juce::Colours::black);
        bubble.setColour(juce::TooltipWindow::ColourIds::textColourId, juce::Colours::grey);
                
    }
    
    void drawTickBox(juce::Graphics &g, juce::Component &c, float x, float y, float w, float h, bool ticked, bool isEnabled, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        c.setColour(juce::ListBox::ColourIds::backgroundColourId, juce::Colours::black);
        c.setColour(juce::ListBox::ColourIds::textColourId, juce::Colours::white);

        g.setColour(juce::Colours::black);
        g.fillAll();
        
        // Fill the rectangle with green if ticked
         if (ticked)
         {
             g.setColour(juce::Colours::skyblue);
             g.fillRect(x + 2, y + 2, w - 4, h - 4);
         }
    }
        
    void positionComboBoxText(juce::ComboBox &box, juce::Label &label) override
    {
        label.setSize(box.getWidth(), box.getHeight());
        label.setJustificationType(juce::Justification::centred);
        label.setSize(0, 0);
        
        box.setJustificationType(juce::Justification::centred);
         
        if (JUCE_IOS)
        {
            getOptionsForComboBoxPopupMenu(box, label);
        }
    }
    
    void drawPopupMenuItem(juce::Graphics &g, const juce::Rectangle<int> &area, bool isSeparator, bool isActive, bool isHighlighted, bool isTicked, bool hasSubMenu, const juce::String &text, const juce::String &shortcutKeyText, const juce::Drawable *icon, const juce::Colour *textColour) override
    {
        g.setColour(juce::Colours::grey);

        if (isTicked == true)
        { g.setColour(juce::Colours::skyblue); }
        else if (isHighlighted == true)
        { g.setColour(juce::Colours::white); }
        else
        { g.setColour(juce::Colours::grey); }
        
        g.drawFittedText(text, area, juce::Justification::centred, 1);
    }
    
    void drawComboBox(juce::Graphics &g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, juce::ComboBox &box) override
    {
        auto bounds = box.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setBounds(0, 0, bounds.getWidth(), bounds.getHeight());
        g.setColour(juce::Colour::fromRGB(60, 60, 60));
        g.fillRoundedRectangle(rect, 5.0);
        g.setColour(juce::Colour::fromRGB(24, 24, 24));
        g.drawRoundedRectangle(rect, 5.f, .3f);
        g.setFont(bounds.getHeight() * .45);
        g.setColour(juce::Colour::fromRGB(250, 250, 250));
        g.drawFittedText(box.getText(), bounds.getX(), bounds.getY() + (bounds.getHeight() * .05) , bounds.getWidth(), bounds.getHeight() ,juce::Justification::centred, 1);
    }
    
    void drawButtonText(juce::Graphics &g, juce::TextButton &button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        
        auto bounds = button.getLocalBounds();
        juce::Rectangle<int> rect;
        rect.setBounds(bounds.getX(),bounds.getY(),bounds.getWidth(),bounds.getHeight());
        
        if (shouldDrawButtonAsDown)
        { g.setColour(juce::Colour::fromRGB(0,250,250)); }
        else
        { g.setColour(juce::Colours::white); }

        g.setFont(bounds.getHeight() * .4);
        g.drawFittedText(button.getButtonText(), rect, juce::Justification::centred, 1);
        
    }

    juce::Component* getParentComponentForMenuOptions (const juce::PopupMenu::Options& options) override
    {
        
            #if JUCE_IOS
                if (juce::PluginHostType::getPluginLoadedAs() == juce::AudioProcessor::wrapperType_AudioUnitv3)
                {
                     if (options.getParentComponent() == nullptr && options.getTargetComponent() != nullptr)
                         return options.getTargetComponent()->getTopLevelComponent();
                }
            #endif
            
               return LookAndFeel_V2::getParentComponentForMenuOptions (options);
    }

    void drawPopupMenuBackground(juce::Graphics &g, int width, int height) override
    {
        g.setColour(juce::Colours::black);
        g.fillAll();
        
        g.setColour(juce::Colours::lightgrey);
        juce::Rectangle<float> rect;
        rect.setBounds(0, 0, width, height);
        g.drawRect(rect);
    }
    
    void drawToggleButton(juce::Graphics &g, juce::ToggleButton & toggleButton, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        auto bounds = toggleButton.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setBounds(0, 0, bounds.getWidth(), bounds.getHeight());
        g.setColour(juce::Colour::fromRGB(60, 60, 60));
        g.fillRoundedRectangle(rect, 5.0);
        g.setColour(juce::Colour::fromRGB(24, 24, 24));
        g.drawRoundedRectangle(rect, 5.f, .3f);
        g.setFont(bounds.getHeight() * .45);
        if (toggleButton.getToggleState()) {  g.setColour(juce::Colour::fromRGB(0, 250, 250)); }
        else if (shouldDrawButtonAsHighlighted) {  g.setColour(juce::Colour::fromRGB(220, 220, 220)); }
        else { g.setColour(juce::Colour::fromRGB(250, 250, 250)); }
        g.drawFittedText(toggleButton.getButtonText(), bounds.getX(), bounds.getY() + (bounds.getHeight() * .05) , bounds.getWidth(), bounds.getHeight() ,juce::Justification::centred, 1);
    }
    
    void drawButtonBackground (juce::Graphics &g, juce::Button &button, const juce::Colour &backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setBounds(0, 0, bounds.getWidth(), bounds.getHeight());
        g.setColour(juce::Colour::fromRGB(60, 60, 60));
        g.fillRoundedRectangle(rect, 5.0);
        g.setColour(juce::Colour::fromRGB(24, 24, 24));
        g.drawRoundedRectangle(rect, 5.f, .3f);
    }


    
    juce::Component* topLevelComponent;

private:
    

};

class Bypasslaf : public juce::LookAndFeel_V4 {
public:
    
    void drawToggleButton    (juce::Graphics & g,
                              juce::ToggleButton & button,
                              bool shouldDrawButtonAsHighlighted,
                              bool shouldDrawButtonAsDown
                              ) override
    {
        
        auto onButton = juce::ImageCache::getFromMemory (BinaryData::POWER_ON_png, BinaryData::POWER_ON_pngSize);
        auto offButton = juce::ImageCache::getFromMemory (BinaryData::POWER_OFF_png, BinaryData::POWER_OFF_pngSize);
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setSize(bounds.getWidth(), bounds.getHeight());

        if (button.getToggleState() == 0) {g.drawImage(onButton, rect); }
        else { g.drawImage(offButton, rect); }
        
    }

};

class Phaselaf : public juce::LookAndFeel_V4 {
public:
    
    void drawToggleButton    (juce::Graphics & g,
                              juce::ToggleButton & button,
                              bool shouldDrawButtonAsHighlighted,
                              bool shouldDrawButtonAsDown
                              ) override
    {
        
        auto onButton = juce::ImageCache::getFromMemory (BinaryData::PHASE_ON_png, BinaryData::PHASE_ON_pngSize);
        auto offButton = juce::ImageCache::getFromMemory (BinaryData::PHASE_OFF_png, BinaryData::PHASE_OFF_pngSize);
        auto bounds = button.getLocalBounds();
        juce::Rectangle<float> rect;
        rect.setSize(bounds.getWidth(), bounds.getHeight());

        if (button.getToggleState() == 0) {g.drawImage(onButton, rect); }
        else { g.drawImage(offButton, rect); }
    }

};

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


//==============================================================================
/*
*/
class LAFComponent  : public juce::Component
{
public:
    LAFComponent();
    ~LAFComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    NewLAF newLAF;
    WindowLAF lWindow;

    Bypasslaf lBypass;
    Phaselaf lPhase;
    
    CH1lafVOffset lCH1VOffset, lCH2VOffset;
    CH1lafHOffset lCH1HOffset, lCH2HOffset;
    CH1lafVolts lCH1Volts, lCH2Volts;
    CH1lafVSeconds lCH1Seconds, lCH2Seconds;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LAFComponent)
};







