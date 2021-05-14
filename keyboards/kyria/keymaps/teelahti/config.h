#pragma once

#define EE_HANDS

// default 200
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD
// Use per key option to be able to disable permissive hold from home row modifiers
// #define PERMISSIVE_HOLD_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#define BILATERAL_COMBINATIONS 1000
