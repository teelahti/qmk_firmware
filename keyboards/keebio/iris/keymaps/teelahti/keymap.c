#include QMK_KEYBOARD_H

#include "iris.h"
#include "keymap_finnish.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Layers
#define _BASE 0
#define _NUM 1
#define _SNUM 2
#define _NAV 3
#define _CTL 4

// Abbreviations
#define _G LGUI_T
#define _A LALT_T
#define _C LCTL_T
#define _S LSFT_T
#define _RS RSFT_T
#define DELWRD RALT(KC_DEL)
#define RDELWRD RALT(KC_BSPC)
#define FN_ENT LT(_SNUM,KC_ENT)
#define FN_BSPC LT(_CTL,KC_BSPC)
// Some of the default FI_* symbols do not work with MacOS
#define PIPE LALT(KC_7) // FI_PIPE, |
#define BSLS LALT(KC_AMPR) // FI_BSLS
#define LCBR LALT(KC_ASTR) // FI_LCBR, {
#define RCBR LALT(KC_LPRN) // FI_RCBR, }
#define LABK KC_GRV // FI_GRV, <
#define RABK LSFT(KC_GRV) // FI_RABK, >


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        KC_ESC  ,   KC_1  ,   KC_2  ,   KC_3  ,   KC_4  ,   KC_5  ,                            KC_6  ,   KC_7  ,   KC_8  ,    KC_9 ,   KC_0  , KC_MINS ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        KC_TAB  ,   KC_Q  ,   KC_W  ,   KC_E  ,   KC_R  ,   KC_T  ,                            KC_Y  ,   KC_U  ,   KC_I  ,    KC_O ,    KC_P , KC_BSLS ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        KC_LCTL ,_G(KC_A) ,_A(KC_S) ,_C(KC_D) ,_S(KC_F) ,   KC_G  ,                            KC_H  ,_S(KC_J) ,_C(KC_K) ,_A(KC_L) ,_G(FI_ODIA),FI_ADIA,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        KC_LSFT ,   KC_Z  ,   KC_X  ,   KC_C  ,   KC_V  ,   KC_B  , KC_LALT ,     FN_BSPC  ,  KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                             KC_LGUI  , MO(_NUM) , FN_ENT ,        KC_SPC   , MO(_NAV) , KC_RGUI
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
                                             KC_MRWD,  _______ ,   KC_MFFD,         _______ ,  KC_0   , FI_DOT
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
        _______ , _______ , _______ , _______ , _______ , _______,  _______ ,      _______ , FI_SCLN , FI_EXLM , FI_DQUO , FI_HASH , _______ , _______ ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                _______ , _______ , _______,        _______, FI_EQL  , FI_COLN
    //                                        `---------+---------+------'          `------+---------+---------'
    ),
    [_NAV] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.                        ,---------+---------+---------+---------+---------+---------.
        _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        FI_GRV  , _______ , FI_LBRC , FI_RBRC ,   PIPE  ,   BSLS  ,                          _______ , KC_PGUP ,  KC_UP  , KC_PGDN , FI_ARNG , FI_DIAE ,
    //|---------+---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------+---------|
        _______ , _______ ,   LCBR  ,   RCBR  , FI_LPRN , FI_RPRN ,                          KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  , FI_ACUT ,
    //|---------+---------+---------+---------+---------+---------+---------.    ,---------|---------+---------+---------+---------+---------+---------|
        _______ , KC_LALT ,   LABK  ,   RABK  , FI_CIRC , FI_TILD , _______ ,      KC__MUTE, RDELWRD , KC_BSPC , KC_DEL  , DELWRD  , KC_ENT  , KC_F13  ,
    //`---------+---------+---------+--+------+---------+---------+---------/    \---------+---------+---------+---------+---------+---------+---------'
                                                _______ ,  KC_NO  , _______,        KC__VOLDOWN,_______,KC__VOLUP
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
