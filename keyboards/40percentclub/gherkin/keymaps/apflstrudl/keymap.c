#include QMK_KEYBOARD_H
// #include "wanleg.h"

#define _______ KC_TRNS
#define __MOD__ KC_TRNS // used to mark modifier keys to get to a layer

// Layer shorthand
#define _CM 0
#define _QW 1
#define _GA 2
#define _FN 3
#define _LO 4
#define _RA 5
#define _FF 6

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// custom tap dance for space: tap:k doubletap: space hold:RAISE
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
    _K_RA,
    _TD_SCL,
    _TD_Q
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void k_finished(qk_tap_dance_state_t *state, void *user_data);
void k_reset(qk_tap_dance_state_t *state, void *user_data);


// these are for better layout/readability
#define C_A CTL_T(KC_A)
#define S_Z SFT_T(KC_Z)
#define G_X GUI_T(KC_X)
#define A_C ALT_T(KC_C)
#define _FN_D LT(_FN,KC_D)
#define _LO_V LT(_LO,KC_V)
// #define _RA_K LT(_RA,KC_K)
#define _RA_K TD(_K_RA)
#define _FN_H LT(_FN,KC_H)
#define A_COMM ALT_T(KC_COMM)
#define G_DOT GUI_T(KC_DOT)
#define C_O CTL_T(KC_O)
#define S_SLSH SFT_T(KC_SLSH)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* COLEMAK MOD DH
 * .-----------------------------------------------------------------------------------------.
 * | Q      | W      | F      | P      | B      | J      | L      | U      | Y      | ;      |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | A      | R      | S      | T      | G      | M      | N      | E      | I      | O      |
 * | CTRL   |        |        |        |        |        |        |        |        | CTRL   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Z      | X      | C      | D      | V      | K      | H      | ,      | .      | /      |
 * | SHIFT  | GUI    | ALT    | _FN    | _LO    | _RA    | _FN    | ALT    | GUI    | SHIFT  |
 * '-----------------------------------------------------------------------------------------'
 */
[_CM] = LAYOUT_ortho_3x10(
   TD(_TD_Q),KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    C_A,     KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    C_O,
    S_Z,     G_X,     A_C,     _FN_D,   _LO_V,   _RA_K,   _FN_H,   A_COMM,  G_DOT,   S_SLSH
),

/* COLEMAK MOD DH
 * .-----------------------------------------------------------------------------------------.
 * | Q      | W      | F      | P      | B      | J      | L      | U      | Y      | ;      |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | A      | R      | S      | T      | G      | M      | N      | E      | I      | O      |
 * | CTRL   |        |        |        |        |        |        |        |        | CTRL   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Z      | X      | C      | D      | V      | K      | H      | ,      | .      | /      |
 * | SHIFT  | GUI    | ALT    | _FN    | _LO    | _RA    | _FN    | ALT    | GUI    | SHIFT  |
 * '-----------------------------------------------------------------------------------------'
 */
[_QW] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    C_A,     KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    C_O,
    S_Z,     G_X,     A_C,     _FN_D,   _LO_V,   _RA_K,   _FN_H,   A_COMM,  G_DOT,   S_SLSH
),

/* GAME
 * .-----------------------------------------------------------------------------------------.
 * | ESC    | Q      | W      | E      | R      | T      | L      | U      | Y      | TAB    |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | A      | S      | D      | F      | G      | N      | E      | I      | O      |
 * |        |        |        |        |        |        |        |        |        | CTRL   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | SPACE  | K      | H      | ,      | .      | /      |
 * |        |        |        |        |        | _RA    | _FN    | ALT    | GUI    | SHIFT  |
 * '-----------------------------------------------------------------------------------------'
 */
[_GA] = LAYOUT_ortho_3x10(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_N,    KC_E,    KC_I,    C_O,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_SPC,  _RA_K,   _FN_H,   A_COMM,  G_DOT,   S_SLSH
),

/* Function
 * .-----------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F0     |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LEFT   | UP     | DOWN   | RIGHT  | RESET  | QWERTY | COLEMAK| GAME   | FF     |        |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
 * | F11    | F12    | DELETE | ###### |        |        | ###### |        |        |        |
 * |        |        |        | ###### |        |        | ###### |        |        |        |
 * '-----------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, RESET,   DF(_QW), DF(_CM), DF(_GA), DF(_FF), _______,
    KC_F11,  KC_F12,  KC_DEL,  __MOD__, _______, _______, __MOD__, _______, _______, _______
),

/* Lower
 * .-----------------------------------------------------------------------------------------.
 * | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | BACKSP | TAB    |        |        | GUI    |        | -      | =      | (      | )      |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | ~      | |      | `      | ###### | SPACE  |        |        | [      | ]      |
 * |        |        |        |        | ###### |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------'
 */
