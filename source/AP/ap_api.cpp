#include "ap_api.hpp"

#include "item_list.hpp"
#include "item_location.hpp"
#include "location_access.hpp"
#include "enemizer.hpp"
#include "playthrough.hpp"
#include "spoiler_log.hpp"
#include "random.hpp"
#include "json.hpp"

void Init() {
    ItemTable_Init();
    LocationTable_Init();
    Enemizer::InitEnemyTypes();
}

// Returns json containing serialized Options relevant to Archipelago
const char* GetAllSettings() {
    const char* json = "settings_test_string";
    return json;
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
