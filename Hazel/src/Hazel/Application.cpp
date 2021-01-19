//
// Created by crist on 16/01/2021.
//

#include "Application.hpp"

namespace Hazel
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    Application::~Application()
    {

    }
}