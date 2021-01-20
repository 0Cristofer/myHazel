//
// Created by crist on 16/01/2021.
//

#include "Application.hpp"

namespace Hazel
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback([this] (Event& event) { this->OnEvent(event); });
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<WindowCloseEvent>(
                [this] (WindowCloseEvent& event) -> bool { return this->OnWindowClose(event); });

        HZ_CORE_TRACE("{0}", event);
    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }

    Application::~Application() = default;
}