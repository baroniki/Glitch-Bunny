#include "GlitchBunny/PluginProcessor.h"
#include "GlitchBunny/PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    :   AudioProcessorEditor (&p), 
        processorRef (p),
        DebugLogger (juce::FileLogger::createDefaultAppLogger("GlitchBunnyLogger", "GlitchBunnyLog.txt", "PLUGIN EDITOR LOGS")),
        BackgroundImage (juce::ImageFileFormat::loadFrom(juce::File::getCurrentWorkingDirectory().getChildFile("plugin/assets/BG/BG@1x.png")))
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (810, 480); // 21:16 ratio
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // add background image
    g.drawImage(BackgroundImage, getLocalBounds().toFloat());
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
