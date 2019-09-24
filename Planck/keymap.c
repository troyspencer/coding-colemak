/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

bool NumpadOn;

#define KC_CAD LALT(LCTL(KC_DEL)) 

enum planck_layers {
  _COLEMAK,
  _NUMPAD,
  _FUNC,
  _SYM,
  
};

enum planck_keycodes {
  FUNC = SAFE_RANGE,
  SYM,
  STRTNUM,
  STOPNUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* New Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  | Func |    Space    | Sym  | GUI  | End  | Home |Enter |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {_______,  _______, KC_LALT, KC_LGUI, FUNC,    KC_SPC,  KC_SPC,  SYM,     KC_RGUI, KC_END,  KC_HOME, KC_ENT }
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |   -  |  9   |  8   |  7   | Bksp |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   +  |  6   |  5   |  4   |   /  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Func |Enter |  3   |  2   |  1   |   *  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUM  |Enter |  .   |  0   |  0   |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, KC_PMNS, KC_P9,   KC_P8, KC_P7,   KC_BSPC, _______, _______, _______, _______, _______, _______},
  {_______, KC_PPLS, KC_P6,   KC_P5, KC_P4,   KC_PSLS, _______, _______, _______, _______, _______, _______},
  {FUNC,    KC_PENT, KC_P3,   KC_P2, KC_P1,   KC_PAST, _______, _______, _______, _______, _______, _______},
  {STOPNUM, KC_PENT, KC_PDOT, KC_P0, KC_P0,   _______, _______, _______, _______, _______, _______, _______}
},

/* Functions
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |  Up  |      |      |      |      |  Up  |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Left | Down |Right |      |      |  Left| Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  NUM |      |      |      |      |             |      |      |      |      | C/A/D|
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {KC_ESC , _______, _______, KC_UP,   _______, _______, _______, _______, KC_UP,   _______, _______, KC_DEL },
  {_______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {STRTNUM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAD }
},

/* Symbols/Numbers
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case STRTNUM:
      if (record->event.pressed) {
        layer_off(_FUNC);
        set_single_persistent_default_layer(_NUMPAD);
      }
      return false;
      break;
    case STOPNUM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
  }
  return true;
}


/* Empty Keymap
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
[EMPTY_KEYMAP] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}},
*/