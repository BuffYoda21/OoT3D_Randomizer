#include "types.h"

enum ItemOverride_Type {
    OVR_BASE_ITEM    = 0,
    OVR_CHEST        = 1,
    OVR_COLLECTABLE  = 2,
    OVR_SKULL        = 3,
    OVR_GROTTO_SCRUB = 4,
    OVR_DELAYED      = 5,
    OVR_TEMPLE       = 6,
};

typedef union ItemOverride_Key {
    u32 all;
    struct {
        char pad_;
        u8 scene;
        u8 type;
        u8 flag;
    };
} ItemOverride_Key;

typedef union ItemOverride_Value {
    u32 all;
    struct {
        u16 itemId;
        u8 player;
        u8 looksLikeItemId;
    };
} ItemOverride_Value;

typedef struct ItemOverride {
    ItemOverride_Key key;
    ItemOverride_Value value;
} ItemOverride;

ItemOverride ItemOverride_LookupByKey(ItemOverride_Key key);
