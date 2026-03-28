#include "ap_api.hpp"

#include "item_list.hpp"
#include "item_location.hpp"
#include "location_access.hpp"
#include "enemizer.hpp"
#include "playthrough.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
#include "random.hpp"
#include "json.hpp"

using json = nlohmann::json;

void Init() {
    ItemTable_Init();
    LocationTable_Init();
    Enemizer::InitEnemyTypes();
}

// Returns json containing serialized Options relevant to Archipelago
const char* GetAllSettings() {
    std::string json;
    std::vector<std::pair<std::string, std::vector<Option*>>> allSettings = Settings::GetApSettings();
    json                                                                  = SerializeAllSettings(allSettings);
    return json.c_str();
}

// Parses selected options from Archipelago and applies them to settings
bool ParseSettings(const char* json) {
    return true;
}

// Returns json containing serialized ItemLocations to be randomized based on parsed settings
const char* GetLocationPool() {
    const char* json;
    return json;
}

// Retruns json containing serialized Items to be randomized based on parsed settings
const char* GetItemPool() {
    const char* json;
    return json;
}

// Helper to serialize Option
json OptionToJson(const Option& opt) {
    return json{
        { "name", opt.GetName() },
        { "options", opt.GetOptions() },
        // string_view isn't directly serializable
        { "optionDescriptions",
          std::vector<std::string>(opt.GetAllOptionDescriptions().begin(), opt.GetAllOptionDescriptions().end()) },
        { "defaultOption", opt.GetDefaultOptionIndex() },
    };
}

std::string SerializeAllSettings(const std::vector<std::pair<std::string, std::vector<Option*>>>& allSettings) {
    json j = json::array();

    for (const auto& [groupName, optionPtrs] : allSettings) {
        json group;
        group["group"]    = groupName;
        group["settings"] = json::array();

        for (const Option* opt : optionPtrs) {
            group["settings"].push_back(OptionToJson(*opt));
        }

        j.push_back(group);
    }

    return j.dump();
}