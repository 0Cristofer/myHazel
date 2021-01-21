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

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();
        }
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<WindowCloseEvent>(
                [this] (WindowCloseEvent& event) -> bool { return this->OnWindowClose(event); });

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(event);
            if (event.Handled)
                break;
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    Application::~Application() = default;
}