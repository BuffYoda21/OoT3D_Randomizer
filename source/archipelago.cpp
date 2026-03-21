#include "archipelago.hpp"
#include <cstring>

std::string apSlotName = "player 1";

// address: 0x4f8000
APHeader g_apHeader = {
    { 'O', 'O', 'T', '3', 'R', 'A', 'N', 'D' },
    1,
    0,
    "",
};

bool ConnectAndGenerate() {
    printf("\n\n\n\n\n\n\n\n\n\n\n"); // clear top screen to make room for debug messages (temporary)
    g_apHeader.listening = 1;

    memset(g_apHeader.slotName, 0, sizeof(g_apHeader.slotName));
    strncpy(g_apHeader.slotName, apSlotName.c_str(), 16);
    g_apHeader.slotName[16] = '\0';

    return true;
}