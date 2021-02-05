/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _CM 0
#define _QW 1
#define _GA 3
#define _FN 4
#define _LO 5
#define _RA 6

#define RAISE MO(_RA)
#define LOWER MO(_LO)
#define FUNCT MO(_FN)
    
#define _______ KC_TRNS

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum custom_keycodes {
	KX_AE = SAFE_RANGE,
	KX_OE,
	KX_UE,
	KX_SS,
	KX_EURO,
};

/* Holds state of modifiers when Backspace was pressed.
 * Used to ensure that the correct keycode is unregistered when Backspace is released.
 */
static uint8_t bspc_mods = 0;


/*
char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2)), // Alt+0252 → ü
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_0)), // Alt+0220 → Ü
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // Alt+0223 → ß
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // Alt+0223 → ß
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
    },
};
*/
char *alt_codes[][2] = {
    {
        SS_TAP(X_RALT)"\"a",
        SS_TAP(X_RALT)"\"A",
    },
    {
        SS_TAP(X_RALT)"\"o",
        SS_TAP(X_RALT)"\"O",
    },
    {
        SS_TAP(X_RALT)"\"u",
        SS_TAP(X_RALT)"\"U",
    },
    {
        SS_TAP(X_RALT)"ss",
        SS_TAP(X_RALT)"SS",
    },
    {
        SS_TAP(X_RALT)"=E",
        SS_TAP(X_RALT)"=E",
    },
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK Mod DH ortholinear
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------| 2      | 3      | 4      | 5      |      | 6      | 7      | 8      | 9      |-----------------.
 * | GESC   | 1      +--------+--------+--------+--------|      |--------+--------+--------+--------+ 0      | MUTE   |
 * |--------+--------| W      | F      | P      | B      |      | J      | L      | U      | Y      |--------+--------|
 * | TAB    | Q      +--------+--------+--------+--------|      |--------+--------+--------+--------+ ;      | '      |
 * |--------+--------| R      | S      | T      | G      |      | M      | N      | E      | I      |--------+--------|
 * | BACKSP | A      +--------+--------+--------+--------|      |--------+--------+--------+--------+ O      | ENTER  |
 * |--------+--------| X      | C      | D      | V      |      | K      | H      | ,      | .      |--------+--------|
 * | LSHIFT | Z      +--------+--------+--------+--------|      |--------+--------+--------+--------+ /      | RSHIFT |
 * '-----------------| [      | ]      |                 |      |                 | -      | =      |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     | LOWER  | FUNC   |      | SPACE  | RAISE  |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     | ALT    | LCTRL  |      | RCTRL  | ALT    |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     | HOME   | LGUI   |      | RGUI   | END    |
 *                                     '-----------------'      '-----------------'
 */
  [_CM] = LAYOUT_5x6(
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MUTE,
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
     KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,           KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       KC_LBRC, KC_RBRC,                                            KC_MINS, KC_EQL,
                                         FUNCT,   LOWER,          KC_SPC,  RAISE,
                                         KC_LALT, KC_LCTL,        KC_RCTL, KC_RALT,
                                         KC_HOME, KC_LGUI,        KC_RGUI, KC_END
  ),
            
/* QWERTY
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------|        |        |        |        |      |        |        |        |        |-----------------.
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------| W      | E      | R      | T      |      | Y      | U      | I      | O      |--------+--------|
 * |        | Q      +--------+--------+--------+--------|      |--------+--------+--------+--------+ P      |        |
 * |--------+--------| S      | D      | F      | G      |      | H      | J      | K      | L      |--------+--------|
 * |        | A      +--------+--------+--------+--------|      |--------+--------+--------+--------+ ;      |        |
 * |--------+--------| X      | C      | V      | B      |      | N      | M      | ,      | .      |--------+--------|
 * |        | Z      +--------+--------+--------+--------|      |--------+--------+--------+--------+ /      |        |
 * '-----------------| [      | ]      |                 |      |                 | -      | =      |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     |        |        |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      |        |        |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     |        |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */
  [_QW] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                       KC_LBRC, KC_RBRC,                                            KC_MINS, KC_EQL,
                                         _______, _______,        _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, _______,        _______, _______
  ),

