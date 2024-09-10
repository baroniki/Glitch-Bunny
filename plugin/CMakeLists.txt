cmake_minimum_required(VERSION 3.22)

project(GlitchBunny VERSION 0.1.0)

juce_add_plugin(${PROJECT_NAME} 
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE AL3x
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "Glitch Bunny"
)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/PluginEditor.cpp
        src/PluginProcessor.cpp
        src/KnobComponent.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        inc
        ${CMAKE_BINARY_DIR}/plugin/GlitchBunny_artefacts/JuceLibraryCode/
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

add_compile_definitions(JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1)
juce_generate_juce_header(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            _SILENCE_CXX23_ALIGNED_STORAGE_DEPRACATION_WARNING
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()