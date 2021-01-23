//
// Created by crist on 22/01/2021.
//

#ifndef MYHAZEL_IMGUILAYER_HPP
#define MYHAZEL_IMGUILAYER_HPP

#include "../Layer.hpp"
#include "../Events/MouseEvent.hpp"
#include "../Events/KeyEvent.hpp"

namespace Hazel
{
    class HAZEL_API  ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}

#endif //MYHAZEL_IMGUILAYER_HPP
