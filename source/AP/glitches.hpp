#pragma once

#include <string_view>
#include <vector>

const std::vector<std::string_view> GlitchDifficulties{ "Disabled", "Novice", "Intermediate",
                                                        "Advanced", "Expert", "Hero" };

enum class GlitchType {
    RestrictedItems,
    SuperStab,
    ISG,
    BombHover,
    BombOI,
    OutdoorBombOI,
    WindmillBombOI,
    IndoorBombOI,
    DungeonBombOI,
    HoverBoost,
    SuperSlide,
    Megaflip,
    ASlide,
    HammerSlide,
    LedgeCancel,
    ActionSwap,
    QPA,
    HookshotClip,
    HookshotJump_Bonk,
    HookshotJump_Boots,
    CutsceneDive,
    NaviDive_Stick,
    TripleSlashClip,
    LedgeClip,
    SeamWalk,
};

enum class GlitchDifficulty {
    NOVICE = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT,
    HERO,
};
