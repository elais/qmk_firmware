#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE   0   // default layer
#define SYMB_R 1   // symbols (activated by right hand)
#define SYMB_L 2   // symbols (activated by left hand)
#define NAV    3   // navigation
#define TOP    4   // space cadet

enum {
  CT_SE = 0,
  CT_QUOTE
};

qk_tap_dance_action_t tap_dance_actions[] = {
[CT_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox( // layer 0 : default
  // left hand
  LT(NAV,KC_ESC),  KC_1,    KC_2,       KC_3,     KC_4,     KC_5,  KC_DELETE,
  KC_TAB,          KC_Q,    KC_W,       KC_E,     KC_R,     KC_T,  OSL(TOP),
  LCTL(KC_DELETE), KC_A,    KC_S,       KC_D,     KC_F,     KC_G,
  KC_LSFT,         KC_Z,    KC_X,       KC_C,     KC_V,     KC_B,  SGUI(KC_ESC),
  MOD_HYPR,        KC_LGUI, MOD_MEH,    KC_LALT,  KC_LCTRL,   
                                         C(KC_LALT),        KC_LALT,
                                                            MO(NAV),
                             KC_BSPC,    LT(SYMB_L,KC_ESC), KC_LSFT,
  // right hand
  KC_BSPC,         KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSLS,
  CTL_T(KC_SCLN),  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
                   KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  CT_QUOT,
  ALT_T(KC_INS),   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                            MO(NAV), KC_NO,    KC_RALT,  KC_RGUI,  C(KC_ENT),
  KC_RALT,         KC_RCTRL,
  MO(NAV),
  KC_RSFT,         LT(SYMB_R,KC_ENT),    KC_SPACE
),
[SYMB_L] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_SLSH,  LSFT(KC_COMM),
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,
       KC_TRNS,  KC_EQL,   KC_HASH,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_LBRC,
 LSFT(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                         LSFT(KC_SLSH),  KC_TRNS,  KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  LSFT(KC_DOT),  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_PIPE,  KC_TRNS,
                 KC_RPRN,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_ENT,
       KC_RBRC,  KC_RCBR,  KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_ENT,
                           KC_0,    KC_DOT,  KC_DOT,     KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_SCLN,  KC_DOT
),
[SYMB_R] = LAYOUT_ergodox(  // same as above, but avoids clash between SYMB and ;/:
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_SLSH,  LSFT(KC_COMM),
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,
       KC_TRNS,  KC_PIPE,  KC_HASH,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_LBRC,
 LSFT(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                         LSFT(KC_SLSH),  KC_COLN,  KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  LSFT(KC_DOT),  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_MINS,  KC_TRNS,
                 KC_RPRN,  KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_ENT,
       KC_RBRC,  KC_RCBR,  KC_1,     KC_2,     KC_3,     KC_EQL,   KC_ENT,
                           KC_0,   KC_DOT,     KC_DOT,   KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_DOT
),
[NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_PAUSE,
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_TRNS,
       KC_TRNS,  KC_BTN1,  KC_MS_L,        KC_MS_U,      KC_MS_D,  KC_MS_R,
       KC_TRNS,  KC_BTN2,  KC_BTN4,        KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_BTN5,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,      KC_TRNS,
                                           KC_TRNS,      KC_TRNS,
                                                         KC_TRNS,
                               KC_TRNS,    KC_TRNS,      KC_TRNS,
       // right hand
       KC_PSCREEN,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
       KC_TRNS,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_ENT,
       KC_TRNS,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_TRNS,
                              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,     KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS
),
[TOP] = LAYOUT_ergodox(
        // left hand
  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,  UC(0x2227), UC(0x222A), UC(0x2229), UC(0x2282), UC(0x2283), KC_TRNS,
  KC_TRNS,  UC(0x22A5), UC(0x22A4), UC(0x22A2), UC(0x22A3), UC(0x2191),
  KC_TRNS,  UC(0x230A), UC(0x2308), UC(0x236F), UC(0x2243), UC(0x2261), KC_TRNS,
  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                KC_TRNS,    KC_TRNS,
                                                            KC_TRNS,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // right hand
  
  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,     UC(0x2283), UC(0x2200), UC(0x221E), UC(0x2203), UC(0x2202), KC_TRNS,
               UC(0x2193), UC(0x2190), UC(0x2192), UC(0x2194), KC_TRNS,    KC_TRNS,
  KC_TRNS,     UC(0x2264), UC(0x2265), KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS
),
};

// Tap Dance Declarations
void dance_quote_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
  }
};

void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOT);
  }
};
