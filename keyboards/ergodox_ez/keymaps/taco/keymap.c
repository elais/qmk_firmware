#include QMK_KEYBOARD_H

#include "debug.h"
#include "action_layer.h"

#define BASE   0   // default layer
#define SYMB   1   // symbols (activated by right hand)
#define NAV    2   // navigation
#define TOP    3   // space cadet

enum {
  CT_SE = 0,
  CT_QUOT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox( // layer 0 : default
  // left hand
  LT(NAV,KC_ESC),    KC_1,    KC_2,       KC_3,     KC_4,     KC_5,  KC_DELETE,
  KC_TAB,            KC_Q,    KC_W,       KC_E,     KC_R,     KC_T,  OSL(TOP),
  GUI_T(KC_DELETE),  KC_A,    KC_S,       KC_D,     KC_F,     KC_G,
  KC_LSPO,           KC_Z,    KC_X,       KC_C,     KC_V,     KC_B,  KC_MEH,
  MOD_HYPR,          KC_LGUI, MOD_MEH,    KC_LALT,  KC_LCTRL,   
                                        C(KC_LALT),          RGB_M_K,
                                                             MO(NAV),
                             KC_LEAD,    MO(NAV), KC_LSFT,
  // right hand
  KC_BSPC,         KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSLS,
  CTL_T(KC_SCLN),  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
                   KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_ENT,
  ALT_T(KC_INS),   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                            MO(NAV), KC_NO,    KC_RALT,  KC_RGUI,  C(KC_ENT),
  RGB_TOG,         KC_RCTRL,
  MO(NAV),
  KC_RSFT,         S(KC_ESC),    LT(SYMB,KC_SPC)
),
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  LSFT(KC_COMM),
       KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_LBRC,
 LSFT(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,
                                               KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  LSFT(KC_DOT),  KC_UP,    KC_7,     KC_8,     KC_9,     KC_PPLS,  KC_TRNS,
                 KC_DOWN,  KC_4,     KC_5,     KC_6,     KC_MINUS, TD(CT_QUOT),
       KC_RBRC,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_PAST,  KC_PEQL,
                           KC_0,     KC_DOT,   KC_BSLS,  KC_PSLS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
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
  KC_TRNS,  UC(0x2227), UC(0x2228), UC(0x222A), UC(0x2229), UC(0x2282), KC_TRNS,
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
                                       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS
),
};


void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
};

// leader key config
LEADER_EXTERNS();

void matrix_scan_user(void){
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_DELETE) {
      // When I press KC_LEAD and then KC_TAB, this opens 1password
      SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_BSLASH))));
    }

    SEQ_ONE_KEY(KC_LEAD) {
      // When I press KC_LEAD and then KC_DELETE, this launches Alfred;
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
    }

    SEQ_ONE_KEY(KC_SCOLON) {
      // When I press KC_LEAD and then KC_GRAVE, this launches iTerm;
      SEND_STRING(SS_LCTRL(SS_TAP(X_GRAVE)));
    }

    // Window Manipulation
    // Window Halves
    SEQ_TWO_KEYS(KC_W, KC_H) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_LEFT))));
    }

    SEQ_TWO_KEYS(KC_W, KC_J) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_DOWN))));
    }

    SEQ_TWO_KEYS(KC_W, KC_K) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_UP))));
    }

    SEQ_TWO_KEYS(KC_W, KC_L) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_RIGHT))));
    }

    // Window Quarters
    SEQ_TWO_KEYS(KC_W, KC_U) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_U))));
    }

    SEQ_TWO_KEYS(KC_W, KC_I) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_I))));
    }

    SEQ_TWO_KEYS(KC_W, KC_N) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_N))));
    }

    SEQ_TWO_KEYS(KC_W, KC_M) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_M))));
    }
  }
}
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
}

qk_tap_dance_action_t tap_dance_actions[] = {
[CT_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset)
};
