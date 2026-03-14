#pragma once

#include <string>

struct APSettings {
    std::string url  = "archipelago.gg";
    int port         = 12345;
    std::string slot = "player 1";
    std::string password;
};

extern APSettings apSettings;

void ConnectAndGenerate();