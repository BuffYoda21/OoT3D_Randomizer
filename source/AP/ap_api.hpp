#pragma once

#ifdef _WIN32
    #define API_EXPORT __declspec(dllexport)
#else
    #define API_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

API_EXPORT void Init();
API_EXPORT const char* GetAllSettings();
API_EXPORT bool ParseSettings(const char* json);
API_EXPORT const char* GetLocationPool();
API_EXPORT const char* GetItemPool();

#ifdef __cplusplus
}
#endif