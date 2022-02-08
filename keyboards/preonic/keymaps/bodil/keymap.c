/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "unicode.h"
#include "emoji.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names { _QWERTY = 0, _SYMBOL, _UNICODE, _FUNCTION, _SYSTEM, _COMPOSE };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { ADJUST = SAFE_RANGE, EMOJI_ENUM };

#define RAISE MO(_SYMBOL)
#define LOWER MO(_UNICODE)
#define FN MO(_FUNCTION)
#define SYSRQ MO(_SYSTEM)
#define COMPOSE MO(_COMPOSE)

const rgblight_segment_t PROGMEM symbol_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_GREEN});
const rgblight_segment_t PROGMEM unicode_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_YELLOW});
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_BLUE});
const rgblight_segment_t PROGMEM system_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_RED});
const rgblight_segment_t PROGMEM compose_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_PURPLE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(symbol_layer, unicode_layer, function_layer, system_layer, compose_layer);

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |Esc/~ |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Win  | Alt  |Lower |   \  |    Space    |  /   |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
  FN,      KC_LGUI, KC_LALT, LOWER,   KC_BSLS, KC_SPC,  KC_SPC,  KC_SLSH, RAISE,   KC_LEFT, KC_DOWN, KC_RGHT
),

/* Symbol layer (raise)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home |  Up  | End  |      |      |      |   [  |   ]  |   {  |   }  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |      |   _  |   -  |   +  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   <  |   >  | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   -  |             |   =  |      | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_PGUP, _______,
  _______, _______, _______, _______, KC_MINS, _______, _______, KC_EQL,  _______, KC_HOME, KC_PGDN, KC_END
),

/* Unicode layer (lower)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |  £/€ |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Leader|      |      |   Æ  |      |   Þ  |      |      |      |   Ø  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Cmpose|   Å  |   ẞ  |   Ð  |      |      |      |      |  —  |   Λ  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   Ñ  |      |      |   …  |   ↑  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     NbSp    |      |      |  ←  |  ↓   |  →  |
 * `-----------------------------------------------------------------------------------'
 */
[_UNICODE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, X_CASH,  _______, _______, _______, _______, _______, _______, KC_DEL,
  KC_LEAD, _______, _______, X_AE,    _______, X_THORN, _______, _______, _______, X_OE,    _______, _______,
  COMPOSE, X_AA,    X_SS,    X_ETH,   _______, _______, _______, _______, X_DASH,  X_LMBD,  _______, _______,
  _______, _______, _______, _______, _______, _______, X_ENE,   _______, _______, X_ELLIP, X_UARR,  _______,
  _______, _______, _______, _______, _______, X_NBSP,  X_NBSP,  _______, _______, X_LARR,  X_DARR,  X_RARR
),

/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MBtn1 |MouseU|MBtn2 |WheelU|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MouseL|MouseD|MouseR|WheelD|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MBtn3 |WheelL|WheelR|      |      |      |      |      | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Play/Pause  |      |      | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN3, KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______, KC_PGUP, _______,
  _______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, KC_HOME, KC_PGDN, KC_END
),

/* System layer (raise+lower—command keys are enabled when this layer is active)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |UCMod |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYSTEM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  UC_MOD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Compose layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   ˜  |      |   ¨  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ´  |      |   ¸  |      |   `  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   ^  |      |      |      |   ¯  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COMPOSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, XC_TILD, _______, XC_UML,  _______, _______, _______, _______,
  _______, XC_ACUT, _______, XC_CEDI, _______, XC_GRAV, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, XC_CIRC, _______, _______, _______, XC_MACR, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

// /* New layer
//  * ,-----------------------------------------------------------------------------------.
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_NEW] = LAYOUT_preonic_grid(
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

};

// clang-format on

void keyboard_post_init_user() {
    rgblight_disable();
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL, _UNICODE, _SYSTEM);
    rgblight_set_layer_state(0, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(1, layer_state_cmp(state, _UNICODE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYSTEM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _COMPOSE));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) { EMOJI_SWITCH(record) }
    return true;
};

#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(ONE_UP_SOUND);
#endif

LEADER_EXTERNS();

void leader_start() {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

#define SEQ_SINGLE_ACCENT(keycode, acc_code, upper, lower) \
    SEQ_TWO_KEYS(keycode, acc_code) { send_unicode_string((get_mods() & MOD_MASK_SHIFT) ? upper : lower); }

#define SEQ_ACCENT(keycode, u_acute, l_acute, u_grave, l_grave, u_circ, l_circ, u_uml, l_uml, u_mac, l_mac) \
    SEQ_SINGLE_ACCENT(keycode, KC_A, u_acute, l_acute)                                                      \
    SEQ_SINGLE_ACCENT(keycode, KC_G, u_grave, l_grave)                                                      \
    SEQ_SINGLE_ACCENT(keycode, KC_C, u_circ, l_circ)                                                        \
    SEQ_SINGLE_ACCENT(keycode, KC_U, u_uml, l_uml)                                                          \
    SEQ_SINGLE_ACCENT(keycode, KC_M, u_mac, l_mac)

void matrix_scan_user() {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Vowels with acute KC_A, grave KC_G, circumflex KC_C, diaeresis/umlaut KC_U, macron KC_M
        SEQ_ACCENT(KC_A, "Á", "á", "À", "à", "Â", "â", "Ä", "ä", "Ā", "ā")
        SEQ_ACCENT(KC_E, "É", "é", "È", "è", "Ê", "ê", "Ë", "ë", "Ē", "ē")
        SEQ_ACCENT(KC_I, "Í", "í", "Ì", "ì", "Î", "î", "Ï", "ï", "Ī", "ī")
        SEQ_ACCENT(KC_O, "Ó", "ó", "Ò", "ò", "Ô", "ô", "Ö", "Ö", "Ō", "ō")
        SEQ_ACCENT(KC_U, "Ú", "ú", "Ù", "ù", "Û", "û", "Ü", "ü", "Ū", "ū")

        // Y with acute, circumflex, diaeresis, macron with accent keys as above
        SEQ_SINGLE_ACCENT(KC_Y, KC_A, "Ý", "ý")
        SEQ_SINGLE_ACCENT(KC_Y, KC_C, "Ŷ", "ŷ")
        SEQ_SINGLE_ACCENT(KC_Y, KC_U, "Ÿ", "ÿ")
        SEQ_SINGLE_ACCENT(KC_Y, KC_M, "Ȳ", "ȳ")

        // &aring;
        SEQ_SINGLE_ACCENT(KC_A, KC_R, "Å", "å")

        // C with cedilla
        SEQ_SINGLE_ACCENT(KC_C, KC_C, "Ç", "ç")

        // N with tilde
        SEQ_SINGLE_ACCENT(KC_N, KC_T, "Ñ", "ñ")

        // Sharp S
        SEQ_SINGLE_ACCENT(KC_S, KC_S, "ẞ", "ß")

        // L with stroke
        SEQ_SINGLE_ACCENT(KC_L, KC_S, "Ł", "ł")
    }
}
