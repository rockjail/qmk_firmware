#include QMK_KEYBOARD_H


#define _CM 0
#define _QW 1
#define _FN 2
#define _LO 3
#define _RA 4

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
  KX_DEG,
};

/* Holds state of modifiers when Backspace was pressed.
 * Used to ensure that the correct keycode is unregistered when Backspace is released.
 */
// static uint8_t bspc_mods = 0;


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
    {
        SS_TAP(X_RALT)"oo",
        SS_TAP(X_RALT)"oo",
    },
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_CM] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_HOME,          KC_PGUP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_END,           KC_PGDN, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_ESC,           KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, FUNCT,            LOWER,   KC_SPC,           KC_SPC,  RAISE,            FUNCT,   KC_RALT, KC_RGUI, KC_RCTL
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),


  [_QW] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, FUNCT,            LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),


 [_FN] = LAYOUT( /* FUNCTION */
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,            _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,            _______,   _______, DF(_CM), DF(_QW), _______, _______, _______,
  _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, RESET,              _______,   _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
  _______, _______, _______, FUNCT,            _______, _______,            _______,   _______,          FUNCT,   _______, _______, _______
 ),


 [_LO] = LAYOUT( /* LOWER */
   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_VOLU,          KC_MNXT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
   KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_VOLD,          KC_MPRV, KC_CIRC, KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, _______,
   _______, KC_TILD, KX_DEG,  KC_PIPE, KC_GRV,  _______, KC_MUTE,          KC_MPLY, KC_BSLS, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______,
   _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
 ),


 [_RA] = LAYOUT( /* RAISE */
   _______, _______, _______, _______, _______, _______, KC_VOLU,            KC_MNXT, _______, _______, KX_UE,   _______, _______, _______ ,
   _______, KX_AE,   _______, KX_SS,   _______, _______, KC_VOLD,            KC_MPRV, _______, _______, KX_EURO, _______, KX_OE,   _______ ,
   _______, _______, _______, _______, _______, _______, KC_MUTE,            KC_MPLY, _______, _______, _______, _______, _______, _______ ,
   _______, _______, _______, _______,          _______, _______,            _______, _______,          _______, _______, _______, _______ 
 ),

  // [_ADJUST] = LAYOUT(
  //    TSKMGR,  _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL,
  //    _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
  //    _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, _______, _______, _______, _______, BL_STEP,
  //    _______, _______, _______, _______,           _______, _______,         _______,  _______,          _______, _______, _______, RESET
  // )

}; // end keymaps



bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) return true;
    
    switch (keycode) {
    case KX_AE: case KX_OE: case KX_UE: case KX_SS: case KX_EURO: {
        uint16_t index = keycode - KX_AE;
        uint8_t shift = get_mods()&MODS_SHIFT_MASK;
        
        unregister_code(KC_LSFT); // Gotta temporarily disable both shift keys, else this whole thing may behave oddly
        unregister_code(KC_RSFT);
        
        // Choose Alt code based on which key was pressed and whether Shift was held.
        send_string(alt_codes[index][ (bool)shift]);
        
        
        if (shift &MOD_BIT(KC_LSFT)) register_code(KC_LSFT); // Restore shift keys to previous state
        if (shift &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);
        
        return false;
        break;
    }
    default:
        return true;
        break;
    }
};