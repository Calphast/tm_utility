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
    
    // slider styling
    gainSlider.setRange(0, 2, .01);
    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    gainSlider.setTextBoxIsEditable(false);
    gainSlider.setDoubleClickReturnValue(true, 1.0);
    gainSlider.setColour(juce::Slider::trackColourId, juce::Colour(18, 115, 105));
    gainSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(16,64,59));
    
    // button styling
    monoToggle.setName("Mono");
    monoToggle.setSize(15, 15);
    monoToggle.setButtonText("Mono");
    monoToggle.changeWidthToFitText();
    
    // attaching slider to parameter
    juce::Value valueToControl = audioProcessor.apvts.getParameterAsValue("gain");
    gainSlider.getValueObject().referTo(valueToControl);
    
    // attaching button to parameter
    juce::Value monoValueToControl = audioProcessor.apvts.getParameterAsValue("monotoggle");
    monoToggle.getToggleStateValue().referTo(monoValueToControl);
                                
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
    g.drawText("Gain", 50, 3, 30, 30, juce::Justification::centred);
    
    toggleCustomLook.drawToggleButton(g, monoToggle);
    monoToggle.setLookAndFeel(&toggleCustomLook);
    
    monoToggle.setLookAndFeel(nullptr);
}

void Tm_gainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(30, 30, 70, 240);

    // No Idea where this will go
    monoToggle.setBounds(120, 30, 67, 27);
}
