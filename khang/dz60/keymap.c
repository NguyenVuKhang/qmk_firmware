/* Copyright 2024 Nguyen Vu Khang <brew4k@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum keyboard_layers { BASE_L, FUNC_L, SYSTEM_L, DANGER_L };

#define MO_DGR MO(DANGER_L)
#define MO_SYS MO(SYSTEM_L)
#define MO_FN MO(FUNC_L)
#define XXXXXXX KC_NO
#define ZZ_LEFT RGUI_T(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [BASE_L] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, MO_FN  , _______,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC ,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT
    ),

    // https://docs.qmk.fm/#/keycodes
    //  [  ~  ]  [  1  ]  [  2  ]  [  3  ]  [  4  ]  [  5  ]  [  6  ]  [  7  ]  [  8  ]  [  9  ]  [  0  ]  [  -  ]  [  =  ]  [  ?  ]  [  ?  ]
    //  [ TAB ]  [  Q  ]  [  W  ]  [  E  ]  [  R  ]  [  T  ]  [  Y  ]  [  U  ]  [  I  ]  [  O  ]  [  P  ]  [  {  ]  [  }  ]  [ \|  ]
    //  [ ESC ]  [  A  ]  [  S  ]  [  D  ]  [  F  ]  [  G  ]  [  H  ]  [  J  ]  [  K  ]  [  L  ]  [  ;  ]  [  "  ]  [    ENTER     ]
    //  [ SFT ]  [  Z  ]  [  X  ]  [  C  ]  [  V  ]  [  B  ]  [  N  ]  [  M  ]  [ ,<  ]  [ .>  ]  [  /  ]  [   R SHIFT    ]
    //  [ CTL ]  [ ALT ]  [ CMD ]  [                       SPACE                      ]  [  ←  ]  [  ↓  ]  [  ↑  ]  [  →  ]

    [FUNC_L] = LAYOUT_60_ansi_split_bs_rshift(
        MO_DGR , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL ,
        _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO_SYS , XXXXXXX, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______
    ),

    [SYSTEM_L] = LAYOUT_60_ansi_split_bs_rshift(
        _______, KC_BRMD, KC_BRMU, KC_MCTL, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______
    ),

    [DANGER_L] = LAYOUT_60_ansi_split_bs_rshift(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______
    )
    // clang-format on
};

#define ONE(i, hue, lum) {i, 1, hue, 255, lum}

const rgblight_segment_t PROGMEM BASE_RGB[] =
    RGBLIGHT_LAYER_SEGMENTS(ONE(0x0, 190, 180),
                            ONE(0x1, 196, 180),
                            ONE(0x2, 202, 181),
                            ONE(0x3, 208, 181),
                            ONE(0x4, 214, 182),
                            ONE(0x5, 220, 182),
                            ONE(0x6, 226, 183),
                            ONE(0x7, 232, 183),
                            ONE(0x8, 6, 184),
                            ONE(0x9, 8, 184),
                            ONE(0xA, 11, 185),
                            ONE(0xB, 13, 185),
                            ONE(0xC, 16, 186),
                            ONE(0xD, 18, 186),
                            ONE(0xE, 21, 187),
                            ONE(0xF, 23, 187));

const rgblight_segment_t PROGMEM DANGER_RGB[] =
    RGBLIGHT_LAYER_SEGMENTS(ONE(0x0, 7, 180),
                            ONE(0x1, 6, 180),
                            ONE(0x2, 5, 180),
                            ONE(0x3, 4, 180),
                            ONE(0x4, 3, 180),
                            ONE(0x5, 2, 180),
                            ONE(0x6, 1, 180),
                            ONE(0x7, 0, 180),
                            ONE(0x8, 255, 180),
                            ONE(0x9, 254, 180),
                            ONE(0xA, 253, 180),
                            ONE(0xB, 252, 180),
                            ONE(0xC, 251, 180),
                            ONE(0xD, 250, 180),
                            ONE(0xE, 249, 180),
                            ONE(0xF, 248, 180));

const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(BASE_RGB, DANGER_RGB);

void keyboard_post_init_kb(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    // 0 here is the index of `my_rgb_layers`.
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE_L));
    return state;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    // 1 here is the index of `my_rgb_layers`.
    rgblight_set_layer_state(1, layer_state_cmp(state, DANGER_L));
    return state;
}

const key_override_t delete_key_override =
    ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL,
};

// These overrides save memory space.
// clang-format off
uint16_t keycode_config(uint16_t keycode) { return keycode; }
uint8_t mod_config(uint8_t mod) { return mod; }
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case KC_LBRC:
            if (is_key_pressed(KC_LEFT)) {
                register_code(KC_RGUI);
                tap_code(KC_LBRC);
                unregister_code(KC_RGUI);
                return false;
            }
        case KC_RBRC:
            if (is_key_pressed(KC_LEFT)) {
                register_code(KC_RGUI);
                tap_code(KC_RBRC);
                unregister_code(KC_RGUI);
                return false;
            }
        default:
            return true;
    }
}
