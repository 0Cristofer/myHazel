//
// Created by crist on 16/01/2021.
//

#include <Hazel.hpp>

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}