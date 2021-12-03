#include QMK_KEYBOARD_H
#include "unicode.h"

const uint32_t PROGMEM unicode_map[] = {
    [MDASH] = 0x2014,
    [NDASH] = 0x2013,
    [ELLIP] = 0x2026,
    [NBSP] = 0x00A0,
    [R_ARR] = 0x2192,
    [L_ARR] = 0x2190,
    [U_ARR] = 0x2191,
    [D_ARR] = 0x2193,
    [R_DAR] = 0x21D2,
    [L_DAR] = 0x21D0,
    [U_DAR] = 0x21D1,
    [D_DAR] = 0x21D3,
    [L_LAMBDA] = 0x03BB,
    [U_LAMBDA] = 0x039B,
    [L_THORN] = 0xFE,
    [U_THORN] = 0xDE,
    [L_ETH] = 0xF0,
    [U_ETH] = 0xD0,
    [L_AA] = 0xE5,
    [U_AA] = 0xC5,
    [L_AE] = 0xE6,
    [U_AE] = 0xC6,
    [L_OE] = 0xF8,
    [U_OE] = 0xD8,
};
