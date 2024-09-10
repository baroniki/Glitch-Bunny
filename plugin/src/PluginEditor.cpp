#include "GlitchBunny/PluginProcessor.h"
#include "GlitchBunny/PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    :   AudioProcessorEditor (&p), 
        processorRef (p),
        m_DebugLogger (juce::FileLogger::createDefaultAppLogger("GlitchBunnyLogger", "GlitchBunnyLog.txt", "PLUGIN EDITOR LOGS")),
        m_AssetsPath (juce::File::getCurrentWorkingDirectory().getChildFile("plugin/assets/")),
        m_BackgroundImage (juce::ImageFileFormat::loadFrom(m_AssetsPath.getChildFile("BG/BG@1x.png")))
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    m_Knob1.setImage(juce::ImageFileFormat::loadFrom(m_AssetsPath.getChildFile("Knob/Knob@1x.png")));

    addAndMakeVisible(m_Knob1, -1);

    setSize (810, 480); // 21:16 ratio
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // add background image
    g.drawImage(m_BackgroundImage, getLocalBounds().toFloat());
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    m_Knob1.setBounds(200, 200, 200, 200);
}
