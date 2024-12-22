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
    
    void drawToggleButton(juce::Graphics& g, juce::TextButton& button)
    {
        auto bounds = button.getBoundsInParent();
        bool buttonStatus = button.getToggleState();
        
        juce::Rectangle<int> mainRectangle(button.getX(), button.getY(), button.getWidth(), button.getHeight());
        
        g.setFont(juce::Font(juce::FontOptions("Futura", 16.f, 0)));
        
        if(buttonStatus)
        {
            g.setColour(juce::Colour(18, 115, 105));
            g.fillRect(mainRectangle);
            
            g.setColour(juce::Colour(16,64,59));
            g.drawRect(mainRectangle);
            
            g.setColour(juce::Colours::white);
            g.drawFittedText("Mono", mainRectangle, juce::Justification::centred, 1);
        }
        else
        {
            g.setColour(juce::Colours::white);
            g.fillRect(mainRectangle);
            
            g.setColour(juce::Colour(18, 115, 105));
            g.drawRect(mainRectangle);
            
            g.setColour(juce::Colours::black);
            g.drawFittedText("Mono", mainRectangle, juce::Justification::centred, 1);
        }
    }
private:
    
};
