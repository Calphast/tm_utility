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
    addAndMakeVisible(monoButton);
    
    // slider basic parameters
    gainSlider.setRange(0, 2, .01);
    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    gainSlider.setTextBoxIsEditable(false);
    gainSlider.setDoubleClickReturnValue(true, 1.0);
    gainSlider.setColour(juce::Slider::trackColourId, juce::Colour(18, 115, 105));
    gainSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(16,64,59));
    
    // button bassic parameters
    monoButton.setButtonText("Mono");
    monoButton.setClickingTogglesState(true);
    monoButton.setLookAndFeel(&toggleCustomLook);
    monoButton.setOpaque(false);
    monoButton.setAlpha(0.0f);
    
    // attaching slider to parameter
    juce::Value valueToControl = audioProcessor.apvts.getParameterAsValue("gain");
    gainSlider.getValueObject().referTo(valueToControl);
    
    // attaching button to parameter
    juce::Value monoValueToControl = audioProcessor.apvts.getParameterAsValue("monotoggle");
    monoButton.getToggleStateValue().referTo(monoValueToControl);
                                
    setSize (130, 330);
}

Tm_gainAudioProcessorEditor::~Tm_gainAudioProcessorEditor()
{
    monoButton.setLookAndFeel(nullptr);
}

//==============================================================================
void Tm_gainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colour (191,191,191));
    g.setFont(juce::Font(juce::FontOptions("Futura", 16.f, 0)));
    g.drawText("Gain", 50, 3, 30, 30, juce::Justification::centred);
 
    toggleCustomLook.drawToggleButton(g, monoButton);
}

void Tm_gainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(30, 30, 70, 240);

    // No Idea where this will go
    monoButton.setBounds(30, 285, 70, 30);
}
