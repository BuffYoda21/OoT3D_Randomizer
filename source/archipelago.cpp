#include "archipelago.hpp"
#include <cstring>
#include "menu.hpp"

// last checked address: 0x50f000
// Still need a better solution to do this since this will change pretty often
APHeader g_apHeader = {};

void ConnectAndGenerate() {
    g_apHeader.listening = 1;
    printf("\x1b[20;0HWaiting for proxy to send data...\n");
}

void CancelArchipelago() {
    g_apHeader.listening   = 0;
    g_apHeader.lock        = 0;
    g_apHeader.payloadSize = 0;
    memset(g_apHeader.payload, 0, sizeof(g_apHeader.payload));
}

void PollArchipelagoPayload() {
    if (g_apHeader.listening == 0 || g_apHeader.lock == 0)
        return;

    uint32_t payloadSize = g_apHeader.payloadSize;
    ClearDescription(); // hacky way to select the top screen

    if (payloadSize >= sizeof(g_apHeader.payload)) {
        printf("\x1b[20;0HError: Invalid AP payload size: %lu\n", static_cast<unsigned long>(payloadSize));
        return;
    }

    static char json[sizeof(g_apHeader.payload) + 1];

    memcpy(json, g_apHeader.payload, payloadSize);
    json[payloadSize] = '\0';

    // printf("%s\n\n", json);
    printf("\x1b[20;0HReceived AP payload: %ld bytes\n", payloadSize);

    g_apHeader.lock = 0; // allow proxy to write data again
}

void ParseSlotData(const char* json) {
}