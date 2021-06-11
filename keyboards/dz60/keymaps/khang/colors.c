const int yel = 33;
const int gre = 99;
const int red = 252;
const int blu = 140;
const int base_sat = 120;

const rgblight_segment_t PROGMEM _BL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
	  MINIMAL_BASE(yel,200)
);
const rgblight_segment_t PROGMEM _FL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
		MINIMAL(gre,255)
);
const rgblight_segment_t PROGMEM _SL_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
		MINIMAL(red,255)
);
const rgblight_segment_t PROGMEM _BF_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
		MINIMAL(blu,255)
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    _BL_rgblayer,
    _FL_rgblayer,
    _SL_rgblayer,
    _BF_rgblayer
);
void keyboard_post_init_user(void) {
		MINIMAL_BASEx(yel,200);
    rgblight_layers = my_rgb_layers;
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_mode(32);
    // rgblight_sethsv(34, 250, 250);
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _BF));
    return state;
}

// IG
// rgblight_config.hue = 34;
// rgblight_config.sat = 250;
// rgblight_config.val = 250;
// rgblight_mode(32);
// rgblight_sethsv(34, 250, 250);
