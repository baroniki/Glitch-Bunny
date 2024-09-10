#include "GlitchBunny/KnobComponent.h"

KnobComponent::KnobComponent()
        :   m_RotationAngle(c_MinRotationRad),
            m_LastMouseY(0.f)
{

}

KnobComponent::~KnobComponent() {

}

void KnobComponent::paint(juce::Graphics& g) {
    auto rotation = juce::AffineTransform::rotation(m_RotationAngle, getWidth()/2.f, getHeight()/2.f);
    g.addTransform(rotation);

    juce::ImageComponent::paint(g);
}

void KnobComponent::mouseDown(const juce::MouseEvent& e) {
    m_LastMouseY = e.position.y;
}

void KnobComponent::mouseDrag(const juce::MouseEvent& e) {
    float deltay = m_LastMouseY - e.position.y;

    m_LastMouseY = e.position.y;
    m_RotationAngle += deltay * c_RotationSens;

    //
    juce::jlimit(c_MinRotationRad, c_MaxRotationRad, m_RotationAngle);

    repaint();
}