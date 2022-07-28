#pragma once

#define DYNAMIC_MACRO_NO_NESTING
#define TAPPING_TERM 300
#define TAPPING_TOGGLE 3
#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX
#define UNICODE_KEY_WINC KC_APP

#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

#define IS_COMMAND() (IS_LAYER_ON(4))
#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS true

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

// #define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
