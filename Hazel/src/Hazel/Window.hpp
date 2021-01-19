//
// Created by crist on 19/01/2021.
//

#ifndef MYHAZEL_WINDOW_HPP
#define MYHAZEL_WINDOW_HPP

#include "Events/Event.hpp"

namespace Hazel
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title = "Hazel Engine",
                    unsigned int width = 1280, unsigned int height = 720)
                    : Title(title), Width(width), Height(height) {}

    };

    class HAZEL_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}

#endif //MYHAZEL_WINDOW_HPP
