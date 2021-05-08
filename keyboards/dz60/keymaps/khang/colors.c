const rgblight_segment_t PROGMEM _BL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0 ,16, 0   ,0   ,0  },
    { 9, 6, 99, 255, 50},
    {10, 4, 99, 255, 80},
    {11, 2, 99, 255, 90}
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
