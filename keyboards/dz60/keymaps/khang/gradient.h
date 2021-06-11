#define MINIMAL_BASEx(hue,sat) \
    rgblight_sethsv_range(hue, sat,  0,  0, 16); \
    rgblight_sethsv_range(hue, sat, 50,  2, 3); \
    rgblight_sethsv_range(hue, sat, 50,  5, 6)

#define MINIMAL_BASE(hue, sat) \
		{0, 16, hue, sat, 0}, \
		{2,  1, hue, sat, 50}, \
		{5,  1, hue, sat, 50}

#define MINIMAL(hue, sat) \
		{0, 16, hue, sat, 0}, \
		{9,  6, hue, sat, 50}, \
		{10, 4, hue, sat, 80}, \
		{11, 2, hue, sat, 90}
