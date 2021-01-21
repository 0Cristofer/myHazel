//
// Created by crist on 16/01/2021.
//

#include <Hazel.hpp>

class ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
        HZ_INFO(GetName() + ": Update");
    }

    void OnEvent(Hazel::Event &event) override
    {
        HZ_TRACE(GetName() + ", {0}", event);
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}