#include <gtest/gtest.h>
#include <JuceWorkflow/PluginProcessor.h>

namespace audio_plugin_test {
TEST(AudioPlugin, Test1) {
    AudioPluginAudioProcessor processor{};
    ASSERT_FALSE(true);
}
}