/* GAME
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------|        |        |        |        |      |        |        |        |        |-----------------.
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------| Q      | W      | E      | R      |      | Y      | U      | I      | O      |--------+--------|
 * |        | T      +--------+--------+--------+--------|      |--------+--------+--------+--------+ P      |        |
 * |--------+--------| A      | S      | D      | F      |      | H      | J      | K      | L      |--------+--------|
 * | LSHIFT | G      +--------+--------+--------+--------|      |--------+--------+--------+--------+ ;      |        |
 * |--------+--------| Z      | X      | C      | V      |      | N      | M      | ,      | .      |--------+--------|
 * | BACKSP | B      +--------+--------+--------+--------|      |--------+--------+--------+--------+ /      |        |
 * '-----------------| [      | ]      |                 |      |                 | -      | =      |-----------------'
 *                   '--------------------------|--------|      |--------+--------|-----------------'
 *                                     |        | SPACE  |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      |        |        |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     | FUNCT  |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */
  [_GA] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
     KC_LSFT, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
     KC_BSPC, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                       KC_LBRC, KC_RBRC,                                            KC_MINS, KC_EQL,
                                         _______, KC_SPC,         _______, _______,
                                         _______, _______,        _______, _______,
                                         FUNCT,   _______,        _______, _______
  ),

 /* FUNCTION
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------| F2     | F3     | F4     | F5     |      | F6     | F7     | F8     | F9     |-----------------.
 * | F12    | F1     +--------+--------+--------+--------|      |--------+--------+--------+--------+ F10    | F11    |
 * .-----------------| F2     | F3     | F4     | F5     |      | F6     | F7     | F8     | F9     |-----------------.
 * | F12    | F1     +--------+--------+--------+--------|      |--------+--------+--------+--------+ F10    | F11    |
 * |--------+--------| UP     | DOWN   | RIGHT  |        |      | QWERTY | COLEMAK| GAME   |        |--------+--------|
 * | DELETE | LEFT   +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        |        |        |        |      |        |        |        |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * '-----------------|        | DELETE |                 |      |                 |        |        |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     |        |        |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      | RESET  |        |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     |        |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */
  [_FN] = LAYOUT_5x6(
     KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,        KC_F6  ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , 
     KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,        KC_F6  ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , 
     KC_DEL,  KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, _______,        DF(_QW), DF(_CM), DF(_GA), _______, _______, _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                       _______, KC_DEL,                                             _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, _______,        RESET,   _______,
                                         _______, _______,        _______, _______
  ),
/* RAISE
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------|        |        |        |        |      |        |        |        |        |-----------------.
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        |        |        |        |      |        |        | Ü      |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        | ß      |        |        |      |        |        | EURO   |        |--------+--------|
 * |        | Ä      +--------+--------+--------+--------|      |--------+--------+--------+--------+ Ö      |        |
 * |--------+--------|        |        |        |        |      |        |        |        |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+ \      |        |
 * '-----------------|        |        |                 |      |                 |        |        |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     |        |        |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      |        |        |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     |        |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */

  [_RA] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, KX_UE,   _______, _______, _______,
     _______, KX_AE,   _______, KX_SS,   _______, _______,        _______, _______, KX_EURO, _______, KX_OE,   _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, KC_BSLS, _______,
                       _______, _______,                                            _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, RESET,          RESET,   _______,
                                         _______, _______,        _______, _______
  ),

/* LOWER
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------|        |        |        |        |      |        |        |        |        |-----------------.
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * .-----------------| 2      | 3      | 4      | 5      |      | 6      | 7      | 8      | 9      |-----------------.
 * |        | 1      +--------+--------+--------+--------|      |--------+--------+--------+--------+ 0      |        |
 * |--------+--------| @      | #      | $      | %      |      | ^      | -      | =      | (      |--------+--------|
 * |        | !      +--------+--------+--------+--------|      |--------+--------+--------+--------+ )      |        |
 * |--------+--------|        | |      | `      |        |      |        | &      | *      | [      |--------+--------|
 * |        | ~      +--------+--------+--------+--------|      |--------+--------+--------+--------+ ]      |        |
 * '-----------------|        |        |                 |      |                 |        |        |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     |        |        |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      |        |        |                  
 *                                     |-----------------|      |-----------------|                  \\\\\\/?\\\/\/\/
 *                                     |        |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */

  [_LO] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, _______,
     _______, KC_TILD, _______, KC_PIPE, KC_GRV,  _______,        _______, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______,
                       _______, _______,                                            _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, RESET,          RESET,   _______,
                                         _______, _______,        _______, _______
  ),

  /*
  [_RA] = LAYOUT_5x6(

     KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
     _______, _______, _______, _______, _______, KC_LBRC,        KC_RBRC,  KC_P7 ,  KC_P8 ,  KC_P9 , _______, KC_PLUS, 
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,        KC_RPRN,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_MINS, KC_PIPE, 
     _______, _______, _______, _______, _______, RESET  ,        RESET  ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_EQL , KC_UNDS, 
                                _______, KC_PSCR,                                    _______, KC_P0, 
                                         _______, _______,        _______, _______, 
                                         _______, _______,        _______, _______, 
                                         _______, _______,        _______, _______

  ), 
  */
  /*
  [_LO] = LAYOUT_5x6(
     KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,          KC_F6  ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , 
     _______, _______, _______, _______, _______, KC_LBRC,          KC_RBRC, _______, KC_NLCK, KC_INS , KC_SLCK, KC_MUTE, 
     _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,          KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU, 
     _______, _______, _______, _______, _______, RESET  ,          RESET  , _______, _______, _______, _______, KC_VOLD, 
                       _______, _______,                                              KC_EQL , _______, 
                                         _______, _______,          _______, _______, 
                                         _______, _______,          _______, _______, 
                                         _______, _______,          _______, _______
  ),
  */

