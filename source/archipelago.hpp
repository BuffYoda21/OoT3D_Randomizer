#pragma once

#include <string>

#pragma pack(push, 1)
struct APHeader {
    char identifier[8]      = { 'O', 'O', 'T', '3', 'R', 'A', 'N', 'D' };
    uint8_t version         = 4;
    uint8_t listening       = 0; // 0 = no, 1 = yes
    uint8_t lock            = 0; // 0 = safe for proxy to write, 1 = safe for client to read
    uint8_t stage           = 0; // 0 = slot data, 1 = item->location mapping
    uint32_t payloadSize    = 0;
    char payload[64 * 1024] = {};
};
#pragma pack(pop)

extern APHeader g_apHeader;

void ConnectAndGenerate();
void CancelArchipelago();
void PollArchipelagoPayload();