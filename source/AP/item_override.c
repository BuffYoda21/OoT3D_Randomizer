#include "item_override.h"
#include "types.h"

static ItemOverride rItemOverrides[640] = { 0 };
static s32 rItemOverrides_Count         = 0;

ItemOverride ItemOverride_LookupByKey(ItemOverride_Key key) {
    s32 start = 0;
    s32 end   = rItemOverrides_Count - 1;
    while (start <= end) {
        s32 midIdx          = (start + end) / 2;
        ItemOverride midOvr = rItemOverrides[midIdx];
        if (key.all < midOvr.key.all) {
            end = midIdx - 1;
        } else if (key.all > midOvr.key.all) {
            start = midIdx + 1;
        } else {
            return midOvr;
        }
    }
    return (ItemOverride){ 0 };
}