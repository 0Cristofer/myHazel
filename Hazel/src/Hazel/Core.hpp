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
#else
    #error Hazel only supports Windows!
#endif

#endif //MYHAZEL_CORE_HPP
