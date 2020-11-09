#include QMK_KEYBOARD_H

#include "keymap_finnish.h"
#include "sendstring_finnish.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum layers {
    _QWERTY,
    _NUM,
    _SNUM,
    _FNUM,
    _NAV,
    _CODE,
    _CTL
};

enum custom_keycodes {
    NOTEQUAL = SAFE_RANGE,
};

// Left hand home row
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// right hand home row
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_OE RGUI_T(FI_ODIA)

// Function shortcuts
#define DELWRD RALT(KC_DEL)
#define RDELWRD RALT(KC_BSPC)
#define SF12 LSFT(KC_F12) // SHIFT + F12
#define CMIN LCTL(FI_MINS) // CTRL + -

// Layer change keys
#define LT_ENT LT(_FNUM,KC_ENT)
#define LT_ENT2 LT(_CTL,KC_ENT)
#define LT_SPC LT(_CODE,KC_SPC)
#define LT_SPC2 LT(_SNUM,KC_SPC)
#define LT_DEL LT(_FNUM,KC_DEL)
#define LT_NUM MO(_NUM)
#define LT_NAV MO(_NAV)

// Some of the default FI_* symbols do not work with MacOS
#define PIPE LALT(KC_7) // FI_PIPE, |
#define BSLS LALT(KC_AMPR) // FI_BSLS
#define LCBR LALT(KC_ASTR) // FI_LCBR, {
#define RCBR LALT(KC_LPRN) // FI_RCBR, }
#define LABK KC_GRV // FI_GRV, <
#define RABK LSFT(KC_GRV) // FI_RABK, >
#define AT LALT(KC_2)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB    |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   V  |   B  |  Nav | Del  |  |Leader| Bspc |   N  |   M  |   ,  |   .  |   -  |  RSFT  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | GUI  |      | Space| Enter|  | Enter| Space|      | GUI  |  Ctl |
 *                        |      |      |  Num | Snum | FNum |  |  Ctl | Code | Nav  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_TAB,  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                                      KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_OE, FI_ADIA,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   LT_NAV, KC_DEL, KC_LEAD, KC_BSPC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT,KC_LGUI,LT_NUM, LT_SPC2,LT_ENT, LT_ENT2, LT_SPC,   LT_NAV, KC_RGUI, KC_RCTL
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
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NOTEQUAL, FI_EXLM, FI_DQUO, FI_HASH,FI_SCLN ,FI_COLN,
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
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
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
        // individual keys instead of shift + key.
        case HOME_J:
        case HOME_F:
            return TAPPING_TERM - 20;

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

// static void render_kyria_logo(void) {
//     static const char PROGMEM kyria_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
//         0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
//     };
//     oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
// }

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
            oled_write_P(PSTR("QWERTY\n\n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            oled_write_P(PSTR("                  \n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num:\n\n"), false);
            oled_write_P(PSTR("* 7 8 9 + å\n"), false);
            oled_write_P(PSTR("/ 4 5 6 - ä\n"), false);
            oled_write_P(PSTR("= 1 2 3 , .\n"), false);
            oled_write_P(PSTR("0\n"), false);
            break;
        case _SNUM:
            oled_write_P(PSTR("Shifted num:\n\n"), false);
            oled_write_P(PSTR("   / ( ) ? ¨\n"), false);
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
            oled_write_P(PSTR("Code:\n\n"), false);
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

