//
// Created by crist on 22/01/2021.
//

#include <imgui.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "ImGuiLayer.hpp"
#include "../../Platform/OpenGL/imgui_impl_opengl3.h"

namespace Hazel
{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        io.ClipboardUserData = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        io.SetClipboardTextFn = [](void *window, const char *text)
        {
            glfwSetClipboardString((GLFWwindow*)window, text);
        };
        io.GetClipboardTextFn = [](void *window)
        {
            return glfwGetClipboardString((GLFWwindow*)window);
        };

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {

    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& application = Application::Get();
        io.DisplaySize = ImVec2(application.GetWindow().GetWidth(), application.GetWindow().GetHeight());

        auto time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f/60.0f);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }



    void ImGuiLayer::OnEvent(Event &event)
    {
        EventDispatcher eventDispatcher(event);
        HZ_DISPATCH_EVENT(eventDispatcher, MouseButtonPressedEvent, OnMouseButtonPressed, event);
        HZ_DISPATCH_EVENT(eventDispatcher, MouseButtonReleasedEvent, OnMouseButtonReleased, event);
        HZ_DISPATCH_EVENT(eventDispatcher, MouseMovedEvent, OnMouseMoved, event);
        HZ_DISPATCH_EVENT(eventDispatcher, MouseScrolledEvent, OnMouseScrolled, event);
        HZ_DISPATCH_EVENT(eventDispatcher, KeyPressedEvent, OnKeyPressed, event);
        HZ_DISPATCH_EVENT(eventDispatcher, KeyReleasedEvent, OnKeyReleased, event);
        HZ_DISPATCH_EVENT(eventDispatcher, KeyTypedEvent, OnKeyTyped, event);
        HZ_DISPATCH_EVENT(eventDispatcher, WindowResizeEvent, OnWindowResized, event);
    }

    bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent & event)
    {
        ImGui::GetIO().MouseDown[event.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent & event)
    {
        ImGui::GetIO().MouseDown[event.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMoved(MouseMovedEvent & event)
    {
        ImGui::GetIO().MousePos = ImVec2(event.GetMouseX(), event.GetMouseY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.MouseWheelH += event.GetXOffset();
        io.MouseWheel += event.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressed(KeyPressedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.KeysDown[event.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

        return false;
    }

    bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.KeysDown[event.GetKeyCode()] = false;

        io.KeyCtrl = false;
        io.KeyShift = false;
        io.KeyAlt = false;
        io.KeySuper = false;

        return false;
    }

    bool ImGuiLayer::OnWindowResized(WindowResizeEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, event.GetWidth(), event.GetHeight());

        return false;
    }

    bool ImGuiLayer::OnKeyTyped(KeyTypedEvent &event)
    {
        int keycode = event.GetKeyCode();

        if (keycode > 0 && keycode < 0x10000)
            ImGui::GetIO().AddInputCharacter((unsigned int)keycode);

        return false;
    }
}