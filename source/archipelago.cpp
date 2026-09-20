#include "archipelago.hpp"
#include <cstring>
#include "menu.hpp"

// Last checked commit e6f0673
// address: 0x510000
// Still need a better solution to do this since this will change pretty often
APHeader g_apHeader = {};

bool ConnectAndGenerate() {
    ClearDescription(); // clear top screen to make room for debug messages (temporary)
    g_apHeader.listening = 1;

    printf("\x1b[20;0HWaiting for proxy to send data...\n");

    return true;
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

    if (payloadSize >= sizeof(g_apHeader.payload)) {
        printf("Error: Invalid AP payload size: %lu\n", static_cast<unsigned long>(payloadSize));
        return;
    }

    static char json[sizeof(g_apHeader.payload) + 1];

    memcpy(json, g_apHeader.payload, payloadSize);
    json[payloadSize] = '\0';

    ClearDescription();
    printf("%s\n\n", json);
    printf("Received AP payload: %ld bytes\n", payloadSize);

    g_apHeader.lock = 0; // allow proxy to write data again
}