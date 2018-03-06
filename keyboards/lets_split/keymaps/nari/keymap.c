#include QMK_KEYBOARD_H
#include "debug.h"
#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0 // default layer
#define _SYMB 1 // symbo
#define _MDIA 2 // media keys
#define _LOWER 3
#define _RAISE 4
#define _FN 5   // reserved

enum planck_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  MDIA,
  LOWER,
  RAISE,
  FN
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,----------------------------------------+  +-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-----|  |------+------+------+------+------+------|
 * | Ctr  |   A  |   S  |   D  |   F  |   G |  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+-----|  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B |  |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+-----|  |------+------+------+------+------+------|
 * | ESC  | GUI  |MDIA  | Alt  |Lower |Space|  |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------  ------------------------------------------'
 */
[_BASE] = KEYMAP( \
  KC_TAB,        KC_Q,           KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,       KC_A,           KC_S,     KC_D,     KC_F,     KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,       KC_Z,           KC_X,     KC_C,     KC_V,     KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
  KC_ESC,        KC_LGUI,        MDIA,     KC_LALT,  LOWER,    KC_SPC,  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   (  |   )  |   *  | Del  |
 * |------+------+------+------+------+------+  +------+------+------+------+------+------|
 * | Del  |   ~  |   |  |   =  |   \  |   `  |  |  '   |   {  |   [  |   ]  |   :  |  }   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |  "   |   +  |   <  |   >  |   ?  |  _   |
 * |------+------+------+------+------+------+  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      | PgUp |PgDwn |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_DEL, \
  KC_DEL,  KC_TILD, KC_PIPE, KC_EQL,  KC_BSLS, KC_GRV,  KC_QUOT, KC_LCBR, KC_LBRC, KC_RBRC, S(KC_SCLN),KC_RCBR, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DQT,  KC_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),S(KC_MINS), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______\
),

/* Raise
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  | F10  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ENT, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* MDIA
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | Reset|      |      |      |      |      |  |      |      |      |      | Play |  Del |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      |  | Prev | VolDn| VolUp| Next |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      | Rclk | Lclk |      |  |      |      |      | Mute |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_MDIA] =  KEYMAP( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_DEL, \
  _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______, _______, \
  _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MUTE, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
      } else {
        layer_off(_SYMB);
      }
      return false;
      break;
    case MDIA:
      if (record->event.pressed) {
        layer_on(_MDIA);
      } else {
        layer_off(_MDIA);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
};