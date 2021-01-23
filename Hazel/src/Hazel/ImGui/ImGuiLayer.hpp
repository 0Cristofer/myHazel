//
// Created by crist on 22/01/2021.
//

#ifndef MYHAZEL_IMGUILAYER_HPP
#define MYHAZEL_IMGUILAYER_HPP

#include "../Layer.hpp"
#include "../Events/MouseEvent.hpp"
#include "../Events/KeyEvent.hpp"
#include "../Application.hpp"

namespace Hazel
{
    class HAZEL_API  ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

    private:
        float m_Time = 0.0f;

    private:
        bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
        bool OnMouseMoved(MouseMovedEvent& event);
        bool OnMouseScrolled(MouseScrolledEvent& event);
        bool OnKeyPressed(KeyPressedEvent& event);
        bool OnKeyReleased(KeyReleasedEvent& event);
        bool OnKeyTyped(KeyTypedEvent& event);
        bool OnWindowResized(WindowResizeEvent& event);

    };
}

#endif //MYHAZEL_IMGUILAYER_HPP
