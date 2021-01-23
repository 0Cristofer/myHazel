//
// Created by crist on 19/01/2021.
//

#ifndef MYHAZEL_WINDOWSWINDOW_HPP
#define MYHAZEL_WINDOWSWINDOW_HPP

#include "Hazel/Window.hpp"

#include <GLFW/glfw3.h>

namespace Hazel
{
    class WindowsWindow : public Window
    {
    public:
        explicit WindowsWindow(const WindowProps& props);
        ~WindowsWindow() override;

        void OnUpdate() override;

        [[nodiscard]] inline void* GetNativeWindow() const override { return m_Window; }
        [[nodiscard]] unsigned int GetWidth() const override { return m_Data.Width; }
        [[nodiscard]] unsigned int GetHeight() const override { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;

    private:
        void Init(const WindowProps& props);
        void Shutdown();
    private:
        GLFWwindow* m_Window{};

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
