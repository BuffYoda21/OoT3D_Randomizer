#pragma once

#ifdef __cplusplus
    #include <cstdint>

    using s8  = std::int8_t;
    using u8  = std::uint8_t;
    using s16 = std::int16_t;
    using u16 = std::uint16_t;
    using s32 = std::int32_t;
    using u32 = std::uint32_t;
    using s64 = std::int64_t;
    using u64 = std::uint64_t;
#else
    #include <stdint.h>

    typedef int8_t  s8;
    typedef uint8_t u8;
    typedef int16_t s16;
    typedef uint16_t u16;
    typedef int32_t s32;
    typedef uint32_t u32;
    typedef int64_t s64;
    typedef uint64_t u64;
#endif

typedef float f32;
