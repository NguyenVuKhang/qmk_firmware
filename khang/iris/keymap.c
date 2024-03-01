/* Copyright 2023 Nguyen Vu Khang <brew4k@gmail.com>
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

/**
 * Khang's Iris Keymap
 *
 * - QWERTY at heart
 * - Space on right thumb
 * - Enter on left thumb
 * - Right-Shift as Fn
 * - Minimal (disabled everything unused to save space)
 */

#include QMK_KEYBOARD_H

enum keyboard_layers {
    BASE_L = 0,
    FUNC_L,
    SYS_L,
    UP_L,
};

#undef _______
#define ______ KC_NO
#define XXXXXX KC_NO
#define KC_STAB LSFT(KC_TAB)
#define MO_SYS MO(SYS_L)
#define MO_UP MO(UP_L)
#define MO_FN MO(FUNC_L)
#define TMUX LCTL(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    [BASE_L] = LAYOUT(
    //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
        KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                       KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_BSPC ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,KC_BSLS ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,KC_SCLN ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,KC_MINS ,    KC_EQL ,  KC_N  ,  KC_M  ,KC_COMM , KC_DOT ,KC_SLSH ,MO(FUNC_L) ,
    //╰────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────╯  ╰───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────╯
                                      KC_LGUI ,KC_LCTL , KC_ENT ,             KC_SPC , MO_UP  ,KC_RALT
    //                               ╰────────┴────────┴────────╯           ╰────────┴────────┴────────╯
    ),

    [UP_L] = LAYOUT(
    //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
       KC_TILD , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ ,KC_MINS , KC_EQL ,KC_BSPC ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        ______ , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ ,KC_LBRC ,KC_RBRC , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        ______ , ______ , ______ , ______ , ______ , ______ ,                     KC_LEFT ,KC_DOWN , KC_UP  ,KC_RGHT , ______ , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT , ______ , ______ , ______ , ______ , ______ , ______ ,    ______ , ______ , ______ , ______ , ______ , ______ , ______ ,
    //╰────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────╯  ╰───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────╯
                                      KC_LGUI ,  TMUX  , ______ ,             ______ , XXXXXX , ______
    //                               ╰────────┴────────┴────────╯           ╰────────┴────────┴────────╯
    ),

    [FUNC_L] = LAYOUT(
    //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
        ______ , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_STAB , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ , ______ , ______ , KC_F12 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        ______ , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ ,KC_BRID ,KC_BRIU , ______ , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        MO_SYS , ______ , ______ , ______ , ______ , ______ , ______ ,    ______ , ______ , ______ ,KC_VOLD ,KC_VOLU , ______ , XXXXXX ,
    //╰────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────╯  ╰───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────╯
                                       ______ , ______ , ______ ,            KC_MPLY ,KC_MPRV ,KC_MNXT
    //                               ╰────────┴────────┴────────╯           ╰────────┴────────┴────────╯
    ),

    [SYS_L] = LAYOUT(
    //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
        ______ , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ , ______ , ______ , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        ______ , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ , ______ , ______ , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
        ______ , ______ , ______ , ______ , ______ , ______ ,                      ______ , ______ , ______ , ______ , ______ , ______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXX , ______ , ______ , ______ , ______ , ______ , ______ ,    ______ , ______ , ______ , ______ , ______ , ______ , XXXXXX ,
    //╰────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────╯  ╰───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────╯
                                       GUI_ON , ______ , ______ ,            QK_BOOT , ______ , ______
    //                               ╰────────┴────────┴────────╯           ╰────────┴────────┴────────╯
        // clang-format on
        ),
};

#define ALL(hue, sat, lum) \
    { 0, 12, hue, sat, lum }
#define MINIMAL_IN(hue, sat, lum) \
    {0, 12, 0, 0, 0}, {           \
        5, 2, hue, sat, lum       \
    }

#define RGB_LAYER(name, segments) const rgblight_segment_t PROGMEM name[] = RGBLIGHT_LAYER_SEGMENTS(segments);

#define ALL_GREEN ALL(7, 250, 100)
#define ALL_BLUE MINIMAL_IN(99, 250, 100)
#define ALL_RED MINIMAL_IN(252, 250, 100)

RGB_LAYER(BASE_RGB, ALL_GREEN);
RGB_LAYER(FUNC_RGB, ALL_BLUE);
RGB_LAYER(SYS_RGB, ALL_RED);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(BASE_RGB, FUNC_RGB, SYS_RGB);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE_L));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, FUNC_L));
    rgblight_set_layer_state(2, layer_state_cmp(state, SYS_L));
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
