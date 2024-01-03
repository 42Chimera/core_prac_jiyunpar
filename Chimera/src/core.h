#pragma once

#ifdef CM_PLATFORM_WINDOWS
    #ifdef CM_BUILD_DLL
        #define CHIMERA_API __declspec(dllexport)
    #else
        #define CHIMERA_API __declspec(dllimport)
    #endif
#else
    #define CHIMERA_API
#endif