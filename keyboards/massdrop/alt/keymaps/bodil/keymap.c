#include QMK_KEYBOARD_H
#include "unicode.h"
#include "emoji.h"

enum alt_keycodes {
    // System
    U_T_AUTO = SAFE_RANGE,  // USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,               // USB Toggle Automatic GCR control
    DBG_TOG,                // DEBUG Toggle On / Off
    DBG_MTRX,               // DEBUG Toggle Matrix Prints
    DBG_KBD,                // DEBUG Toggle Keyboard Prints
    DBG_MOU,                // DEBUG Toggle Mouse Prints
    // MD_BOOT,               //Restart into bootloader after hold timeout

    // Space Cadet layer switches
    X_LMOD,
    X_RMOD,

    // Emoji
    EMOJI_ENUM
};

// Keybinding macros

#define XB_ENT RSFT_T(KC_ENT)
#define XB_SHOT LSFT(LGUI(KC_S))
#define XB_EMOJ LGUI(KC_DOT)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker( // Base layer
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          XB_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        X_LMOD,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, X_RMOD,  KC_LEFT, KC_DOWN, KC_RIGHT \
    ),
    [1] = LAYOUT_65_ansi_blocker( // Function keys (LMOD)
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_MUTE, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN3, KC_MS_U, KC_BTN2, _______, XB_SHOT, KC_END, \
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WSCH, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,          KC_BTN1, KC_VOLU, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            KC_MPLY,                            KC_APP,  MO(3),   KC_HOME, KC_PGDN, KC_END   \
    ),
    [2] = LAYOUT_65_ansi_blocker( // Unicode typography / intl (RMOD)
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, X_DASH,  _______, KC_PSCR, KC_MUTE, \
        _______, _______, _______, X_AE,    _______, X_THORN, _______, _______, _______, X_OE,    _______, X_LARR,  X_RARR,  XB_SHOT, KC_END, \
        _______, X_AA,    _______, X_ETH,   _______, _______, _______, _______, _______, X_LMBD,  _______, KC_PIPE,          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, X_ELLIP, _______, _______,          KC_PGUP, KC_VOLD, \
        MO(3),   _______, _______,                            X_NBSP,                             MO(4),   _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [3] = LAYOUT_65_ansi_blocker( // System functions (LMOD + RMOD)
        DBG_TOG, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  RESET,   RGB_TOG, \
        _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, UC_MOD,  TERM_ON, \
        _______, _______, _______, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______,          DM_RSTP, TERM_OFF, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          DM_REC1, DM_REC2, \
        _______, _______, _______,                            _______,                            _______, _______, _______, DM_PLY1, DM_PLY2  \
    ),
    [4] = LAYOUT_65_ansi_blocker( // Unicode emoji (RMOD + RAlt)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, EM_CRY,  EM_SAD,  EM_WORRY,EM_CONF, EM_OHNO, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, EM_SHUT, EM_SMILE,EM_SMIRK,EM_SHRUG,EM_WELP, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, EM_HMM,  EM_FIST, EM_THUP, EM_HEART,EM_DOG,  _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            XB_EMOJ,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
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

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        C_ESC, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_MOD, C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY,        C_MOD, C_MOD,
        C_MOD, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_KEY, C_MOD,        C_CUR, C_MOD,
        C_L_1, C_MOD, C_MOD,                      C_KEY,                      C_MOD, C_L_2, C_CUR, C_CUR, C_CUR,
        // Underglow
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
        _____,                                                                                            _____,
        _____,                                                                                            _____,
        _____,                                                                                            _____,
        _____,                                                                                            _____,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
    },
    [1] = {
        C_L_1, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_L_1, C_MUL,
        _____, _____, _____, _____, _____, _____, _____, _____, C_MSB, C_MSB, C_MSE, C_MSB, _____, C_L_1, C_L_1,
        _____, C_MUL, C_MUL, C_MUL, C_L_1, _____, _____, _____, C_MSB, C_MSE, C_MSE, C_MSE,        C_MSB, C_MUL,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        C_L_1, C_MUL,
        C_L_1, _____, _____,                      C_MUL,                      C_L_1, C_L_3, C_L_1, C_L_1, C_L_1,
        // Underglow
        C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1,
        C_L_1,                                                                                            C_L_1,
        C_L_1,                                                                                            C_L_1,
        C_L_1,                                                                                            C_L_1,
        C_L_1,                                                                                            C_L_1,
        C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1, C_L_1
    },
    [2] = {
        C_L_1, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_2, _____, C_L_1, C_MUL,
        _____, _____, _____, C_L_2, _____, C_L_2, _____, _____, _____, C_L_2, _____, C_L_2, C_L_2, C_L_1, C_L_1,
        _____, C_L_2, _____, C_L_2, _____, _____, _____, _____, _____, C_L_2, _____, C_L_2,        _____, C_MUL,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, C_L_2, _____, _____,        C_L_1, C_MUL,
        C_L_3, _____, _____,                      C_L_2,                      C_L_4, C_L_2, C_L_1, C_L_1, C_L_1,
        // Underglow
        C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2,
        C_L_2,                                                                                            C_L_2,
        C_L_2,                                                                                            C_L_2,
        C_L_2,                                                                                            C_L_2,
        C_L_2,                                                                                            C_L_2,
        C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2, C_L_2
    },
    [3] = {
        C_L_3, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_FUN, C_L_3, C_L_3,
        _____, C_L_3, C_L_3, _____, _____, _____, _____, _____, _____, _____, _____, C_L_3, C_L_3, C_L_3, C_L_3,
        _____, _____, _____, C_L_3, _____, _____, _____, _____, _____, _____, _____, _____,        C_L_3, C_L_3,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        C_L_3, C_L_3,
        C_L_3, _____, _____,                      _____,                      _____, C_L_3, _____, C_L_3, C_L_3,
        // Underglow
        C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3,
        C_L_3,                                                                                            C_L_3,
        C_L_3,                                                                                            C_L_3,
        C_L_3,                                                                                            C_L_3,
        C_L_3,                                                                                            C_L_3,
        C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3, C_L_3
    },
    [4] = {
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
        _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____, _____, _____, _____, _____,
        _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____, _____,        _____, _____,
        _____, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, _____, _____, _____, _____, _____, _____,        _____, _____,
        _____, _____, _____,                      C_L_4,                      C_L_4, C_L_4, _____, _____, _____,
        // Underglow
        C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4,
        C_L_4,                                                                                            C_L_4,
        C_L_4,                                                                                            C_L_4,
        C_L_4,                                                                                            C_L_4,
        C_L_4,                                                                                            C_L_4,
        C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4, C_L_4
    }
    // [x] = {
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____, _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,        _____, _____,
    //     _____, _____, _____,                      _____,                      _____, _____, _____, _____, _____,
    //     // Underglow
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    //     _____,                                                                                            _____,
    //     _____,                                                                                            _____,
    //     _____,                                                                                            _____,
    //     _____,                                                                                            _____,
    //     _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
    // }
};

// clang-format on

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

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
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        // case MD_BOOT:
        //     if (record->event.pressed) {
        //         reset_timer = timer_read32();
        //     } else {
        //         if (timer_elapsed32(reset_timer) >= 500) {
        //             reset_keyboard();
        //         }
        //     }
        //     return false;
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

            EMOJI_SWITCH(record)
    }
    return true;
}

static bool macro_recording = false;

void dynamic_macro_record_start_user(void) { macro_recording = true; }
void dynamic_macro_record_end_user(int8_t direction) { macro_recording = false; }

void keyboard_post_init_user() { rgb_matrix_enable(); }

void rgb_matrix_indicators_user() {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        return;
    }

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
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }

    if (macro_recording) {
        rgb_matrix_set_color(80, 0, 255, 0);
    }

    if (debug_enable) {
        rgb_matrix_set_color(68, 255, 80, 0);
    }
}
