// #include "../code/include/z3D/z3Dscene.h"
#include "z3D.h"

extern "C" {

const char* sceneNames[SCENE_MAX] = {
    "Deku Tree",                               // SCENE_DEKU_TREE
    "Dodongo's Cavern",                        // SCENE_DODONGOS_CAVERN
    "Jabu Jabu's Belly",                       // SCENE_JABU_JABU
    "Forest Temple",                           // SCENE_FOREST_TEMPLE
    "Fire Temple",                             // SCENE_FIRE_TEMPLE
    "Water Temple",                            // SCENE_WATER_TEMPLE
    "Spirit Temple",                           // SCENE_SPIRIT_TEMPLE
    "Shadow Temple",                           // SCENE_SHADOW_TEMPLE
    "Bottom of the Well",                      // SCENE_BOTTOM_OF_THE_WELL
    "Ice Cavern",                              // SCENE_ICE_CAVERN
    "Ganon's Tower",                           // SCENE_GANONS_TOWER
    "Gerudo Training Grounds",                 // SCENE_GERUDO_TRAINING_GROUNDS
    "Thieves' Hideout",                        // SCENE_THIEVES_HIDEOUT
    "Inside Ganon's Castle",                   // SCENE_INSIDE_GANONS_CASTLE
    "Ganon's Tower (Collapsing)",              // SCENE_GANONS_TOWER_COLLAPSE_INTERIOR
    "Treasure Chest Shop",                     // SCENE_TREASURE_BOX_SHOP
    "Queen Gohma's Lair",                      // SCENE_DEKU_TREE_BOSS
    "King Dodongo's Lair",                     // SCENE_DODONGOS_CAVERN_BOSS
    "Barinade's Lair",                         // SCENE_JABU_JABU_BOSS
    "Phantom Ganon's Lair",                    // SCENE_FOREST_TEMPLE_BOSS
    "Volvagia's Lair",                         // SCENE_FIRE_TEMPLE_BOSS
    "Morpha's Lair",                           // SCENE_WATER_TEMPLE_BOSS
    "Twinrova's Lair",                         // SCENE_SPIRIT_TEMPLE_BOSS
    "Bongo Bongo's Lair",                      // SCENE_SHADOW_TEMPLE_BOSS
    "Ganondorf's Lair",                        // SCENE_GANONDORF_BOSS
    "Ganon's Tower Exterior (Collapsing)",     // SCENE_GANONS_TOWER_COLLAPSE_EXTERIOR
    "Market Entrance (Child - Day)",           // SCENE_MARKET_ENTRANCE_DAY
    "Market Entrance (Child - Night)",         // SCENE_MARKET_ENTRANCE_NIGHT
    "Market Entrance (Ruins)",                 // SCENE_MARKET_ENTRANCE_RUINS
    "Back Alley (Child - Day)",                // SCENE_BACK_ALLEY_DAY
    "Back Alley (Child - Night)",              // SCENE_BACK_ALLEY_NIGHT
    "Market (Child - Day)",                    // SCENE_MARKET_DAY
    "Market (Child - Night)",                  // SCENE_MARKET_NIGHT
    "Market (Ruins)",                          // SCENE_MARKET_RUINS
    "Temple of Time Exterior (Child - Day)",   // SCENE_TEMPLE_OF_TIME_EXTERIOR_DAY
    "Temple of Time Exterior (Child - Night)", // SCENE_TEMPLE_OF_TIME_EXTERIOR_NIGHT
    "Temple of Time Exterior (Ruins)",         // SCENE_TEMPLE_OF_TIME_EXTERIOR_RUINS
    "Know-It-All Brothers' House",             // SCENE_KNOW_IT_ALL_BROS_HOUSE
    "House of Twins",                          // SCENE_TWINS_HOUSE
    "Mido's House",                            // SCENE_MIDOS_HOUSE
    "Saria's House",                           // SCENE_SARIAS_HOUSE
    "Carpenter Boss's House",                  // SCENE_KAKARIKO_CENTER_GUEST_HOUSE
    "Back Alley House (Man in Green)",         // SCENE_BACK_ALLEY_HOUSE
    "Bazaar",                                  // SCENE_BAZAAR
    "Kokiri Shop",                             // SCENE_KOKIRI_SHOP
    "Goron Shop",                              // SCENE_GORON_SHOP
    "Zora Shop",                               // SCENE_ZORA_SHOP
    "Kakariko Potion Shop",                    // SCENE_POTION_SHOP_KAKARIKO
    "Market Potion Shop",                      // SCENE_POTION_SHOP_MARKET
    "Bombchu Shop",                            // SCENE_BOMBCHU_SHOP
    "Happy Mask Shop",                         // SCENE_HAPPY_MASK_SHOP
    "Link's House",                            // SCENE_LINKS_HOUSE
    "Back Alley House (Dog Lady)",             // SCENE_DOG_LADY_HOUSE
    "Stable",                                  // SCENE_STABLE
    "Impa's House",                            // SCENE_IMPAS_HOUSE
    "Lakeside Laboratory",                     // SCENE_LAKESIDE_LABORATORY
    "Carpenters' Tent",                        // SCENE_CARPENTERS_TENT
    "Gravekeeper's Hut",                       // SCENE_GRAVEKEEPERS_HUT
    "Great Fairy's Fountain (Upgrades)",       // SCENE_GREAT_FAIRYS_FOUNTAIN_MAGIC
    "Fairy's Fountain",                        // SCENE_FAIRYS_FOUNTAIN
    "Great Fairy's Fountain (Spells)",         // SCENE_GREAT_FAIRYS_FOUNTAIN_SPELLS
    "Grottos",                                 // SCENE_GROTTOS
    "Grave (Redead)",                          // SCENE_REDEAD_GRAVE
    "Grave (Fairy's Fountain)",                // SCENE_GRAVE_WITH_FAIRYS_FOUNTAIN
    "Royal Family's Tomb",                     // SCENE_ROYAL_FAMILYS_TOMB
    "Shooting Gallery",                        // SCENE_SHOOTING_GALLERY
    "Temple of Time",                          // SCENE_TEMPLE_OF_TIME
    "Chamber of the Sages",                    // SCENE_CHAMBER_OF_THE_SAGES
    "Castle Hedge Maze (Day)",                 // SCENE_CASTLE_COURTYARD_GUARDS_DAY
    "Castle Hedge Maze (Night)",               // SCENE_CASTLE_COURTYARD_GUARDS_NIGHT
    "Cutscene Map",                            // SCENE_CUTSCENE_MAP
    "Dampé's Grave / Windmill",                // SCENE_WINDMILL_AND_DAMPES_GRAVE
    "Fishing Pond",                            // SCENE_FISHING_POND
    "Castle Courtyard",                        // SCENE_CASTLE_COURTYARD_ZELDA
    "Bombchu Bowling Alley",                   // SCENE_BOMBCHU_BOWLING_ALLEY
    "Ranch Buildings",                         // SCENE_LON_LON_BUILDINGS
    "Guard House",                             // SCENE_MARKET_GUARD_HOUSE
    "Granny's Potion Shop",                    // SCENE_POTION_SHOP_GRANNY
    "Ganon's Battle Arena",                    // SCENE_GANON_BOSS
    "House of Skulltula",                      // SCENE_HOUSE_OF_SKULLTULA
    "Hyrule Field",                            // SCENE_HYRULE_FIELD
    "Kakariko Village",                        // SCENE_KAKARIKO_VILLAGE
    "Graveyard",                               // SCENE_GRAVEYARD
    "Zora's River",                            // SCENE_ZORAS_RIVER
    "Kokiri Forest",                           // SCENE_KOKIRI_FOREST
    "Sacred Forest Meadow",                    // SCENE_SACRED_FOREST_MEADOW
    "Lake Hylia",                              // SCENE_LAKE_HYLIA
    "Zora's Domain",                           // SCENE_ZORAS_DOMAIN
    "Zora's Fountain",                         // SCENE_ZORAS_FOUNTAIN
    "Gerudo Valley",                           // SCENE_GERUDO_VALLEY
    "Lost Woods",                              // SCENE_LOST_WOODS
    "Desert Colossus",                         // SCENE_DESERT_COLOSSUS
    "Gerudo's Fortress",                       // SCENE_GERUDOS_FORTRESS
    "Haunted Wasteland",                       // SCENE_HAUNTED_WASTELAND
    "Hyrule Castle",                           // SCENE_HYRULE_CASTLE
    "Death Mountain Trail",                    // SCENE_DEATH_MOUNTAIN_TRAIL
    "Death Mountain Crater",                   // SCENE_DEATH_MOUNTAIN_CRATER
    "Goron City",                              // SCENE_GORON_CITY
    "Lon Lon Ranch",                           // SCENE_LON_LON_RANCH
    "Outside Ganon's Castle",                  // SCENE_OUTSIDE_GANONS_CASTLE
    "",                                        // SCENE_65
    "",                                        // SCENE_66
    "",                                        // SCENE_67
    "",                                        // SCENE_68
    "",                                        // SCENE_69
    "",                                        // SCENE_6A
    "",                                        // SCENE_HYRULE_FIELD_TITLE_SCREEN
};

} // extern "C"
