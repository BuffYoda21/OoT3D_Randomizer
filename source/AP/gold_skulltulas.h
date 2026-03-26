#include "z3D.h"

typedef enum {
    GS_TIME_ALWAYS,
    GS_TIME_NIGHT,
} GsTimeCondition;

typedef enum {
    GS_AGE_ADULT,
    GS_AGE_CHILD,
    GS_AGE_BOTH,
} GsAgeCondition;

typedef struct {
    u8 arrayIndex;
    u8 bitFlag;
    s16 scene;
    s8 room;
    GsAgeCondition ageCondition;
    GsTimeCondition timeCondition;
    PosRot posRot;
} GsLocOverride;