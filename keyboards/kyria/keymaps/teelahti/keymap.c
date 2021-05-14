#include QMK_KEYBOARD_H

#include "keymap_finnish.h"
#include "sendstring_finnish.h"
#include "eeconfig.h"

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer 1: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   V  |   B  |  Nav | Del  |  |Leader| Bspc |   N  |   M  |   ,  |   .  |   -  |  RSFT  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | GUI  |      | Space| Enter|  | Enter| Space|      | GUI  |  Win |
 *                        |      |      |  Num | Snum | FNum |  |  Ctl | Code | Nav  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_TAB,  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                                      KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_OE, FI_ADIA,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   LT_NAV, KC_DEL, KC_LEAD, KC_BSPC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT,KC_LGUI,LT_NUM, LT_SPC2,LT_ENT, LT_ENT2, LT_SPC,   LT_NAV, KC_RGUI, TG_WIN
    ),
/*
 * Base Layer 2: QWERTY Windows. Changes the programming layer to a Windows-version
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   V  |   B  |  Nav | Del  |  |Leader| Bspc |   N  |   M  |   ,  |   .  |   -  |  RSFT  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | GUI  |      | Space| Enter|  | Enter| Space|      | GUI  |  Mac |
 *                        |      |      |  Num | Snum | FNum |  |  Ctl | Code | Nav  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY_WIN] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_TAB,  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                                      KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_OE, FI_ADIA,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   LT_NAV, KC_DEL, KC_LEAD, KC_BSPC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT,KC_LGUI,LT_NUM, LT_SPC2,LT_ENT, LT_ENT2, W_LT_SPC, LT_NAV, KC_RGUI, TG_WIN
    ),
/*
 * Numpad layer, activated with LT_NUM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   *  | 7 /  | 8 (  | 9 )  |  +   |   å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | GUI  | Alt  | Ctl  | Shift|      |                              |   /  | 4 €  | 5 %  | 6 &  |  -   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Play |      |  |      |      |   =  | 1 !  | 2 "  | 3 #  |  ,   |   .    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        |      | Prev |  Num | Next |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     FI_ASTR, KC_7,    KC_8,    KC_9, FI_PLUS, FI_ARNG,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     FI_SLSH, KC_4,    KC_5,    KC_6, FI_MINS, _______,
      _______, _______, _______, KC_VOLD, KC_MUTE, _______, KC_MPLY, _______, _______, _______, FI_EQL,  KC_1,    KC_2,    KC_3, FI_COMM,  FI_DOT,
                                 _______, KC_MRWD, _______, KC_MFFD, _______, _______, _______, KC_0,   _______,  _______
    ),
/*
 * Shifted numbers, activated with LT_SPC2
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  /   |  (   |  )   |  ?   |    ¨   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | GUI  | Alt  | Ctl  | Shift|      |                              |      |  €   |  %   |  &   |  _   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |  !=  |  !   |  "   |  #   |  ;   |   :    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      | SNum |      |  |      |      |   =  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SNUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, FI_SLSH, FI_LPRN, FI_RPRN, FI_QUES, FI_DIAE,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______, FI_CURR, FI_PERC, FI_AMPR, FI_UNDS, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NOTEQUAL,FI_EXLM, FI_DQUO, FI_HASH,FI_SCLN ,FI_COLN,
                                 _______, _______, _______, _______, _______, _______, _______, FI_EQL , _______, _______
    ),

/*
 * F-keys layer, entered with FNum
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | GUI  | Alt  | Ctl  | Shift|      |                              |      | F4   | F5   | F6   | F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | F1   | F2   | F3   | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      | FNum |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FNUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Coding layer, entered with LT_SPC
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   `    |   [  |  ]   |  |   |  \   |  ´   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ~    |   {  |  }   |  (   |  )   |  "   |                              |      | Shift| Ctl  |  Alt | GUI  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   @    |   <  |  >   |  !   |  =   |  ^   |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      | Code |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CODE] = LAYOUT(
      FI_GRV,  FI_LBRC, FI_RBRC, PIPE,    BSLS,    FI_ACUT,                                     _______, _______, _______, _______, _______, _______,
      FI_TILD, LCBR,    RCBR,    FI_LPRN, FI_RPRN, FI_DQUO,                                     _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
      AT,      LABK,    RABK,    FI_EXLM, FI_EQL,  FI_CIRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Coding layer Windows, entered with LT_SPC
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   `    |   [  |  ]   |  |   |  \   |  ´   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ~    |   {  |  }   |  (   |  )   |  "   |                              |      | Shift| Ctl  |  Alt | GUI  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   @    |   <  |  >   |  !   |  =   |  ^   |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      | Code |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CODE_WIN] = LAYOUT(
      FI_GRV,  FI_LBRC, FI_RBRC, FI_PIPE, FI_BSLS, FI_ACUT,                                     _______, _______, _______, _______, _______, _______,
      FI_TILD, FI_LCBR, FI_RCBR, FI_LPRN, FI_RPRN, FI_DQUO,                                     _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
      FI_AT,   FI_LABK, FI_RABK, FI_EXLM, FI_EQL,  FI_CIRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation Layer, entered with Nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Sleep  |      |      |      |      |      |                              |      | PgUp |  Up  | PgDn |      | ScrlLk |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | GUI  | Alt  | Ctl  | Shift|      |                              | Home | Left | Down | Right| End  | CapsLk |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Nav  |      |  |      | Mute |RDelW | Bspc |  Del | DelW | Ctl- |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |VolDn | Nav  |VolUp |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      KC_SLEP, _______, _______, _______, _______, _______,                                        _______, KC_PGUP,  KC_UP,   KC_PGDN, _______, KC_SLCK,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        KC_HOME, KC_LEFT,  KC_DOWN, KC_RGHT, KC_END,  KC_CAPS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC__MUTE,   RDELWRD ,KC_BSPC , KC_DEL,  DELWRD,  CMIN,    _______,
                                 _______, _______, _______, _______, _______, _______, KC__VOLDOWN,_______, KC__VOLUP,_______
    ),
/*
 * Adjust Layer, entered with LT_ENT2
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | RES  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  | CTL  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CTL] = LAYOUT(
      _______, _______,  _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// Per key tapping term settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Reduce the amount of accidental Enter and Space key hits when using those keys
        // as layer change
        case LT_ENT:
        case LT_SPC:
            return TAPPING_TERM - 20;

        // Using shift is usually fast, reduce tap term for them to avoid getting
        // individual keys instead of shift + key. This is needed, since when
        // IGNORE_MOD_TAP_INTERRUPT is on, both keys, modifier and another key, need to be held
        // at least for TAPPING_TERM for the modified symbol to appear.
        case HOME_J:
        case HOME_F:
            return TAPPING_TERM - 50;

        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NOTEQUAL:
        if (record->event.pressed) {
            // when keycode NOTEQUAL is pressed
            SEND_STRING("!=");
        } else {
            // when keycode NOTEQUAL is released
        }
        break;
    }
    return true;
};


LEADER_EXTERNS();

void matrix_scan_user(void) {

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) { // Inline Code
            SEND_STRING("``" SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_C, KC_C) { // Slack/Discord code block
            SEND_STRING("```" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
        SEQ_ONE_KEY(KC_S) { // MacOS screenshot
            SEND_STRING(SS_LGUI(SS_LSFT("5")));
        }
        SEQ_ONE_KEY(KC_E) { // Email personal
            SEND_STRING("tero@teelahti.fi");
        }
        SEQ_TWO_KEYS(KC_E, KC_E) { // Email work
            SEND_STRING("tero.teelahti@nextgames.com");
        }
        SEQ_TWO_KEYS(KC_G, KC_B) { // Greeting
            SEND_STRING("Best,\n\nTero");
        }
        SEQ_TWO_KEYS(KC_G, KC_T) { // Greeting
            SEND_STRING("Thanks,\n\nTero");
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_signature(void) {
  static const char PROGMEM img[] = {
    // Generate with https://javl.github.io/image2cpp/, 128x64px, plain bytes, vertical, 1 bit per pixel
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xe0,
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0,
    0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00,
    0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00,
    0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x0f, 0x0f,
    0x0f, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x8f, 0x8f, 0xcf, 0xcf, 0xc7, 0xc7, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x07, 0x0f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0x07, 0x00,
    0x00, 0x00, 0x03, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x07, 0x07, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x80, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x0f, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x87, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
    0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x78, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(img, sizeof(img));
}

static void render_status(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY MAC\n\n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            break;
        case _QWERTY_WIN:
            oled_write_P(PSTR("QWERTY WIN\n\n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num:\n\n"), false);
            oled_write_P(PSTR("* 7 8 9 + o\n"), false);
            oled_write_P(PSTR("/ 4 5 6 - a\n"), false);
            oled_write_P(PSTR("= 1 2 3 , .\n"), false);
            oled_write_P(PSTR("0\n"), false);
            break;
        case _SNUM:
            oled_write_P(PSTR("Shifted num:\n\n"), false);
            oled_write_P(PSTR("   / ( ) ? ''\n"), false);
            oled_write_P(PSTR("   e % & _\n"), false);
            oled_write_P(PSTR("!= ! \" # ; :\n"), false);
            oled_write_P(PSTR("=\n"), false);
            break;
        case _FNUM:
            oled_write_P(PSTR("F-keys:\n\n"), false);
            oled_write_P(PSTR("  F7  F8  F9  F10\n"), false);
            oled_write_P(PSTR("  F4  F5  F6  F11\n"), false);
            oled_write_P(PSTR("  F1  F2  F3  F12\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _CODE:
            oled_write_P(PSTR("Code MAC:\n\n"), false);
            oled_write_P(PSTR("` [ ] | \\ ´\n"), false);
            oled_write_P(PSTR("~ { } ( ) \"\n"), false);
            oled_write_P(PSTR("@ < > ! = ^\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _CODE_WIN:
            oled_write_P(PSTR("Code WIN:\n\n"), false);
            oled_write_P(PSTR("` [ ] | \\ ´\n"), false);
            oled_write_P(PSTR("~ { } ( ) \"\n"), false);
            oled_write_P(PSTR("@ < > ! = ^\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation:\n\n"), false);
            oled_write_P(PSTR("    PU U PD\n"), false);
            oled_write_P(PSTR("Hom L  D R  E\n"), false);
            oled_write_P(PSTR("RDW BS D DW C-\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _CTL:
            oled_write_P(PSTR("Adjust:\n\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("                 RES\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_signature();
    }
}
#endif

