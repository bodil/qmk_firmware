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

// Defines names for use in layer keycodes and the keymap
enum layer_names { _LEFT = 0, _RIGHT, _SYMBOL, _FUNCTION };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { ADJUST = SAFE_RANGE };

#define LOWER TT(_SYMBOL)
#define RAISE TT(_RIGHT)
#define FN TT(_FUNCTION)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   * ,-----------------------------------------.
   * | Esc/~|   1  |   2  |   3  |   4  |   5  |
   * |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |
   * |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |
   * |------+------+------+------+------+------+------.
   * | Shift|   Z  |   X  |   C  |   V  |   B  |Enter |
   * |------+------+------+------+------+------+------|
   * |  Fn  | GUI  | Alt  | Flip |Symbol| Back |Space |
   * `------------------------------------------------'
   */
  [_LEFT] = LAYOUT( \
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      _______, _______, _______, _______, _______, _______, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      _______, _______, _______, _______, _______, _______, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      _______, _______, _______, _______, _______, _______, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_SFTENT,_______, _______, _______, _______, _______, _______, _______, \
      FN,      KC_LGUI, KC_LALT, RAISE,   LOWER,   KC_BSPC, KC_SPC,  _______, _______, _______, _______, _______, _______, _______ \
    ),

  /* Flip
   * ,-----------------------------------------.
   * | Esc  |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------|
   * |      |   Y  |   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+------|
   * |      |   H  |   J  |   K  |   L  |   ;  |
   * |------+------+------+------+------+------+------.
   * |      |   N  |   M  |   ,  |   .  |   /  |      |
   * |------+------+------+------+------+------+------|
   * |      |      |      |      |      | Del  |      |
   * `------------------------------------------------'
   */
  [_RIGHT] = LAYOUT( \
      KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, _______, _______, _______, _______, _______, \
      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                      _______, _______, _______, _______, _______, _______, \
      _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

  /* Symbol (Opt)
   * ,-----------------------------------------.
   * | Esc  |  ^   |  _   |  +   |  -   |  =   |
   * |------+------+------+------+------+------|
   * |      |  {   |  }   |  [   |  ]   |  '   |
   * |------+------+------+------+------+------|
   * |      |  (   |  )   |  |   |  \   |  :   |
   * |------+------+------+------+------+------+------.
   * |      |  *   |  &   |  <   |  >   |  ?   |      |
   * |------+------+------+------+------+------+------|
   * |      |      |      |      |      | Del  |      |
   * `------------------------------------------------'
   */
  [_SYMBOL] = LAYOUT( \
      KC_ESC,  KC_CIRC, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,                    _______, _______, _______, _______, _______, _______, \
      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_QUOT,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, KC_COLN,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_ASTR, KC_AMPR, KC_LT,   KC_GT,   KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* Function (Fn)
   * ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
   * |------+------+------+------+------+------|
   * |UCMod | Home |  Up  | End  | PgUp |      |
   * |------+------+------+------+------+------|
   * |      | Left | Down |Right | PgDn |      |
   * |------+------+------+------+------+------+------.
   * |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Play |
   * `------------------------------------------------'
   */
  [_FUNCTION] =  LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     _______, _______, _______, _______, _______, _______, \
      UC_MOD,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______, _______ \
      )

};

// clang-format on
