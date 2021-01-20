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
    #define DEBUG_BREAK  __debugbreak();
    #define HZ_PLATFORM_SUPPORTED
#elif HZ_PLATFORM_LINUX
    #define HAZEL_API
    #define HZ_PLATFORM_SUPPORTED
    #define DEBUG_BREAK assert(false)
#else
    #error Hazel only supports Windows and Linux!
#endif

#ifdef HZ_DEBUG
    #define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
    #define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#else
    #define HZ_ASSERT(x, ...)
    #define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#endif //MYHAZEL_CORE_HPP
