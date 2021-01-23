//
// Created by crist on 23/01/2021.
//

#ifndef MYHAZEL_WINDOWSINPUT_HPP
#define MYHAZEL_WINDOWSINPUT_HPP

#include "../../Hazel/Input.hpp"

namespace Hazel
{
    class WindowsInput : public Input
    {
    protected:
        bool IsKeyPressedImpl(int keycode) override;
        bool IsMouseButtonPressedImpl(int button) override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;

        std::pair<float, float> GetMousePositionImpl() override;
    };
}


#endif //MYHAZEL_WINDOWSINPUT_HPP
