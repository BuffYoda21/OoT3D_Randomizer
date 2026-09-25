#include "archipelago.hpp"
#include <cstring>
#include "menu.hpp"
#include "preset.hpp"

// last checked address: 0x510000
// Still need a better solution to do this since this will change pretty often
APHeader g_apHeader = {};
static std::string g_apPayload;

void ConnectAndGenerate() {
    g_apHeader.stage      = 0;
    g_apHeader.bufferSize = 0;
    g_apPayload.clear();
    g_apHeader.listening = 1;
    printf("\x1b[20;0HWaiting for proxy to send data...\n");
}

void CancelArchipelago() {
    g_apHeader.listening  = 0;
    g_apHeader.lock       = 0;
    g_apHeader.stage      = 0;
    g_apHeader.bufferSize = 0;
    memset(g_apHeader.buffer, 0, sizeof(g_apHeader.buffer));
    g_apPayload.clear();
}

void PollArchipelagoPayload() {
    if (g_apHeader.listening == 0 || g_apHeader.lock == 0)
        return;

    uint32_t payloadSize = g_apHeader.bufferSize;
    ClearDescription(); // hacky way to select the top screen

    if (payloadSize > sizeof(g_apHeader.buffer)) {
        printf("\x1b[20;0HError: Invalid AP payload size: %lu\n", static_cast<unsigned long>(payloadSize));
        return;
    }

    g_apPayload.append(g_apHeader.buffer, payloadSize);

    // printf("%s\n\n", data);
    printf("Received AP payload: %ld bytes\n", payloadSize);

    // allow proxy to write data again
    // data has been copied out of the buffer, so it's safe to delete it now
    g_apHeader.lock = 0;

    if (g_apHeader.stage == 1) {
        if (LoadPresetRaw(g_apPayload, OptionCategory::Setting))
            printf("Settings loaded successfully!\n");
        else
            printf("ERROR: Failed to load settings\n");
        g_apPayload.clear();
    }
}