#include "archipelago.hpp"
#include <cstring>
#include "menu.hpp"
#include "preset.hpp"

// last checked address: 0x510000
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

    static char data[sizeof(g_apHeader.payload) + 1];

    memcpy(data, g_apHeader.payload, payloadSize);
    data[payloadSize] = '\0';

    // printf("%s\n\n", data);
    printf("Received AP payload: %ld bytes\n", payloadSize);

    // allow proxy to write data again
    // data has been copied out of the buffer, so it's safe to delete it now
    g_apHeader.lock = 0;

    LoadPresetRaw(data, OptionCategory::Setting);
}