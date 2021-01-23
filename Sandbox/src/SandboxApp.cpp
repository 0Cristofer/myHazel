//
// Created by crist on 16/01/2021.
//

#include <Hazel.hpp>
#include <imgui.h>

class ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("TESTE APP");

        ImGui::Text("Teste texto");

        ImGui::End();
    }

    void OnEvent(Hazel::Event &event) override
    {
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() override
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}