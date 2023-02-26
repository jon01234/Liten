// ! THIS SHOULD NOT BE IMPORTED BY CLIENT

#ifndef CORE_H
#define CORE_H

#ifdef LIT_PLATFORM_LINUX
    #ifdef LIT_BUILD_DLL
        #define LIT_API __attribute__((visibility("default")))
    #else
        #define LIT_API
    #endif //LIT_BUILD_DLL 
#elif LIT_PLATFORM_WINDOWS
    #ifdef LIT_BUILD_DLL
        #define LIT_API __declspec(dllexport)
    #else
        #define LIT_API __declspec(dllimport)
    #endif // LIT_BUILD_DLL
#else
    #error  Please define LIT_PLATFORM_
#endif // LIT_PLATFORM_LINUX 

#endif // !CORE_H
