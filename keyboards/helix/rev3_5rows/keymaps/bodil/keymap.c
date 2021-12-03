/* Copyright 2020 yushakobo
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
#include "unicode.h"
#include "emoji.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names { _QWERTY = 0, _SYMBOL, _UNICODE, _SYSTEM };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { ADJUST = SAFE_RANGE, EMOJI_ENUM };

#define LOWER MO(_SYMBOL)
#define RAISE MO(_UNICODE)
#define SYSRQ MO(_SYSTEM)

const rgblight_segment_t PROGMEM symbol_layer[]  = RGBLIGHT_LAYER_SEGMENTS({25, 7, HSV_BLUE}, {57, 7, HSV_BLUE});
const rgblight_segment_t PROGMEM unicode_layer[] = RGBLIGHT_LAYER_SEGMENTS({25, 7, HSV_GREEN}, {57, 7, HSV_GREEN});
const rgblight_segment_t PROGMEM system_layer[]  = RGBLIGHT_LAYER_SEGMENTS({25, 7, HSV_RED}, {57, 7, HSV_RED});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(symbol_layer, unicode_layer, system_layer);

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc/~|   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   =  |   -  |   N  |   M  |   ,  |   .  |  Up  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Symbol| GUI  | Alt  |AltGr |System|Ucode |Space |Space |   /  |Symbol|Ucode | Left | Down |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT, \
      LOWER,   KC_LGUI, KC_LALT, KC_RALT, SYSRQ,  RAISE,    KC_SPC,  KC_SPC,  KC_SLSH, LOWER,   RAISE,   KC_LEFT, KC_DOWN, KC_RIGHT \
    ),

  /* Symbol
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | F1   | F2   | F3   | F4   | F5   | F6   |             | F7   | F8   | F9   | F10  | F11  | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Home |  Up  | End  |      |      |             |PrtSc |   {  |   }  |   [  |   ]  |  `   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Left | Down |Right |      |      |             |      |   _  |   -  |   +  |   =  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |  [   |   ]  |   |  |   \  |      |      | PgUp |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      | Home | PgDn | End  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_SYMBOL] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
      _______, KC_HOME, KC_UP,   KC_END,  _______, _______,                   KC_PSCR, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,  \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  _______, \
      _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS, _______, _______, KC_PGUP, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END   \
      ),

  /* Unicode
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | 😢  | 😔  | 😟  | 😕   | 😮  | 😑  |             | 😊  | 😏  | 🤷🏻‍♀️   | 😳   | 🤔  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | ✊   | 👍  | ❤️  |   Æ  | 🐶  |   Þ  |             |      |      |      |   Ø  |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   Å  |      |   Ð  |      |      |             |      |      |  —  |   Λ  |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  —  |      |      |      |   …  |  ↑   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | NbSp | NbSp |     |      |       |  ←  |  ↓   |  →  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_UNICODE] = LAYOUT( \
      EM_CRY,  EM_SAD,  EM_WORRY,EM_CONF, EM_OHNO, EM_SHUT,                   EM_SMILE,EM_SMIRK,EM_SHRUG,EM_WELP, EM_HMM,  KC_DEL,  \
      EM_FIST, EM_THUP, EM_HEART,X_AE,    EM_DOG,  X_THORN,                   _______, _______, _______, X_OE,    _______, _______, \
      _______, X_AA,    _______, X_ETH,   _______, _______,                   _______, _______, X_DASH,  X_LMBD,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, X_DASH,  _______, _______, _______, X_ELLIP, X_UARR,  _______, \
      _______, _______, _______, _______, _______, _______, X_NBSP,  X_NBSP,  _______, _______, _______, X_LARR,  X_DARR,  X_RARR  \
      ),

  /* System (Symbol + Unicode)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | F13  | F14  | F15  | F16  | F17  | F18  |             | F19  | F20  | F21  | F22  | F23  | F24  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |UCMod |Reset |EEPRST|      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |Debug |      |      |             |      |      |      |      |      |DMStop|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |DMRec1|DMRec2|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |DMPly1|DMPly2|      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_SYSTEM] =  LAYOUT( \
      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                    KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, \
      UC_MOD,  RESET,   EEP_RST, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, DEBUG,   _______, _______,                   _______, _______, _______, _______, _______, DM_RSTP, \
      _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, DM_PLY1, DM_PLY2, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      )

};

// clang-format on

void keyboard_post_init_user() {
    rgblight_disable();
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // state = update_tri_layer_state(state, _SYMBOL, _UNICODE, _SYSTEM);
    rgblight_set_layer_state(0, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(1, layer_state_cmp(state, _UNICODE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYSTEM));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_SYMBOL);
                layer_on(_UNICODE);
            } else {
                layer_off(_SYMBOL);
                layer_off(_UNICODE);
            }
            break;

            EMOJI_SWITCH(record)
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
