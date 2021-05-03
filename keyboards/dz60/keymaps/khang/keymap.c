#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL = 0,     // BaseLayer
    _FL,         // FunctionLayer
    _SL,         // SystemLayer
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            // static bool backslash_registered;
            if (record->event.pressed) {
                // Detect the activation of either control keys
                if (mod_state & MOD_MASK_CTRL) {
                    // First temporarily canceling both controls so that
                    // control isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held control key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                // } else if (mod_state & MOD_MASK_SHIFT) {
                //     del_mods(MOD_MASK_SHIFT);
                //     register_code16(KC_BSLS);
                //     backslash_registered = true;
                //     set_mods(mod_state);
                //     return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                //} else if (backslash_registered) {
                //    unregister_code(KC_BSLS);
                //    backslash_registered = false;
                //    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of control
            return true;
        };
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BaseLayer
    [_BL] = LAYOUT_60_ansi_split_backspace(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  MO(_FL),
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
    KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT ),

    // FunctionLayer
    [_FL] = LAYOUT_60_ansi_split_backspace(
    MO(_SL),  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BRID,  KC_BRIU,  KC_NO,  
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
    KC_NO,    KC_NO,    KC_NO,                                  KC_NO,                        KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT),

    // SystemLayer
    [_SL] = LAYOUT_60_ansi_split_backspace(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    SGUI(KC_WHOM),KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
    KC_NO,    KC_NO,    KC_NO,                                  RESET,                        KC_NO,    KC_NO,    KC_NO,    KC_NO),

//  template layer
//  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
//  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
//  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
//  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
//  KC_NO,    KC_NO,    KC_NO,                                  KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO),
};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}

// Turn on RGB underglow according to active layer
uint32_t layer_state_set_user(uint32_t state) {
    // int red=249;
    int blue=140;
    int green=94;
    int pink=252;
	switch (biton32(state)) {
		case _BL: // base layer
            rgblight_sethsv_range(0, 0, 0, 0, 16);
            rgblight_sethsv_range(green, 200, 50, 9, 15);
            rgblight_sethsv_range(green, 200, 80, 10, 14);
            rgblight_sethsv_range(green, 200, 90, 11, 13);
            // instagram-looking configureation
            // rgblight_sethsv_noeeprom(30, 250, 250);
            // rgblight_mode(32);
            break;
		case _FL: // function layer
            rgblight_sethsv_range(0, 0, 0, 0, 16);
            rgblight_sethsv_range(blue, 255, 50, 9, 15);
            rgblight_sethsv_range(blue, 255, 80, 10, 14);
            rgblight_sethsv_range(blue, 255, 90, 11, 13);
            break;
    //  case _WL: // window management layer
    //      rgblight_sethsv_range(0, 0, 0, 0, 16);
    //      rgblight_sethsv_range(red, 255, 50, 9, 15);
    //      rgblight_sethsv_range(red, 255, 80, 10, 14);
    //      rgblight_sethsv_range(red, 255, 90, 11, 13);
    //      break;
		case _SL: // system mode (mostly for bootloader)
            rgblight_sethsv_range(pink, 250, 250, 0, 16);
            break;
		default:
            rgblight_sethsv_noeeprom(0, 0, 0);
            break;
	}
	return state;
};
