#ifndef USERS_BODIL_UNICODE
#define USERS_BODIL_UNICODE

enum unicode_names {
    // Typography
    MDASH,
    NDASH,
    ELLIP,
    NBSP,
    POUND,
    EURO,

    // Maths
    R_ARR,
    L_ARR,
    U_ARR,
    D_ARR,
    R_DAR,
    L_DAR,
    U_DAR,
    D_DAR,
    L_LAMBDA,
    U_LAMBDA,

    // Intl
    L_THORN,
    U_THORN,
    L_ETH,
    U_ETH,
    L_AA,
    U_AA,
    L_AE,
    U_AE,
    L_OE,
    U_OE,
};

#define X_DASH XP(MDASH, NDASH)  // Em dash, en dash shifted
#define X_ELLIP X(ELLIP)         // Ellipsis
#define X_NBSP X(NBSP)           // Non-breaking space
#define X_CASH XP(POUND, EURO)
#define X_RARR XP(R_ARR, R_DAR)        // Right arrow, double arrow shifted
#define X_LARR XP(L_ARR, L_DAR)        // Left arrow, double arrow shifted
#define X_UARR XP(U_ARR, U_DAR)        // Up arrow, double arrow shifted
#define X_DARR XP(D_ARR, D_DAR)        // Down arrow, double arrow shifted
#define X_LMBD XP(L_LAMBDA, U_LAMBDA)  // Lambda, shifted capitalised
#define X_THORN XP(L_THORN, U_THORN)   // Thorn, shifted capitalised
#define X_ETH XP(L_ETH, U_ETH)         // Eth, shifted capitalised
#define X_AA XP(L_AA, U_AA)            // Norwegian Å, shifted capitalised
#define X_AE XP(L_AE, U_AE)            // Norwegian Æ, shifted capitalised
#define X_OE XP(L_OE, U_OE)            // Norwegian Ø, shifted capitalised

#endif
