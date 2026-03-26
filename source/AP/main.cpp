// #include <3ds.h>

// #include "menu.hpp"
// #include "hint_list.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "location_access.hpp"
// #include "music.hpp"
#include "enemizer.hpp"
#include "playthrough.hpp"
#include "spoiler_log.hpp"
#include "random.hpp"

int main(int argc, char* argv[]) {
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--seed") {
            Settings::seed = std::string(argv[i + 1]);
            i++;
        }
    }

    printf("\n");

    // If no seed was given, generate one
    if (Settings::seed.empty()) {
        Settings::seed = GetRandomSeed();
    } else if (Settings::seed.rfind("seed_testing_count", 0) == 0) {
        const int count = std::stoi(Settings::seed.substr(18), nullptr);
        Playthrough::Playthrough_Repeat(count);
        return 0;
    }

    InitLogDirectories();

    // Initialize
    printf("Initializing...");
    ItemTable_Init();
    LocationTable_Init();
    Enemizer::InitEnemyTypes();
    printf("Done\n");

    // All that other randomzier stuff
    int ret = Playthrough::Playthrough_Init(std::hash<std::string>{}(Settings::seed));
    if (ret < 0) {
        if (ret == -1) { // Failed to generate after 5 tries
            printf("\n\nFailed to generate after 5 tries.\nPress B to go back to the menu.\nA different seed might be "
                   "successful.");
            PlacementLog_Msg("\nRANDOMIZATION FAILED COMPLETELY. PLZ FIX\n");
            PlacementLog_Write();
        } else {
            printf("\n\nError %d with fill.\nPress Select to exit or B to go back to the menu.\n", ret);
        }
        return 0;
    }

    printf("\nGeneration Successful!\n");

    return 0;
}
