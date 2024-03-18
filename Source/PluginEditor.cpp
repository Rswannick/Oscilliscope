/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OscilliscopeAudioProcessorEditor::OscilliscopeAudioProcessorEditor (OscilliscopeAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), cOscope (p), cOscope2(p)
{
    addLookAndFeel();
    addComponents();
    addListeners();
    setGUISize();
}

OscilliscopeAudioProcessorEditor::~OscilliscopeAudioProcessorEditor()
{
    stopTimer();
    mBypass.setLookAndFeel(nullptr);
    mPolarity.setLookAndFeel(nullptr);
}

//==============================================================================
void OscilliscopeAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::black);
    g.fillAll();
}

void OscilliscopeAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    
    bounds = setiOSBounds(bounds);
    
    float scopeX = bounds.getX() + bounds.getWidth() / 16;
    float scopeY = bounds.getY() + bounds.getHeight() / 6;
    float scopeW = bounds.getWidth() / 2.05;
    float scopeH = bounds.getHeight() / 1.85;
    
    float globalX = bounds.getX() +  bounds.getWidth() * .11;
    float globalY = bounds.getY() + bounds.getHeight() * .83;
    float globalW = bounds.getWidth() * .7915;
    float globalH = bounds.getHeight() * .0825;
    
    float chX =  bounds.getX() + bounds.getWidth() * .60;
    float ch1Y = bounds.getY() + bounds.getHeight() * .230;
    float ch2Y = bounds.getY() + bounds.getHeight() * .525;
    float chW = bounds.getWidth() * .325;
    float chH = bounds.getHeight() * .130;
    
    float buttonX =  bounds.getX() + bounds.getWidth() * .895;
    float buttonY = bounds.getY() + bounds.getHeight() * .705;
    float buttonW = bounds.getWidth() * .045;
    float buttonH = bounds.getHeight() * .065;
    
    if (JUCE_IOS)
    {
        globalY = bounds.getY() + bounds.getHeight() * .825;
        ch2Y = bounds.getY() + bounds.getHeight() * .53;
        buttonY = bounds.getY() + bounds.getHeight() * .70;
    }

    //Visuals
    cBackground.setBounds(bounds);
    cOscope.setBounds(scopeX, scopeY, scopeW, scopeH);
    cOscope2.setBounds(scopeX, scopeY, scopeW, scopeH);
    //Hide Oscilloscope when off
    if (mBypass.getToggleState() == 0) { cOscope.scopeComponent.setVisible(true); cOscope2.scopeComponent2.setVisible(true); }
    else { cOscope.scopeComponent.setVisible(false); cOscope2.scopeComponent2.setVisible(false);}
    //Controls
    cGlobal.setBounds(globalX, globalY, globalW, globalH);
    cCH1.setBounds(chX, ch1Y, chW, chH);
    cCH2.setBounds(chX, ch2Y, chW, chH);
    //Power
    mBypass.setBounds(buttonX, buttonY, buttonW, buttonH);
    //Polarity
    mPolarity.setBounds(mBypass.getX() - (buttonW * 3.45), buttonY, buttonW * .75, buttonH * 1.25);
    
    //Settings// - Settings Button
    mSettings.setBounds(bounds.getX() + (bounds.getRight() * .93), bounds.getY() + (bounds.getHeight() * .90), bounds.getWidth() * .075,  bounds.getHeight() * .075);
    
    audioProcessor.windowW = bounds.getWidth();
    audioProcessor.windowH = bounds.getHeight();
    
}

void OscilliscopeAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &cGlobal.mGainSlider) { audioProcessor.cOscilloscope.gainValue = cGlobal.mGainSlider.getValue(); }
    if (slider == &cGlobal.mThicknessSlider) { cOscope.scopeComponent.mThick = cGlobal.mThicknessSlider.getValue(); cOscope2.scopeComponent2.mThick2 = cGlobal.mThicknessSlider.getValue(); }
    if (slider == &cGlobal.mRotationSlider) { cOscope.scopeComponent.mRotation = cGlobal.mRotationSlider.getValue();
        cOscope2.scopeComponent2.mRotation2 = cGlobal.mRotationSlider.getValue(); }

    
    if (slider == &cCH1.mVOffsetSlider) { cOscope.scopeComponent.mVOffset = cCH1.mVOffsetSlider.getValue(); }
    if (slider == &cCH1.mHOffsetSlider) { cOscope.scopeComponent.mHOffset = cCH1.mHOffsetSlider.getValue(); }
    if (slider == &cCH1.mSecondsSlider) { cOscope.scopeComponent.mSeconds = cCH1.mSecondsSlider.getValue(); }
    if (slider == &cCH1.mVoltsSlider) { cOscope.scopeComponent.mVolts = cCH1.mVoltsSlider.getValue(); }

    if (slider == &cCH2.mVOffsetSlider) { cOscope2.scopeComponent2.mVOffset2 = cCH2.mVOffsetSlider.getValue(); }
    if (slider == &cCH2.mHOffsetSlider) { cOscope2.scopeComponent2.mHOffset2 = cCH2.mHOffsetSlider.getValue(); }
    if (slider == &cCH2.mSecondsSlider) { cOscope2.scopeComponent2.mSeconds2 = cCH2.mSecondsSlider.getValue(); }
    if (slider == &cCH2.mVoltsSlider) { cOscope2.scopeComponent2.mVolts2 = cCH2.mVoltsSlider.getValue(); }
}

