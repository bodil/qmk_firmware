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
enum layer_names { _BASE = 0, _SYMBOL, _UNICODE, _SYSTEM };

#ifdef OLED_DRIVER_ENABLE

void render_status(void) {
    // Render to mode icon
    static const char os_logo[][3][3] PROGMEM = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, {{0x99, 0x9a, 0}, {0xb9, 0xba, 0}}};

    int mode = get_unicode_input_mode();
    int os   = 0;
    if (mode == UC_WINC || mode == UC_WIN) {
        os = 1;
    } else if (mode == UC_LNX) {
        os = 2;
    }
    oled_write_P(os_logo[os][0], false);
    oled_write_P(PSTR(" Layer:\n"), false);
    oled_write_P(os_logo[os][1], false);

    oled_write_P(PSTR(" "), false);

    // Host Keyboard Layer Status
    int layer = get_highest_layer(layer_state);
    if (layer == _BASE) {
        oled_write_P(PSTR("BASE"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("BASE "), false);
    }
    if (layer == _SYMBOL) {
        oled_write_P(PSTR("SYM"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("SYM "), false);
    }
    if (layer == _UNICODE) {
        oled_write_P(PSTR("UTF"), true);
        oled_write_P(PSTR(" "), false);
    } else {
        oled_write_P(PSTR("UTF "), false);
    }
    if (layer == _SYSTEM) {
        oled_write_P(PSTR("SYS"), true);
    } else {
        oled_write_P(PSTR("SYS"), false);
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
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

static void render_rgbled_status(bool full) {
#    ifdef RGBLIGHT_ENABLE
    char buf[30];
    if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
        if (full) {
            snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ", rgblight_get_mode(), rgblight_get_hue() / RGBLIGHT_HUE_STEP, rgblight_get_sat() / RGBLIGHT_SAT_STEP, rgblight_get_val() / RGBLIGHT_VAL_STEP);
        } else {
            snprintf(buf, sizeof(buf), "[%2d] ", rgblight_get_mode());
        }
        oled_write(buf, false);
    }
#    endif
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
        render_rgbled_status(true);
    }
}
#endif