/* EMPTY
 *                   .-----------------------------------.      .-----------------------------------.
 * .-----------------|        |        |        |        |      |        |        |        |        |-----------------.
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        |        |        |        |      |        |        |        |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        |        |        |        |      |        |        |        |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * |--------+--------|        |        |        |        |      |        |        |        |        |--------+--------|
 * |        |        +--------+--------+--------+--------|      |--------+--------+--------+--------+        |        |
 * '-----------------|        |        |                 |      |                 |        |        |-----------------'
 *                   '-----------------|--------+--------|      |--------+--------|-----------------'
 *                                     |        |        |      |        |        |                  
 *                                     +-----------------|      |-----------------+                  
 *                                     |        |        |      |        |        |                  
 *                                     |-----------------|      |-----------------|                  
 *                                     |        |        |      |        |        |
 *                                     '-----------------'      '-----------------'
 */
/*
  [_EM] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                       _______, _______,                                            _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, _______,        _______, _______,
                                         _______, _______,        _______, _______
  ),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    //if (!record->event.pressed) return true;
    
    switch (keycode) {
    // umlaute
    case KX_AE: case KX_OE: case KX_UE: case KX_SS: case KX_EURO: {
        if (record->event.pressed) {    
            uint16_t index = keycode - KX_AE;
            uint8_t shift = get_mods()&MODS_SHIFT_MASK;
            
            // Gotta temporarily disable both shift keys, else this whole thing may behave oddly
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            
            // Choose Alt code based on which key was pressed and whether Shift was held.
            send_string(alt_codes[index][ (bool)shift]);
            
            if (shift &MOD_BIT(KC_LSFT)) register_code(KC_LSFT); // Restore shift keys to previous state
            if (shift &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);
            
            return false;
        }
    }
    // shift + backspace = delete
    case KC_BSPC: {
        if (record->event.pressed) {
            const uint8_t current_mods = get_mods();
            const uint8_t shift = current_mods & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));
            const uint8_t ctrl = current_mods & (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL));
            bspc_mods = current_mods;
            if(shift || ctrl) {
                add_key(KC_DEL);
                add_mods(current_mods);
                send_keyboard_report();
            } else {
                return true;
            }
        }
        else {
            if(bspc_mods & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL))) {
                // if Shift or Ctrl was pressed with Backspace, than that was intepreted as Del, so we need
                // to unregister the Del key
                del_key(KC_DEL);
            } else {
                // Either Backspace was pressed without mods, or with a modifier other than Shift or Ctrl
                // so it is simply taken as Backspace
                del_key(KC_BSPC);
            }
            send_keyboard_report();
        }
        return false;
    }
    default:
        return true;
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
//   if (index == 1) { // only have one encoder so don't need this, but never know what happens in the future
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
//   }
}


/*
#shift + backspace = delete
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_BSPC: {
            if (record->event.pressed) {
                const uint8_t current_mods = get_mods();
                const uint8_t shift = current_mods & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));
                const uint8_t ctrl = current_mods & (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL));
                bspc_mods = current_mods;
                if(shift || ctrl) {
                    add_key(KC_DEL);
                    add_mods(current_mods);
                    send_keyboard_report();
                } else {
                    return true;
                }
            }
            else {
                if(bspc_mods & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL))) {
                    // if Shift or Ctrl was pressed with Backspace, than that was intepreted as Del, so we need
                    // to unregister the Del key
                    del_key(KC_DEL);
                } else {
                    // Either Backspace was pressed without mods, or with a modifier other than Shift or Ctrl
                    // so it is simply taken as Backspace
                    del_key(KC_BSPC);
                }
                send_keyboard_report();
            }
            return false;
        }
        default:
            return true;
    }
}
*/
