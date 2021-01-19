//
// Created by crist on 19/01/2021.
//

#ifndef MYHAZEL_WINDOWSWINDOW_HPP
#define MYHAZEL_WINDOWSWINDOW_HPP

#include "../../Hazel/Window.hpp"

#include <GLFW/glfw3.h>

namespace Hazel
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn &callback) override{}

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}



#endif //MYHAZEL_WINDOWSWINDOW_HPP
