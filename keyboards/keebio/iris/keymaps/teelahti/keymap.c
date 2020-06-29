#include QMK_KEYBOARD_H

#include "iris.h"
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

// Funtion shortcuts
#define DELWRD RALT(KC_DEL)
#define RDELWRD RALT(KC_BSPC)
#define SF12 LSFT(KC_F12) // SHIFT + F12
#define CMIN LCTL(FI_MINS) // CTRL + -

// Layer change keys
#define LT_ENT LT(_SNUM,KC_ENT)
#define LT_SPC LT(_CODE,KC_SPC)
#define LT_BSPC LT(_CTL,KC_BSPC)
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

// Per key tapping term settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // My finger tends to linger on these key which causes accidental modifier+symbol
        // presses --> increase the time
        // GUI:
        case HOME_A:
        case HOME_OE:
        // Shift:
        case HOME_J:
        case HOME_F:
           return TAPPING_TERM + 50;

        // Reduce the amount of accidental Enter and Space key hits when using the key
        // as layer change
        case LT_ENT:
        case LT_SPC:
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        KC_ESC  ,   KC_1  ,   KC_2  ,   KC_3  ,   KC_4  ,   KC_5  ,                            KC_6  ,   KC_7  ,   KC_8  ,    KC_9 ,   KC_0  , KC_MINS ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        KC_ESC  ,   KC_Q  ,   KC_W  ,   KC_E  ,   KC_R  ,   KC_T  ,                            KC_Y  ,   KC_U  ,   KC_I  ,    KC_O ,   KC_P  , KC_BSLS ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        KC_TAB  ,  HOME_A ,  HOME_S ,  HOME_D ,  HOME_F ,   KC_G  ,                            KC_H  ,  HOME_J ,  HOME_K ,  HOME_L , HOME_OE , FI_ADIA ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        KC_LSFT ,   KC_Z  ,   KC_X  ,   KC_C  ,   KC_V  ,   KC_B  ,  LT_NAV ,     LT_BSPC  ,  KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                             KC_LGUI  ,  LT_NUM  , LT_ENT ,        LT_SPC  ,  LT_NAV ,  KC_RGUI
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
	[_NUM] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______ ,                          FI_ASTR ,   KC_7  ,   KC_8  ,   KC_9  , FI_PLUS , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , _______ ,                          FI_SLSH ,   KC_4  ,   KC_5  ,   KC_6  , FI_MINS , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______,  KC_MPLY ,      KC_DEL  , FI_COMM ,   KC_1  ,   KC_2  ,   KC_3  , FI_EQL  , _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                             KC_MRWD  , _______ ,  KC_MFFD,         _______ ,  KC_0   , FI_DOT
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    [_SNUM] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , FI_SLSH , FI_LPRN , FI_RPRN , FI_QUES , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , _______ ,                          _______ , FI_CURR , FI_PERC , FI_AMPR , FI_UNDS , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______,  _______ ,      _______ , FI_SCLN , FI_EXLM , FI_DQUO , FI_HASH , NOTEQUAL, _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                             _______  , _______ , _______ ,         _______, FI_EQL  , FI_COLN
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    // TODO: Currently there is no way to enter this layer
    [_FNUM] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ ,  KC_F7  ,  KC_F8  ,  KC_F9  , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , _______ ,                          _______ ,  KC_F4  ,  KC_F5 ,   KC_F6  , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______,  _______ ,      _______ , _______ ,  KC_F1  ,  KC_F2  ,  KC_F3  , _______ , _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                _______ , _______ , _______,        _______, _______  , _______
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    [_NAV] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , KC_PGUP ,  KC_UP  , KC_PGDN , FI_ARNG , FI_DIAE ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , _______ ,                          KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  ,   SF12  ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        _______ , _______ , _______ , _______ , _______ , _______,  _______ ,      KC__MUTE, RDELWRD , KC_BSPC , KC_DEL  , DELWRD  ,  CMIN   , KC_F12  ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                _______ ,  KC_NO  , _______,        KC__VOLDOWN,_______,KC__VOLUP
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    [_CODE] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        FI_GRV  , FI_LBRC , FI_RBRC ,   PIPE  ,   BSLS  , FI_ACUT ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        FI_TILD ,   LCBR  ,   RCBR  , FI_LPRN , FI_RPRN , FI_DQUO ,                          _______ , KC_RSFT , KC_RCTL , KC_RALT , KC_RGUI , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
          AT    ,   LABK  ,   RABK  , FI_EXLM , FI_EQL  , FI_CIRC ,  KC_NO  ,      KC_NO   , _______ , _______ , _______ , _______ , _______ , _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                _______ ,  KC_NO  , _______,        _______, _______  , _______
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    [_CTL] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        KC_SLEP , RGB_TOG , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , RGB_MOD , RGB_VAI , RGB_HUI , RGB_SAI , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
       _______  , RGB_RMOD, RGB_VAD , RGB_HUD , RGB_SAI ,  RESET  ,  KC_NO  ,      KC_NO   , _______ , _______ , _______ , _______ , _______ , _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                KC_NO   ,  KC_NO  , KC_NO,          KC_NO  ,_______  , KC_NO
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
