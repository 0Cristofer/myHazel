//
// Created by crist on 16/01/2021.
//

#ifndef MYHAZEL_APPLICATION_HPP
#define MYHAZEL_APPLICATION_HPP

#include "Window.hpp"
#include "Events/ApplicationEvent.hpp"
#include "LayerStack.hpp"

namespace Hazel
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;

        void OnEvent(Event& event);
        bool OnWindowClose(WindowCloseEvent& event);
    };

    Application* CreateApplication();
}


#endif //MYHAZEL_APPLICATION_HPP
