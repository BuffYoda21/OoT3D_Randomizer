#pragma once
#include "json.hpp"
#include "settings.hpp"

using json = nlohmann::json;

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

json OptionToJson(const Option& opt);
std::string SerializeAllSettings(const std::vector<std::pair<std::string, std::vector<Option*>>>& allSettings);

#ifdef __cplusplus
}
#endif