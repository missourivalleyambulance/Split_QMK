#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define FNLR 1 // Alternate Keys
#define RGBL 2 // RGB Underglow Controls

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |PCHOME|           |PCEND|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB   |   Q  |   W  |   E  |   R  |   T   |MACHOME|          |MACEND|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CAPS/CTRL|   A  |   S  |   D  |   F  |   G |------|           |------|   H  |   J  |   K  |   L  |;     |'       |
 * |--------+------+------+------+------+------| FNLR |           | F13  |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  | /ENT |           |      |   N  |   M  |   ,  |   .  | /?   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RGBL | CTRL | NO   | ALT   | GUI  |                                       | PGUP | PGDOWN |   [  |   ]  | GRV  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SPC  | VOLU |       | PREV | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VOLD |       | PLAY |        |      |
 *                                 | BSPC |  DEL |------|       |------|  ENTER |SPACE |
 *                                 |      |      | MUTE |       | NEXT |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_HOME,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   LGUI(KC_LEFT),
        CTL_T(KC_CAPS), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   LT(FNLR,KC_ENT),
        TG(RGBL),      KC_LCTRL,      KC_Q,  KC_LALT,KC_LGUI,
                                                     KC_SPC,  KC_VOLU,
                                                              KC_VOLD,
                                               KC_BSPC,LT(FNLR,KC_DEL),KC_MUTE,
        // right hand
             KC_END,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        LGUI(KC_RGHT),  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_F13,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT,
                                KC_PGUP,KC_PGDOWN,KC_LBRC,KC_RBRC,         KC_GRV,
             KC_MPRV,        KC_ESC,
             KC_MPLY,
             KC_MNXT,KC_ENT, LT(FNLR,KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |   =  |  /    |   *  | BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  UP  |      |      |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LEFT | DOWN | RIGHT|      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |GUI+C+T+V|    |     |      |           |      |      |   1  |   2  |   3  |ENTER |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |ENTER  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | GUI+ |      |       |      |      |      |
 *                                 |      | DEL  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function Layer
[FNLR] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,M(0),KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,   KC_TRNS,
                                          KC_TRNS,
                            LGUI(KC_BSPC),     KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_EQL,  KC_SLSH, KC_ASTR, KC_BSPC,
       KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,    KC_MINS, KC_TRNS,
                KC_TRNS, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_ENT,  KC_TRNS,
                         KC_0,   KC_0,  KC_DOT,    KC_ENT,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |STEP  | HUE+ | HUE- | SAT+  | SAT- | VAL+ | VAL- |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | RGB  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |TOGGLE|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// RGB Controls
[RGBL] = KEYMAP(
  KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
  KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,
  KC_TRNS,KC_TRNS,KC_TRNS,M(0),KC_TRNS,KC_TRNS,KC_TRNS,
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                  KC_TRNS,   KC_TRNS,
                                     KC_TRNS,
                       KC_TRNS,     KC_TRNS, KC_TRNS,
    // right hand
       F(2),  F(3),    F(4),    F(5),    F(6),    F(7),    F(8),
       F(1),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [1]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [2]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [3]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [5]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [7]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [8]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0: // MACRO to key CMD+C+T+V for searching selected test
      if (record->event.pressed) {
        return MACRO( I(50), D(LGUI), T(C), T(T), T(V), U(LGUI), T(ENT), END  ); // this sends the string 'hello' when the macro executes
      }
      break;
  }
  return MACRO_NONE;
};
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
      }

      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
      case RGBLED_INCREASE_VAL:
        if (record->event.pressed) {
          rgblight_increase_val();
        }
        break;
      case RGBLED_DECREASE_VAL:
        if (record->event.pressed) {
          rgblight_decrease_val();
        }
        break;
      case RGBLED_STEP_MODE:
        if (record->event.pressed) {
          rgblight_step();
        }
        break;
  }
}
