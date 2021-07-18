#define MINIMAL_BASEx(hue,sat) \
    rgblight_sethsv_range(hue, sat, 0,  0, 12); \
    rgblight_sethsv_range(hue, sat, 100,  5, 7)

#define MINIMAL_BASE(hue, sat) \
		{0,  12, hue, sat, 0}, \
		{5,  2, hue, sat, 100}

#define MINIMAL(hue, sat) \
		{0,  12, hue, sat, 0}, \
		{3,  1, hue, sat, 100}, \
		{8,  1, hue, sat, 100}