[_LO] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_BSPC, KC_TAB,  _______, _______, KC_LGUI, _______, KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN,
    _______, KC_TILD, KC_PIPE, KC_GRV,  __MOD__, KC_SPC,  _______, _______, KC_LBRC, KC_RBRC
),

/* Raise
 * .-----------------------------------------------------------------------------------------.
 * | GESC   |        | HOME   | PgUp   | INSERT | RESET  | VOL-   | MUTE   | VOL+   | '      |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | END    | PgDn   |        | RGB_TOG| PREV   | PLAY   | NEXT   | ENTER  |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | SPACE  | ###### |        |        |        | \      |
 * |        |        |        |        |        | ###### |        |        |        |        |
 * '-----------------------------------------------------------------------------------------'
 */
[_RA] = LAYOUT_ortho_3x10(
    KC_GESC, _______, KC_HOME, KC_PGUP, KC_INS,  RESET,   KC_VOLD, KC_MUTE, KC_VOLU, KC_QUOT,
    _______, _______, KC_END,  KC_PGDN, _______, RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_ENT,
    _______, _______, _______, _______, KC_SPC,  __MOD__, _______, _______, _______, KC_BSLS
),

/* Function 2
 * .-----------------------------------------------------------------------------------------.
 * | F13    | F14    | F15    | F16    |        |        | F13    | F14    | F15    | F16    |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * | F17    | F18    | F19    | F20    |        |        | F17    | F18    | F19    | F20    |
 * |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * | F21    | F22    | F23    | F24    |        |        | F21    | F22    | F23    | F24    |
 * |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------'
 */
[_FF] = LAYOUT_ortho_3x10(
LGUI(LCTL(LALT(KC_Q))), LGUI(LCTL(LALT(KC_W))), LGUI(LCTL(LALT(KC_F))), LGUI(LCTL(LALT(KC_P))), _______, _______, LGUI(LCTL(LSFT(KC_Q))), LGUI(LCTL(LSFT(KC_W))), LGUI(LCTL(LSFT(KC_F))), LGUI(LCTL(LSFT(KC_P))),
LGUI(LCTL(LALT(KC_A))), LGUI(LCTL(LALT(KC_R))), LGUI(LCTL(LALT(KC_S))), LGUI(LCTL(LALT(KC_T))), _______, _______, LGUI(LCTL(LSFT(KC_A))), LGUI(LCTL(LSFT(KC_R))), LGUI(LCTL(LSFT(KC_S))), LGUI(LCTL(LSFT(KC_T))),
LGUI(LCTL(LALT(KC_Z))), LGUI(LCTL(LALT(KC_X))), LGUI(LCTL(LALT(KC_C))), LGUI(LCTL(LALT(KC_D))), _______, _______, LGUI(LCTL(LSFT(KC_Z))), LGUI(LCTL(LSFT(KC_X))), LGUI(LCTL(LSFT(KC_C))), LGUI(LCTL(LSFT(KC_D)))
)

};


// more tap dance stuff

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        // if (state->interrupted || !state->pressed) return SINGLE_TAP;
        if (!state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap ktap_state = {
    .is_press_action = true,
    .state = 0
};

void k_finished(qk_tap_dance_state_t *state, void *user_data) {
    ktap_state.state = cur_dance(state);
    switch (ktap_state.state) {
        case SINGLE_TAP: register_code(KC_K); break;
        case SINGLE_HOLD: layer_on(_RA); break;
        case DOUBLE_TAP: register_code(KC_SPACE); break;
        // case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case DOUBLE_SINGLE_TAP: tap_code(KC_K); register_code(KC_K);
        case DOUBLE_SINGLE_TAP: register_code(KC_SPACE);
    }
}

void k_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ktap_state.state) {
        case SINGLE_TAP: unregister_code(KC_K); break;
        case SINGLE_HOLD: layer_off(_RA); break;
        case DOUBLE_TAP: unregister_code(KC_SPACE); break;
        // case DOUBLE_HOLD: unregister_code(KC_LALT);
        // case DOUBLE_SINGLE_TAP: unregister_code(KC_K);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_SPACE);
    }
    ktap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [_K_RA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k_finished, k_reset),
    [_TD_SCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [_TD_Q]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};


/*
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _RA_K:
            return false;
        default:
            return true;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _RA_K:
            return true;
        default:
            return false;
    }
}
*/

// int RGB_current_mode;
// bool led_update_user(led_t led_state) {
//     if (led_state.caps_lock) {
//         RGB_current_mode = rgblight_config.mode;
//         rgblight_sethsv(0, 255, 180);
//     } else {
//         rgblight_mode(RGB_current_mode); 
//     }
//     return true;
// }