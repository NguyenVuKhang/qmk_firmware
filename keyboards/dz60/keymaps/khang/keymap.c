#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL = 0,     // BaseLayer
    _FL1,        // FunctionLayer1
    _FL2,        // FunctionLayer2
    _APPS,       // AppLaunchingLayer
};

enum custom_keycodes {
    THINGS = SAFE_RANGE,
    TERMINAL,
    CALENDAR,
    NOTES,  
    SPOTIFY,
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
                } else if (mod_state & MOD_MASK_GUI) {
                    del_mods(MOD_MASK_GUI);
                    register_code16(A(KC_BSPC));
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of control
            return true;
        };

        case THINGS: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) "things" SS_TAP(X_ENT));
            } else {
                // when keycode is released
                return false;
            }
            return false;
            break;
        };

        case CALENDAR: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) "calendar" SS_TAP(X_ENT));
            } else {
                // when keycode is released
                return false;
            }
            return false;
            break;
        };

        case TERMINAL: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) "terminal" SS_TAP(X_ENT));
            } else {
                // when keycode is released
                return false;
            }
            return false;
            break;
        };

        case NOTES: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) "notes" SS_TAP(X_ENT));
            } else {
                // when keycode is released
                return false;
            }
            return false;
            break;
        };

        case SPOTIFY: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) "safari" SS_TAP(X_ENT));
            } else {
                // when keycode is released
                return false;
            }
            return false;
            break;
        };

        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_60_calbatr0ss(
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
    KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_APPS),
    KC_LCTL,  KC_LALT,  KC_LGUI,            MT(MOD_RGUI,KC_SPC),          MO(_FL1),           KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT),

//  FunctionLayer1
    [_FL1] = LAYOUT_60_calbatr0ss(
//  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
//  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
//  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
//  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_APPS),
//  KC_LCTL,  KC_LALT,  KC_LGUI,            LT(_FL2,KC_SPC),              MO(_FL1),           KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT),
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    RESET,    RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    RGB_TOG,  RGB_MOD,  RGB_RMOD, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    A(KC_BSPC),
    KC_NO,    RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MPLY,
    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,              KC_NO,    KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT),

//  FunctionLayer2
    [_FL2] = LAYOUT_60_calbatr0ss(
//  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
//  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
//  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
//  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_APPS),
//  KC_LCTL,  KC_LALT,  KC_LGUI,            LT(_FL2,KC_SPC),              MO(_FL1),           KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT),
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    RESET,    RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    RGB_TOG,  RGB_MOD,  RGB_RMOD, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    A(KC_BSPC),
    KC_NO,    RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MPLY,
    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,              KC_NO,    KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT),

//  AppLaunchingLayer
    [_APPS] = LAYOUT_60_calbatr0ss(
//  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
//  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
//  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
//  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_APPS),
//  KC_LCTL,  KC_LALT,  KC_LGUI,            LT(_FL2,KC_SPC),              MO(_FL),            KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT),
// |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    THINGS,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    SPOTIFY,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    CALENDAR, TERMINAL, KC_NO,    NOTES,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO),
};

// sets the static color to a familiar yellow
extern rgblight_config_t rgblight_config;
void keyboard_post_init_user(void) {
  rgblight_config.hue    = 34;
  rgblight_config.sat    = 250;
  rgblight_config.val    = 250;
}
