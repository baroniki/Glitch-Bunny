#pragma once

#include <memory>

#include "GlitchBunny/PluginProcessor.h"
#include "GlitchBunny/KnobComponent.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    std::unique_ptr<juce::FileLogger> m_DebugLogger;

    juce::File m_AssetsPath = juce::File::getCurrentWorkingDirectory().getChildFile("plugin/assets/");

    juce::Image m_BackgroundImage;

    KnobComponent m_Knob1;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
