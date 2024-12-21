/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Tm_gainAudioProcessorEditor::Tm_gainAudioProcessorEditor (Tm_gainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(monoToggle);
    addAndMakeVisible (gainSlider);
    
    gainSlider.setRange(0, 2, .01);
    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    juce::Value valueToControl = audioProcessor.apvts.getParameterAsValue("gain");
    gainSlider.getValueObject().referTo(valueToControl);
    gainSlider.setTextBoxIsEditable(false);
    gainSlider.setDoubleClickReturnValue(true, 1.0);
    
    monoToggle.setName("Mono");
    monoToggle.setTitle("Mono");
    
    setSize (200, 300);
}

Tm_gainAudioProcessorEditor::~Tm_gainAudioProcessorEditor()
{
}

//==============================================================================
void Tm_gainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colour (191,191,191));
    
    gainSlider.setColour(juce::Slider::trackColourId, juce::Colour(16,64,59));
    gainSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(16,64,59));
}

void Tm_gainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(30, 30, 70, 240);

    // No Idea where this will go
    monoToggle.setBounds(110, 30, 30, 30);
}
