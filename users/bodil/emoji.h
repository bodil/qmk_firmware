// clang-format off

#define EMOJI_ENUM \
    EM_SMILE, \
    EM_SMIRK, \
    EM_HMM, \
    EM_SHUT, \
    EM_SAD, \
    EM_WORRY, \
    EM_CONF, \
    EM_WELP, \
    EM_CRY, \
    EM_OHNO, \
    EM_THUP, \
    EM_FIST, \
    EM_SHRUG, \
    EM_HEART, \
    EM_DOG,

// clang-format on

#define EMOJI_SWITCH(record)                              \
    case EM_SMILE:                                        \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😁");                 \
            } else {                                      \
                send_unicode_string("😊");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_SMIRK:                                        \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😒");                 \
            } else {                                      \
                send_unicode_string("😏");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_HMM:                                          \
        if (record->event.pressed) {                      \
            send_unicode_string("🤔");                  \
        }                                                 \
        break;                                            \
    case EM_SHUT:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😶");                 \
            } else {                                      \
                send_unicode_string("😑");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_SAD:                                          \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("🙃");              \
            } else {                                      \
                send_unicode_string("😔");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_WORRY:                                        \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("🙁");              \
            } else {                                      \
                send_unicode_string("😟");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_CONF:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😖");                 \
            } else {                                      \
                send_unicode_string("😕");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_WELP:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("🤯");              \
            } else {                                      \
                send_unicode_string("😳");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_CRY:                                          \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😭");                 \
            } else {                                      \
                send_unicode_string("😢");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_OHNO:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("😱");                 \
            } else {                                      \
                send_unicode_string("😮");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_THUP:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("☝️");            \
            } else {                                      \
                send_unicode_string("👍");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_FIST:                                         \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("✋");                 \
            } else {                                      \
                send_unicode_string("✊");                 \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_SHRUG:                                        \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("🤦🏻‍♀️"); \
            } else {                                      \
                send_unicode_string("🤷🏻‍♀️"); \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_HEART:                                        \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("💕");                 \
            } else {                                      \
                send_unicode_string("❤️");            \
            }                                             \
        }                                                 \
        break;                                            \
    case EM_DOG:                                          \
        if (record->event.pressed) {                      \
            if (get_mods() & MOD_MASK_SHIFT) {            \
                send_unicode_string("🐕");                 \
            } else {                                      \
                send_unicode_string("🐶");                 \
            }                                             \
        }                                                 \
        break;
