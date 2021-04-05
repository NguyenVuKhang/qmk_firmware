#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL = 0,     // BaseLayer
    _FL1,        // FunctionLayer1
};

enum custom_keycodes {
    THINGS = SAFE_RANGE,
    TERMINAL,
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
            static bool backslash_registered;
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
                } else if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_BSLS);
                    backslash_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                } else if (backslash_registered) {
                    unregister_code(KC_BSLS);
                    backslash_registered = false;
                    return false;
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
    [_BL] = LAYOUT_60_ansi_split_backspace(
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  MO(_FL1),
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
    KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT ),

//  FunctionLayer1
    [_FL1] = LAYOUT_60_ansi_split_backspace(
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    RESET,    RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,
    XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  A(KC_BSPC),
    XXXXXXX,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,
    XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,
    XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT)
};

// sets the static color to a familiar yellow
extern rgblight_config_t rgblight_config;
void keyboard_post_init_user(void) {
    rgblight_config.hue = 34;
    rgblight_config.sat = 250;
    rgblight_config.val = 250;
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _BL:
            // rgblight_config.hue = 34;
            // rgblight_config.sat = 250;
            // rgblight_config.val = 250;
            // rgblight_mode(32);
            rgblight_disable();
            break;
        case _FL1:
            rgblight_enable();
            rgblight_sethsv_noeeprom(HSV_AZURE);
        break;
    }
    return state;
}
