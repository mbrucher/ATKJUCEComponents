/**
 * \file VolumeFilter.cpp
 */

#include "VolumeFilter.h"

#include "../JUCE/LookAndFeel.h"

namespace ATK
{
  namespace juce
  {
    VolumeFilterComponent::VolumeFilterComponent (VolumeFilter<double>& filter, ::juce::String display, double min, double max, double default_)
    : filter (filter), levelSlider(::juce::Slider::SliderStyle::Rotary, ::juce::Slider::TextEntryBoxPosition::TextBoxBelow)
    {
      addAndMakeVisible(levelSlider);
      levelSlider.setRange (min, max);
      levelSlider.setValue(default_);
      levelSlider.setTextValueSuffix (" dB");
      levelSlider.setColour(::juce::Slider::thumbColourId, ::juce::Colour::fromFloatRGBA(1, 1, 1, 0));
      levelSlider.setColour(::juce::Slider::rotarySliderFillColourId, ::juce::Colours::orange);
      levelSlider.setLookAndFeel(&SimpleSliderLookAndFeel::get_instance());
      
      addAndMakeVisible(levelLabel);
      levelLabel.setText(display, ::juce::NotificationType::dontSendNotification);
      levelLabel.setJustificationType(::juce::Justification::centred);
      
      // Make sure that before the constructor has finished, you've set the
      // editor's size to whatever you need it to be.
      setSize (200, 200);
    }
    
    VolumeFilterComponent::~VolumeFilterComponent()
    {
    }
    
    void VolumeFilterComponent::resized()
    {
      levelLabel.setBoundsRelative(0.3, 0.05, 0.4, 0.1);
      levelSlider.setBoundsRelative(0.1, 0.2, 0.8, 0.7);
    }
    
  }
}
