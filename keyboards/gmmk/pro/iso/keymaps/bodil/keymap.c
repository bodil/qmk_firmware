/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "unicode.h"
#include "emoji.h"

enum alt_keycodes {
    // Space Cadet layer switches
    X_LMOD = SAFE_RANGE,
    X_RMOD,

    // Emoji
    EMOJI_ENUM
};

// Keybinding macros

#define XB_SHOT LSFT(LGUI(KC_S))
#define XB_EMOJ LGUI(KC_DOT)

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [0] = LAYOUT( // Base layer
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_HOME,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_APP,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        X_LMOD,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_ALGR, KC_RCTL, X_RMOD,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT( // Function keys (LMOD)
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XB_SHOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN3, KC_MS_U, KC_BTN2, _______,                   KC_END,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WSCH, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_BTN1,          _______,
        _______, KC_MENU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP, _______,
        _______, _______, _______,                            KC_MPLY,                            MO(4),   _______, MO(3),   KC_HOME, KC_PGDN, KC_END
    ),

    [2] = LAYOUT( // Unicode typography / intl (RMOD)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XB_SHOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, X_DASH,  _______, _______,          _______,
        _______, _______, _______, X_AE,    _______, X_THORN, _______, _______, _______, X_OE,    _______, X_LARR,  X_RARR,                    KC_END,
        _______, X_AA,    _______, X_ETH,   _______, _______, _______, _______, _______, X_LMBD,  _______, _______, _______, _______,          _______,
        _______, KC_MENU, _______, _______, _______, _______, _______, _______, _______, _______, X_ELLIP, _______,          _______, KC_PGUP, _______,
        MO(3),   _______, _______,                            X_NBSP,                             MO(4),   _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [3] = LAYOUT( // System functions (LMOD + RMOD)
        DEBUG,   RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UC_MOD,           DM_REC1,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   DM_REC2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_RSTP,          DM_PLY1,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, TERM_ON, DM_PLY2,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, TERM_OFF,_______
    ),

    [4] = LAYOUT( // Unicode emoji (RMOD + RAlt)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, EM_CRY,  EM_SAD,  EM_WORRY,EM_CONF, EM_OHNO, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, EM_SHUT, EM_SMILE,EM_SMIRK,EM_SHRUG,EM_WELP, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, EM_HMM,  EM_FIST, EM_THUP, EM_HEART,EM_DOG,  _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            XB_EMOJ,                            _______, _______, _______, _______, _______, _______
    ),

    // [N] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    // ),

};

// RGB Matrix

#define _____ {0, 0, 0}
#define C_MOD {0, 0, 64}  // Grey
#define C_KEY {0, 0, 192} // White
#define C_ESC {0, 255, 192}  // Red
#define C_CUR {HSV_WHITE}
#define C_L_1 {HSV_BLUE}
#define C_L_2 {HSV_GREEN}
#define C_L_3 {HSV_RED}
#define C_L_4 {HSV_YELLOW}
#define C_MUL {HSV_CHARTREUSE}
#define C_MSE {HSV_PURPLE}
#define C_MSB {HSV_MAGENTA}
#define C_FUN {HSV_TEAL}

// KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
// KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
// KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
// KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
// KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
// KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT

const uint8_t PROGMEM led_keymap[DRIVER_LED_TOTAL] = {
    0, 6, 12, 18, 23, 28, 34, 39, 44, 50, 56, 61, 66, 70,
    1, 7, 13, 19, 24, 29, 35, 40, 45, 51, 57, 62, 79, 86, 73,
    2, 8, 14, 20, 25, 30, 36, 41, 46, 52, 58, 63, 90, 76,
    3, 9, 15, 21, 26, 31, 37, 42, 47, 53, 59, 64, 95, 97, 87,
    4, 67, 10, 16, 22, 27, 32, 38, 43, 48, 54, 60, 91, 94, 83,
    5, 11, 17, 33, 49, 55, 65, 96, 98, 80,

    68, 69, 71, 72, 74, 75, 77, 78, 81, 82, 84, 85, 88, 89, 92, 93
};

// Esc  F1   F2   F3   F4   F5   F6   F7   F8   F9   F10  F11  F12  PSc
// `    1    2    3    4    5    6    7    8    9    0    -    =    BkSp      Del
// Tab  Q    W    E    R    T    Y    U    I    O    P    [    ]              PgUp
// Caps A    S    D    F    G    H    J    K    L    ;    '    \    Ent       PgDn
// LSft Nubs Z    X    C    V    B    N    M    ,    .    /         RSft Up   End
// LCtl LGui LAlt                Spc                 RAlt Fn   RCtl Left Down Right
// + 16 backlight leds
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        C_ESC, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_MOD,
        C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY,        C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY,               C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_MOD,        C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY,        C_MOD, C_CUR, C_MOD,
        C_L_1, C_MOD, C_MOD,                      C_KEY,                      C_MOD, C_MOD, C_L_2, C_CUR, C_CUR, C_CUR,

        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
        _____,                                                                                                   _____,
    },

    [1] = {
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_1,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____,
        _____, _____, _____, _____, _____, _____, _____, _____, C_MSB, C_MSB, C_MSE, C_MSB, _____,               C_L_1,
        _____, C_MUL, C_MUL, C_MUL, C_L_1, _____, _____, _____, C_MSB, C_MSE, C_MSE, C_MSE, _____, C_MSB,        _____,
        _____, C_L_1, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____, C_L_1, _____,
        _____, _____, _____,                      _____,                      C_L_4, _____, C_L_3, C_L_1, C_L_1, C_L_1,

        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
        C_L_1,                                                                                                   C_L_1,
    },

    [2] = {
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_1,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_2, _____, _____,        _____,
        _____, _____, _____, C_L_2, _____, C_L_2, _____, _____, _____, C_L_2, _____, C_L_2, C_L_2,               C_L_1,
        _____, C_L_2, _____, C_L_2, _____, _____, _____, _____, _____, C_L_2, _____, _____, _____, _____,        _____,
        _____, C_L_1, _____, _____, _____, _____, _____, _____, _____, _____, C_L_2, _____,        _____, C_L_1, _____,
        C_L_3, _____, _____,                      C_L_2,                      C_L_4, _____, C_L_2, C_L_1, C_L_1, C_L_1,

        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
        C_L_2,                                                                                                   C_L_2,
    },

    [3] = {
        C_L_3, C_L_3, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_3,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_3,        C_L_3,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,               C_L_3,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_3,        C_L_3,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____, C_L_3, C_L_3,
        C_L_3, _____, _____,                      _____,                      _____, _____, C_L_3, _____, C_L_3, _____,

        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
        C_L_3,                                                                                                   C_L_3,
    },

    [4] = {
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____,
        _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____, _____, _____,               _____,
        _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____, _____, _____, _____,        _____,
        _____, _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____,        _____, _____, _____,
        _____, _____, _____,                      C_L_4,                      C_L_4, _____, C_L_4, _____, _____, _____,

        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
        C_L_4,                                                                                                   C_L_4,
    },

    // [N] = {
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,               _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____, _____, _____,
    //     _____, _____, _____,                      _____,                      _____, _____, _____, _____, _____, _____,

    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    //     _____,                                                                                                   _____,
    // },

};

// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint32_t reset_timer;
    static bool     mod_tapped = false;
    static uint32_t mod_timer;

    if (keycode == X_LMOD || keycode == X_RMOD) {
        if (record->event.pressed) {
            mod_tapped = true;
            mod_timer  = timer_read32();
        }
    } else {
        mod_tapped = false;
    }

    // Ctrl+LAlt+RAlt (pressed in that order) sends Ctrl+Alt+Del.
    if (record->event.pressed && (keycode == KC_RALT)) {
        int mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT);
        if ((get_mods() & mods) == mods) {
            tap_code(KC_DEL);
            return false;
        }
    }

    switch (keycode) {
        // Layer switches
        case X_LMOD:
            if (record->event.pressed) {
                layer_on(1);
            } else {
                layer_off(1);
                if (mod_tapped && timer_elapsed32(mod_timer) <= TAPPING_TERM) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        SEND_STRING("{");
                    } else {
                        SEND_STRING("(");
                    }
                }
            }
            return false;
        case X_RMOD:
            if (record->event.pressed) {
                layer_on(2);
            } else {
                layer_off(2);
                if (mod_tapped && timer_elapsed32(mod_timer) <= TAPPING_TERM) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        SEND_STRING("}");
                    } else {
                        SEND_STRING(")");
                    }
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    } break;
                }
            }
            return false;

            EMOJI_SWITCH(record)
    }
    return true;  // Process all other keycodes normally
}

static bool macro_recording = false;

void dynamic_macro_record_start_user(void) { macro_recording = true; }
void dynamic_macro_record_end_user(int8_t direction) { macro_recording = false; }

void keyboard_post_init_user() {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_NONE);
}

void rgb_matrix_indicators_user() {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        return;
    }

    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_color(68, 255, 0, 0);
    rgb_matrix_set_color(69, 0, 255, 0);
    rgb_matrix_set_color(71, 0, 0, 255);
    rgb_matrix_set_color(72, 255, 0, 255);

    uint8_t layer = get_highest_layer(layer_state);
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if ((layer > 0) && (!hsv.h) && (!hsv.s) && (!hsv.v)) {
            HSV hsv_passthrough = {
                .h = pgm_read_byte(&ledmap[0][i][0]),
                .s = pgm_read_byte(&ledmap[0][i][1]),
                .v = pgm_read_byte(&ledmap[0][i][2]),
            };
            hsv = hsv_passthrough;
        }

        if (hsv.h || hsv.s || hsv.v) {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(led_keymap[i], f * rgb.r, f * rgb.g, f * rgb.b);
        } else {
            rgb_matrix_set_color(led_keymap[i], 0, 0, 0);
        }
    }

    if (macro_recording) {
        rgb_matrix_set_color(73, 0, 255, 0);
        rgb_matrix_set_color(76, 0, 255, 0);
        rgb_matrix_set_color(83, 0, 255, 0);
        rgb_matrix_set_color(87, 0, 255, 0);
    }

    if (debug_enable) {
        rgb_matrix_set_color(0, 255, 80, 0);
    }
}
