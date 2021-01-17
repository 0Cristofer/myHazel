//
// Created by crist on 16/01/2021.
//

#ifndef MYHAZEL_ENTRYPOINT_HPP
#define MYHAZEL_ENTRYPOINT_HPP

#include "Log.hpp"

#ifdef HZ_PLATFORM_SUPPORTED

int main(int argc, char** argv)
{
    Hazel::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    int a = 5;
    HZ_INFO("Hello! Var = {0}", a);


    auto app = Hazel::CreateApplication();

    app->Run();

    delete app;
    return 0;
}

#endif

#endif //MYHAZEL_ENTRYPOINT_HPP
