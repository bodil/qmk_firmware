#include QMK_KEYBOARD_H
#include "version.h"
#include "unicode.h"

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  ED_PSWE,
  ED_PSW,
  ED_PESW,
  ED_PES,
};

#define XB_QUOT RCTL_T(KC_QUOT)
#define XB_EMOJI LGUI(KC_DOT)
#define XB_SNIP LGUI(LSFT(KC_S))

#define ED_MACRO_SPEED 200 // Milliseconds between keypresses in E:D macros

#define ED_PBAL KC_4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//
// Layer 0: Base layer
//
[0] = LAYOUT_ergodox_pretty(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,               KC_BSLS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TT(2),                TT(2),   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, XB_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(1),                MO(1),   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,                                                 KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_RALT,
                                               KC_APP,  XB_EMOJI,             KC_INS,  KC_DEL,
                                                        KC_HOME,              KC_PGUP,
                                      KC_SPC,  KC_LGUI, KC_END,               KC_PGDN, KC_RGUI, KC_SPC
),
//
// Layer 1: Symbols, mouse and media keys
//
[1] = LAYOUT_ergodox_pretty(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, LT(3, KC_PSCR),
  _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WBAK,     KC_WFWD, KC_LCBR, KC_RCBR, KC_PIPE, KC_ASTR, KC_UNDS, _______,
  _______, _______, XB_SNIP, KC_MS_L, KC_MS_D, KC_MS_R,                       KC_LPRN, KC_RPRN, KC_GRV,  KC_COLN, KC_DQUO, _______,
  _______, _______, _______, KC_BTN4, KC_BTN3, KC_BTN5, _______,     _______, KC_LBRC, KC_RBRC, KC_TILD, KC_LT,   KC_GT,   _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                                         _______, _______, _______, _______, _______,
                                               KC_WH_L, KC_WH_R,     KC_MPRV, KC_MNXT,
                                                        KC_WH_U,     KC_VOLU,
                                      KC_BTN1, KC_BTN2, KC_WH_D,     KC_VOLD, KC_MUTE, KC_MPLY
),
//
// Layer 2: Elite: Dangerous mode
//
[2] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, TO(0),       TO(0),   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               ED_PSWE, ED_PSW,      _______, _______,
                                                        ED_PESW,     _______,
                                      _______, ED_PBAL, ED_PES,      _______, KC_NO,   _______
),
// Layer 3: System functions
[3] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     EEP_RST, _______, NK_TOGG, VRSN,    DEBUG,   RESET,   _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_SLEP,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_WAKE,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_PWR,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
// // Layer x: wibble
// [x] = LAYOUT_ergodox_pretty(
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

//                                                _______, _______,     _______, _______,
//                                                         _______,     _______,
//                                       _______, _______, _______,     _______, _______, _______
// ),
};

// Original symbol layer, in case I want it:
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// [1] = LAYOUT_ergodox_pretty(
//   // left hand
//   VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, LT(3, KC_PSCR)
//   _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_WBAK,     KC_WFWD, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
//   _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
//   _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
//   EEP_RST, _______, _______, _______, _______,                                         _______, KC_DOT,  KC_0,    KC_EQL,  _______,
//                                                _______, _______,     _______, _______,
//                                                         _______,     _______,
//                                       _______, _______, _______,     _______, _______, _______
// ),

#define ED_DELAY SS_DELAY(ED_MACRO_SPEED)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case ED_PSWE:
            SEND_STRING("4" ED_DELAY "2" ED_DELAY "3");
            return true;
        case ED_PSW:
            SEND_STRING("4" ED_DELAY "2" ED_DELAY "3" ED_DELAY "2" ED_DELAY "3");
            return true;
        case ED_PESW:
            SEND_STRING("4" ED_DELAY "1" ED_DELAY "1");
            return true;
        case ED_PES:
            SEND_STRING("4" ED_DELAY "1" ED_DELAY "1" ED_DELAY "3" ED_DELAY "1");
            return true;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
