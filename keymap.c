#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define CODE 1 // symbols
#define CLMK 2 // colemak layer
#define MDIA 3 // media keys
#define LED_BRIGHTNESS 2

/*
 * @jdavis Ergodox EZ layout
 *
 * Original layout by Nicholas Keene:
 *     http://nicholas.rinard.us/2016/03/ergodox-ez-layout.html
 *
 * Issues:
 *     - Code button isn't in a very great spot
 *          - Fix: Move to a place that is symmetrical
 *     - The minus key (-) is in a really terrible spot
 *          - Fix: Put it in a good place on the coding layer (this relies on the above fix as well)
 *     - Maybe use semicolon for a modifier?
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  |      |           |  -   |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |ESC/CTRL|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   | '/CTRL |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LAlt |      | LAlt | LGui |                                       | Space| ~Mdia| LGui | LAlt | RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,---------------.       ,---------------.
 *                                      |        |      |       | Code |        |
 *                               ,------|--------|------|       |------+--------+------.
 *                               |      |        |      |       |Colemk|        |      |
 *                               |Bkspc |   Del  |------|       |------| ~Code  | Enter|
 *                               |      |        | Space|       | Mdia |        |      |
 *                               `----------------------'       `----------------------'
 */

[BASE] = KEYMAP(  // layer 0 : default
   // left hand
   KC_GRV,        KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_TRNS,
   KC_TAB,        KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_LBRC,
   CTL_T(KC_ESC), KC_A,    KC_S,    KC_D, KC_F, KC_G,
   KC_LSFT,       KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_TRNS,
   KC_LCTL,       KC_LALT, KC_TRNS, KC_LALT,    KC_LGUI,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                                KC_BSPC, KC_DEL, KC_SPC,

                                                                // right hand
                                                                KC_MINS, KC_6, KC_7,   KC_8,     KC_9,    KC_0,    KC_EQL,
                                                                KC_RBRC, KC_Y, KC_U,   KC_I,     KC_O,    KC_P,    KC_BSLS,
                                                                         KC_H, KC_J,   KC_K,     KC_L,    KC_SCLN, CTL_T(KC_QUOT),
                                                                KC_TRNS, KC_N, KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                                                                               KC_SPC, MO(MDIA), KC_RGUI, KC_RALT, KC_RCTL,
                                                                TG(CODE), KC_TRNS,
                                                                TG(CLMK),
                                                                TG(MDIA), MO(CODE), KC_ENT
    ),
    //
/* Keymap 1: Coding Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |   {  |   }  |        |
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

[CODE] = KEYMAP(
       // left hand
       KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                                                         KC_TRNS,KC_TRNS,
                                                                 KC_TRNS,
                                                   KC_TRNS,KC_TRNS,KC_TRNS,
                                                                     // right hand
                                                                     KC_TRNS,      KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,
                                                                     KC_TRNS,      KC_CIRC, KC_AMPR, KC_ASTR,   KC_LPRN, KC_RPRN, KC_F12,
                                                                                   KC_6,    KC_7,    KC_8,      KC_9,    KC_0,    KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,   KC_LCBR, KC_RCBR, KC_TRNS,
                                                                                            KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                                                                     KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                                     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Colemak layer
 *
 * Keep everything as the default layer except for the alphabet.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |      |      |      |        |
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

[CLMK] = KEYMAP(
        // Left hand
        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_TRNS,
        KC_TRNS,      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
        KC_TRNS,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                          KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,
                                                  KC_TRNS,KC_TRNS, KC_TRNS,
        // Right hand
        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
        KC_TRNS,      KC_K,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |ShutDn| Sleep| Mute |Vol Dn|Vol Up|      |           |      |      |PrtSc | PgUp |MyComp| Mail |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  | MsUp |ScrlUp|      |ScrlUp|           |ScrlUp|      |ScrlUp|  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Down |Right |MsRght|      |------|           |------| Home | Left | Down | Right| End  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |MsDown|ScrlDn|      |ScrlDn|           |ScrlDn|      |ScrlDn| Down |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Stop |Refrsh|       |      | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Brwser|Brwser|Search|       |      |      |      |
 *                                 |Back  | Fwd  |------|       |------| Stop | Play-|
 *                                 |      |      | Home |       |      |      | Pause|
 *                                 `--------------------'       `--------------------'
 */

[MDIA] = KEYMAP(
       KC_ESC,  KC_PWR,  KC_SLEP, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
       MO(MDIA), KC_TRNS, KC_UP, KC_MS_U, KC_WH_U, KC_TRNS, KC_WH_U,
       KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_D, KC_TRNS, KC_TRNS, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_WSTP, KC_WREF,
                                                             KC_WSCH,
                                           KC_WBAK, KC_TRNS, KC_WHOM,
                                                                     // right hand
                                                                     KC_TRNS,  KC_TRNS, KC_PSCR, KC_PGUP, KC_MYCM, KC_MAIL, KC_TRNS,
                                                                     KC_WH_U,  KC_TRNS, KC_WH_U, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                                                                               KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END, KC_TRNS,
                                                                     KC_WH_D,  KC_TRNS, KC_WH_D, KC_DOWN, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                        KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
                                                                     KC_TRNS, KC_MNXT,
                                                                     KC_TRNS,
                                                                     KC_TRNS, KC_MSTP, KC_MPLY
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(CODE)                // FN1 - Momentary Layer 1 (Code)
};

const macro_t *action_get_macro(keyrecord_t *record,
        uint8_t id,
        uint8_t opt) {
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        case CODE:
            ergodox_right_led_on(1);
            ergodox_right_led_set(1, LED_BRIGHTNESS);
            break;
        case CLMK:
            ergodox_right_led_on(2);
            ergodox_right_led_set(2, LED_BRIGHTNESS);
            break;
        case MDIA:
            ergodox_right_led_on(3);
            ergodox_right_led_set(3, LED_BRIGHTNESS);
            break;
        default:
            // No LEDs
            break;
    }
}
