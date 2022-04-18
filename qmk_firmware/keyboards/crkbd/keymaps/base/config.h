#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define SPLIT_TRANSPORT_MIRROR

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

#define LED_LAYOUT( \
             L00, L01, L02,                R00, R01, R02, \
             L03, L04, L05,                R03, R04, R05, \
\
   L06, L07, L08, L09, L10, L11,      R06, R07, R08, R09, R10, R11, \
   L12, L13, L14, L15, L16, L17,      R12, R13, R14, R15, R16, R17, \
   L18, L19, L20, L21, L22, L23,      R18, R19, R20, R21, R22, R23, \
                  L24, L25, L26,      R24, R25, R26  \
) { \
   L02, L01, L00, \
   L03, L04, L05, \
   L26, L23, L17, L11, \
   L10, L16, L22, L25, \
   L24, L21, L15, L09, \
   L08, L14, L20, \
   L19, L13, L07, \
   L06, L12, L18, \
\
   R02, R01, R00, \
   R03, R04, R05, \
   R24, R18, R12, R06, \
   R07, R13, R19, R25, \
   R26, R20, R14, R08, \
   R09, R15, R21, \
   R22, R16, R10, \
   R11, R17, R23 \
}

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
          0,  1,  2,                     27, 28, 29, \
          3,  4,  5,                     30, 31, 32, \
\
  6,  7,  8,  9, 10, 11,             33, 34, 35, 36, 37, 38, \
 12, 13, 14, 15, 16, 17,             39, 40, 41, 42, 43, 44, \
 18, 19, 20, 21, 22, 23,             45, 46, 47, 48, 49, 50, \
                 24, 25, 26,     51, 52, 53 \
)

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define LCA_DEL LCA(KC_DEL)
#define LCA_PAUS LCA(KC_PAUS)

#define LT_MO_1 LT(MO(1), KC_LANG2)
#define LT_MO_2 LT(MO(2), KC_LANG1)
