#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class KnobComponent : public juce::ImageComponent {
public:
    KnobComponent();
    ~KnobComponent() override;

protected:
    void paint(juce::Graphics& g) override;
    void mouseDrag(const juce::MouseEvent& e) override;
    void mouseDown(const juce::MouseEvent& e) override;
private:
    float m_RotationAngle;
    float m_LastMouseY;
    static constexpr float c_MinRotationRad = juce::MathConstants<float>::pi * 5/4;
    static constexpr float c_MaxRotationRad = juce::MathConstants<float>::pi * 7/4;
    static constexpr float c_RotationSens = 0.00001f;
};