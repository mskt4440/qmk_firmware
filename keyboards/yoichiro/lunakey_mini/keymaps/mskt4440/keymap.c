/* Copyright 2020 Yoichiro Tanaka
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
#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define PERMISSIVE_HOLD 

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
//#define LOW_TAB LT(LOWER, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ALT_ENT,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC, RAISE,   SFT_ESC, KC_RCTL
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_LOWER] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,                   KC_MINS, KC_EQL, KC_UNDS, KC_PLUS,  XXXXXXX, _______, 
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, _______, _______, _______, KC_DEL,  _______, _______, _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_RAISE] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, CTLL,    CTLU,    CTLR,    _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SCRSHOT, SFTENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, ALTENT,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, SPOTL,   _______, IME,     _______, _______, _______, _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   LOCK,    _______, _______, _______, _______, _______,                   KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, _______, _______, _______, _______, _______, _______, _______ 
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
