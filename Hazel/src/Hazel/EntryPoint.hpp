//
// Created by crist on 16/01/2021.
//

#ifndef MYHAZEL_ENTRYPOINT_HPP
#define MYHAZEL_ENTRYPOINT_HPP

#ifdef HZ_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
    auto app = Hazel::CreateApplication();

    app->Run();

    delete app;
    return 0;
}

#endif

#endif //MYHAZEL_ENTRYPOINT_HPP
