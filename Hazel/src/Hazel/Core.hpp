//
// Created by crist on 16/01/2021.
//

#ifndef MYHAZEL_CORE_HPP
#define MYHAZEL_CORE_HPP

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
    #define HZ_PLATFORM_SUPPORTED
#elif HZ_PLATFORM_LINUX
    #define HAZEL_API
    #define HZ_PLATFORM_SUPPORTED
#else
    #error Hazel only supports Windows and Linux!
#endif

#endif //MYHAZEL_CORE_HPP
