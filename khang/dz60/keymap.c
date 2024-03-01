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

#undef S
#define ONE(i, hue, sat, lum) \
    { i, 1, hue, sat, lum }
#define I(i, h, s, v) ONE(i, h(i), s(i), v(i))
#define ALL_16 I(0, H, S, L), I(1, H, S, L), I(2, H, S, L), I(3, H, S, L), I(4, H, S, L), I(5, H, S, L), I(6, H, S, L), I(7, H, S, L), I(8, H, S, L), I(9, H, S, L), I(10, H, S, L), I(11, H, S, L), I(12, H, S, L), I(13, H, S, L), I(14, H, S, L), I(15, H, S, L)

#define H(i) i < 8 ? (190 + i * 6) % 256 : 6 + ((i - 8) * 5 / 2)
#define S(i) 255
#define L(i) 180 + i / 2
const rgblight_segment_t PROGMEM BASE_RGB[] = RGBLIGHT_LAYER_SEGMENTS(ALL_16);
#undef H
#undef S
#undef L

#define H(i) (7 - i) % 256
#define S(i) 255
#define L(i) 180
const rgblight_segment_t PROGMEM DANGER_RGB[] = RGBLIGHT_LAYER_SEGMENTS(ALL_16);
#undef H
#undef S
#undef L

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(BASE_RGB, DANGER_RGB);
// tied to the order in `my_rgb_layers`
enum myrgb_layers { RGB_BASE, RGB_DANGER };

void keyboard_post_init_kb(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(RGB_BASE, layer_state_cmp(state, BASE_L));
    return state;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(RGB_DANGER, layer_state_cmp(state, DANGER_L));
    return state;
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL,
};

// These overrides save memory space.
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
