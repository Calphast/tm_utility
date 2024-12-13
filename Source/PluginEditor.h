/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Tm_gainAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Tm_gainAudioProcessorEditor (Tm_gainAudioProcessor&);
    ~Tm_gainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Tm_gainAudioProcessor& audioProcessor;
    
    juce::Slider gainSlider;
    juce::ToggleButton monoToggle;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tm_gainAudioProcessorEditor)
};
