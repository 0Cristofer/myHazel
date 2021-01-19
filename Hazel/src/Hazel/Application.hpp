//
// Created by crist on 16/01/2021.
//

#ifndef MYHAZEL_APPLICATION_HPP
#define MYHAZEL_APPLICATION_HPP

#include "Window.hpp"

namespace Hazel
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
    };

    Application* CreateApplication();
}


#endif //MYHAZEL_APPLICATION_HPP
