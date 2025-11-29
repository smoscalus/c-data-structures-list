#pragma once

#ifdef _WIN32
    #ifdef BUILDING_DLL
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#else
    #define API
#endif