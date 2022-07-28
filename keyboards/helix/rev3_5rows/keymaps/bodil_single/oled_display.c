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

/*
  How to Customize

  $ make helix/rev3_5rows:YOUR_KEYMAP:clean
  $ cp keyboards/helix/rev3_5rows/oled_display.c keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP

  $ edit keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP/oled_display.c
  $ make helix/rev3_5rows:YOUR_KEYMAP
  $ make helix/rev3_5rows:YOUR_KEYMAP:flash
*/

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { _LEFT = 0, _RIGHT, _SYMBOL, _FUNCTION };

bool oled_task_user(void) {
    // Render to mode icon
    // static const char os_logo[][3][3] PROGMEM = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, {{0x99, 0x9a, 0}, {0xb9, 0xba, 0}}};

    // int mode = get_unicode_input_mode();
    // int os   = 0;
    // if (mode == UC_WINC || mode == UC_WIN) {
    //     os = 1;
    // } else if (mode == UC_LNX) {
    //     os = 2;
    // }
    // oled_write_P(os_logo[os][0], false);
    oled_write_P(PSTR("\n"), false);
    // oled_write_P(os_logo[os][1], false);

    oled_write_P(PSTR(" "), false);

    // Host Keyboard Layer Status
    int layer = get_highest_layer(layer_state);
    if (layer == _LEFT) {
        oled_write_P(PSTR("LEFT"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("LEFT "), false);
    }
    if (layer == _RIGHT) {
        oled_write_P(PSTR("RIGHT"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("RIGHT "), false);
    }
    if (layer == _SYMBOL) {
        oled_write_P(PSTR("SYM"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("SYM "), false);
    }
    if (layer == _FUNCTION) {
        oled_write_P(PSTR("FN"), true);
    } else {
        oled_write_P(PSTR("FN"), false);
    }
    oled_write_P(PSTR("\n"), false);

    if (debug_enable) {
        oled_write_ln_P(PSTR("DEBUG mode"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
