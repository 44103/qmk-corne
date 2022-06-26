#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS
    #undef RGBLED_NUM
    #define RGBLED_NUM 54
    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT { 27, 27 }
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define LCA_DEL LCA(KC_DEL)
#define LCA_PAUS LCA(KC_PAUS)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
