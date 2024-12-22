/*
  ==============================================================================

    ToggleCustomLook.h
    Created: 21 Dec 2024 7:52:23pm
    Author:  Gabriel Souto

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ToggleCustomLook : public juce::LookAndFeel_V4
{
public:
    ToggleCustomLook(){}
    ~ToggleCustomLook() override {}
    
    void drawToggleButton(juce::Graphics& g, juce::ToggleButton& toggleButton)
    {
        auto bounds = toggleButton.getBoundsInParent().toFloat();
        juce::Rectangle<float> rect(bounds);
        
        g.setColour(juce::Colour(18, 115, 105));
        g.fillRect(rect);
    }
private:
    
};
