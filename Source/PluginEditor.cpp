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
    addAndMakeVisible (gainSlider);
    gainSlider.setRange(0, 12);
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    
    juce::Value valueToControl = audioProcessor.apvts.getParameterAsValue("gain");
    gainSlider.getValueObject().referTo(valueToControl);
    
    setSize (200, 300);
}

Tm_gainAudioProcessorEditor::~Tm_gainAudioProcessorEditor()
{
}

//==============================================================================
void Tm_gainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void Tm_gainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(30, 30, 140, 240);
}
