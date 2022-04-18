#include QMK_KEYBOARD_H

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

bool should_process_keypress(void) { return true; }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT
                                      //`--------------------------'  `--------------------------'
   ),
   [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_CAPS,                      KC_NLCK,   KC_P4,   KC_P5,   KC_P6,KC_LANG2, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS,  KC_SPC,     KC_ENT,  KC_TRNS, KC_RALT
                                      //`--------------------------'  `--------------------------'
   ),
   [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LALT,   KC_LT, KC_LBRC, KC_LCBR, KC_LPRN,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,KC_LANG1, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_GRV,   KC_GT, KC_RBRC, KC_RCBR, KC_RPRN,                        KC_NO, KC_BSLS, KC_PIPE, KC_UNDS, KC_QUOT, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS,  KC_SPC,     KC_ENT, KC_TRNS, KC_RALT
                                      //`--------------------------'  `--------------------------'
   ),
   [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_PGUP,                      KC_HOME,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, KC_PGDN,                       KC_END,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LCA_DEL, KC_TRNS,  KC_SPC,     KC_ENT, KC_TRNS,LCA_PAUS
                                      //`--------------------------'  `--------------------------'
   )
};



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};
static uint16_t key_tap[RGBLED_NUM] = {0};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

enum custom_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

struct LayerState {
  bool is_lower_pressed;
  bool is_raise_pressed;
};


struct MinMax {
  uint16_t min;
  uint16_t max;
};

static struct MinMax minmax = {0, 1};

static struct LayerState ls = {false, false};
static uint16_t key_to_led[MATRIX_ROWS][MATRIX_COLS] = {
  // Left
  { 6,  7,  8,  9, 10, 11},
  {12, 13, 14, 15, 16, 17},
  {18, 19, 20, 21, 22, 23},
  {-1, -1, -1, 24, 25, 26},
  // Right
  {38, 37, 36, 35, 34, 33},
  {44, 43, 42, 41, 40, 39},
  {50, 49, 48, 47, 46, 45},
  {-1, -1, -1, 53, 52, 51}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        ls.is_lower_pressed = true;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (ls.is_lower_pressed) {
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
        }
        ls.is_lower_pressed = false;
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        ls.is_raise_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (ls.is_raise_pressed) {
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
        }
        ls.is_raise_pressed = false;
      }
      return false;
    default:
      if (record->event.pressed) {
        ls.is_lower_pressed = false;
        ls.is_raise_pressed = false;
      }
      break;
  }
  if (record->event.pressed) {
    if (!(record->event.key.row == 3 || record->event.key.row == 7))
      ++key_tap[key_to_led[record->event.key.row][record->event.key.col]];
    for(int i=0; i<RGBLED_NUM; ++i) {
      if(minmax.max < key_tap[i]) minmax.max = key_tap[i];
      if(minmax.min > key_tap[i]) minmax.min = key_tap[i];
    }
    for(int i=0; i<RGBLED_NUM; ++i)
      if ((0 <= i && i <= 5) || (27 <= i && i <= 32) || key_tap[i] == 0 || (24 <= i && i <= 26) || (51 <= i && i <= 53))
        sethsv(0, 0, 0, (LED_TYPE *)&led[i]);
      else
        sethsv((key_tap[i]-minmax.min)*200/(minmax.max-minmax.min), 255, 80, (LED_TYPE *)&led[i]);
    rgblight_set();
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
