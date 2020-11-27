#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3 

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define LAYER_TAPPING_TERM 200
#define IME LCTL(KC_SPC)
#define SPOTL LCMD(KC_SPC)
#define SCRSHOT SCMD(KC_4)
#define SFT_ESC RSFT_T(KC_ESC)
#define ALT_ENT RALT_T(KC_ENT)
#define SFTENT RSFT(KC_ENT)
#define ALTENT RALT(KC_ENT)
#define CTLL LCTL(KC_LEFT)
#define CTLR LCTL(KC_RIGHT)
#define CTLU LCTL(KC_UP)
#define LOCK LCMD(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                         XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,                         XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                         XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ALT_ENT, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_LGUI, LOWER,   KC_SPC,        KC_BSPC, RAISE,   SFT_ESC,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_LOWER] = LAYOUT(
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                         XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                         XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LPRN, KC_LT,   KC_LCBR, KC_LBRC, KC_UNDS, KC_PLUS, XXXXXXX,                         XXXXXXX, KC_MINS, KC_EQL,  KC_RBRC, KC_RCBR, KC_GT,   KC_RPRN, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______, _______,       KC_ENT,  _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_RAISE] = LAYOUT(
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX,                         XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, CTLL,    CTLU,    CTLR,    _______, XXXXXXX,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SCRSHOT, SFTENT,  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, XXXXXXX,                         XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, ALTENT,  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          SPOTL,   _______, IME,           _______, _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_ADJUST] = LAYOUT(
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    LOCK,    _______, _______, _______, _______, _______, XXXXXXX,                         XXXXXXX, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, _______, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5, XXXXXXX,                         XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U,KC_MS_R,  _______, _______, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, XXXXXXX,                         XXXXXXX, _______, _______, _______, _______, _______, _______, \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______, _______,       _______, _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
// |--------+--------+--------+--------+--------+--------+--------+--------+-----+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

};

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < LAYER_TAPPING_TERM)) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < LAYER_TAPPING_TERM)) {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}
