#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL = 0,     // BaseLayer
    _FL,         // FunctionLayer
    _SL,         // SystemLayer
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
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
    KC_NO,SGUI(KC_WHOM),KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  
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

// Turn on RGB underglow according to active layer
// uint32_t layer_state_set_user(uint32_t state) {
//     // int red=249;
//     int blue=140;
//     int 94=94;
//     int pink=252;
// 	switch (biton32(state)) {
// 		case _BL: // base layer
//             rgblight_sethsv_range(0, 0, 0, 0, 16);
//             rgblight_sethsv_range(94, 200, 50, 9, 15);
//             rgblight_sethsv_range(94, 200, 80, 10, 14);
//             rgblight_sethsv_range(94, 200, 90, 11, 13);
//             // instagram-looking configureation
//             // rgblight_sethsv_noeeprom(30, 250, 250);
//             // rgblight_mode(32);
//             break;
// 		case _FL: // function layer
//             rgblight_sethsv_range(0, 0, 0, 0, 16);
//             rgblight_sethsv_range(blue, 255, 50, 9, 15);
//             rgblight_sethsv_range(blue, 255, 80, 10, 14);
//             rgblight_sethsv_range(blue, 255, 90, 11, 13);
//             break;
// 		case _SL: // system mode
//             rgblight_sethsv_range(pink, 250, 250, 0, 16);
//             break;
// 	}
// 	return state;
// };

const rgblight_segment_t PROGMEM _BL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0 ,16, 0   ,0   ,0  },
    { 9, 6, 94, 255, 50},
    {10, 4, 94, 255, 80},
    {11, 2, 94, 255, 90}
);
const rgblight_segment_t PROGMEM _FL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0 ,16, 0   ,0   ,0  },
    { 9, 6, 140, 255, 50},
    {10, 4, 140, 255, 80},
    {11, 2, 140, 255, 90}
);
const rgblight_segment_t PROGMEM _SL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0 ,16, 252, 255, 255}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    _BL_rgblayer,
    _FL_rgblayer,
    _SL_rgblayer
);

void keyboard_post_init_user(void) {
    rgblight_sethsv_range(0, 0, 0, 0, 16);
    rgblight_sethsv_range(94, 200, 50, 9, 15);
    rgblight_sethsv_range(94, 200, 80, 10, 14);
    rgblight_sethsv_range(94, 200, 90, 11, 13);
    rgblight_layers = my_rgb_layers;
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SL));
    return state;
}