void OscilliscopeAudioProcessorEditor::buttonStateChanged(juce::Button *button)
{
    if (button == &mPolarity)
    {
        if (mPolarity.getToggleState())
        { cOscope.scopeComponent.mPhase = 1;
          cOscope2.scopeComponent2.mPhase2 = 1; }
        else { cOscope.scopeComponent.mPhase = -1 ;
               cOscope2.scopeComponent2.mPhase2 = -1; }
    }

    if (button == &mBypass)
    {
        audioProcessor.cOscilloscope.mBypass = mBypass.getToggleState();
        resized();
    }
    
    if (button == &cGlobal.mMonoStereo)
    {
       if (cGlobal.mMonoStereo.getToggleState())
       {cOscope.setVisible(true);
        cOscope2.setVisible(true);
       }
       else
       { cOscope.setVisible(true);
         cOscope2.setVisible(false);
       }
    }
}

void OscilliscopeAudioProcessorEditor::buttonClicked(juce::Button *button)
{
    //Necessary function for Button Listener
}

void OscilliscopeAudioProcessorEditor::timerCallback()
{
    cOscope.scopeComponent.rmsValue = audioProcessor.cOscilloscope.rmsValue;
    cOscope.scopeComponent.peakValue = audioProcessor.cOscilloscope.peakValue;
    cOscope2.scopeComponent2.rmsValue2 = audioProcessor.cOscilloscope.rmsValue2;
    cOscope2.scopeComponent2.peakValue2 = audioProcessor.cOscilloscope.peakValue2;
}

void OscilliscopeAudioProcessorEditor::openSettings()
{
    auto pluginHolder = juce::StandalonePluginHolder::getInstance();
    pluginHolder->showAudioSettingsDialog();
}

void OscilliscopeAudioProcessorEditor::addComponents()
{
    cGlobal.mMonoStereo.setToggleState(false, juce::NotificationType::dontSendNotification);

    //Settings Menu
     auto settingsOff = juce::ImageCache::getFromMemory (BinaryData::settingsIcon_png, BinaryData::settingsIcon_pngSize);
    
     mSettings.setImages(false, true, true, settingsOff, 1, juce::Colours::white, settingsOff, 0, juce::Colours::grey, settingsOff, 1, juce::Colours::yellow);
     mSettings.onClick = [this] { openSettings(); };
    
    //Add Visual subcomponents
    addAndMakeVisible(cBackground);
    addAndMakeVisible(cOscope);
    addAndMakeVisible(cOscope2);
    cOscope2.setVisible(false);

    //Add Control Subcomponents
    addAndMakeVisible(cGlobal);
    addAndMakeVisible(cCH1);
    addAndMakeVisible(cCH2);
    
    if (juce::JUCEApplication::isStandaloneApp())
    {
        addAndMakeVisible(mSettings);
        mSettings.onClick = [this] { openSettings(); };
    }
    
    //Bypass Polarity
    addAndMakeVisible(mBypass);
    addAndMakeVisible(mPolarity);
    
}

void OscilliscopeAudioProcessorEditor::addListeners()
{
    //Listeners
    cGlobal.mGainSlider.addListener(this);
    cGlobal.mRotationSlider.addListener(this);
    cGlobal.mThicknessSlider.addListener(this);
    cGlobal.mMonoStereo.addListener(this);
    
    cCH1.mHOffsetSlider.addListener(this);
    cCH1.mVoltsSlider.addListener(this);
    cCH1.mVOffsetSlider.addListener(this);
    cCH1.mSecondsSlider.addListener(this);
           
    cCH2.mHOffsetSlider.addListener(this);
    cCH2.mVoltsSlider.addListener(this);
    cCH2.mVOffsetSlider.addListener(this);
    cCH2.mSecondsSlider.addListener(this);
    
    mBypass.addListener(this);
    mPolarity.addListener(this);
}

void OscilliscopeAudioProcessorEditor::addLookAndFeel()
{
    juce::LookAndFeel::getDefaultLookAndFeel().setDefaultLookAndFeel(&cLAF.newLAF);
    
    mBypass.setLookAndFeel(&cLAF.lBypass);
    mPolarity.setLookAndFeel(&cLAF.lPhase);
}

void OscilliscopeAudioProcessorEditor::setGUISize()
{
    sizeX = audioProcessor.windowW;
    sizeY = audioProcessor.windowH;
    
    double ratio = 6.0/3.0;
    
    if (JUCE_IOS)
    {
        auto screenSize = juce::Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
        float width = screenSize.getWidth();
        float height = screenSize.getHeight();
        sizeX = width;
        sizeY = height;
        startTimer(120);
    }
    else
    {
        setResizable(true, true);
        ratio = ratio = 6.0/3.0;
        setResizeLimits(400, 400/ratio, 1200, 1200/ratio);
        getConstrainer()->setFixedAspectRatio(ratio);
        startTimer(60);
    }
    
    setSize(sizeX, sizeY);
}

juce::Rectangle<int>  OscilliscopeAudioProcessorEditor::setiOSBounds(juce::Rectangle<int> iOSBounds)
{
    if (JUCE_IOS)
    {
        const double targetAspectRatio = 6.0 / 3.0;
        double currentAspectRatio = static_cast<double>(iOSBounds.getWidth()) / iOSBounds.getHeight();

        if (currentAspectRatio > targetAspectRatio)
        {
            int newWidth = static_cast<int>(iOSBounds.getHeight() * targetAspectRatio);
            int xOffset = (iOSBounds.getWidth() - newWidth) / 2;
            iOSBounds.setX(iOSBounds.getX() + xOffset);
            iOSBounds.setWidth(newWidth);
        }
        else if (currentAspectRatio < targetAspectRatio)
        {
            int newHeight = static_cast<int>(iOSBounds.getWidth() / targetAspectRatio);
            int yOffset = (iOSBounds.getHeight() - newHeight) / 2;
            iOSBounds.setY(iOSBounds.getY() + yOffset);
            iOSBounds.setHeight(newHeight);
        }
    }
    
    return iOSBounds;
}
