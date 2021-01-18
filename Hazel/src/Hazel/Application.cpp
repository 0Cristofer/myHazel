//
// Created by crist on 16/01/2021.
//

#include "Application.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace Hazel
{

    Application::Application()
    {

    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        HZ_TRACE(e);

        while (true);
    }

    Application::~Application()
    {

    }
}