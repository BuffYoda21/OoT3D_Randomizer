#pragma once

#include <string>

#pragma pack(push, 1)
struct APHeader {
    char identifier[8];
    uint8_t version   = 1;
    uint8_t listening = 0; // 0 = no, 1 = yes
    char slotName[17];
};
#pragma pack(pop)

extern std::string apSlotName;
extern APHeader g_apHeader;

bool ConnectAndGenerate();