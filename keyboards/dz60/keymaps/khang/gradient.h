#define GRADIENT(start,inc,sat,val) \
		{0,  1, start +  0 * inc, sat, val}, \
		{1,  1, start +  1 * inc, sat, val}, \
		{2,  1, start +  2 * inc, sat, val}, \
		{3,  1, start +  3 * inc, sat, val}, \
		{4,  1, start +  4 * inc, sat, val}, \
		{5,  1, start +  5 * inc, sat, val}, \
		{6,  1, start +  6 * inc, sat, val}, \
		{7,  1, start +  7 * inc, sat, val}, \
		{8,  1, start +  8 * inc, sat, val}, \
		{9,  1, start +  9 * inc, sat, val}, \
		{10, 1, start + 10 * inc, sat, val}, \
		{11, 1, start + 11 * inc, sat, val}, \
		{12, 1, start + 12 * inc, sat, val}, \
		{13, 1, start + 13 * inc, sat, val}, \
		{14, 1, start + 14 * inc, sat, val}, \
		{15, 1, start + 15 * inc, sat, val} 

#define GRADIENTx(start,inc,sat,val) \
    rgblight_sethsv_range(start +  0 * inc, sat, val,  0,  1); \
    rgblight_sethsv_range(start +  1 * inc, sat, val,  1,  2); \
    rgblight_sethsv_range(start +  2 * inc, sat, val,  2,  3); \
    rgblight_sethsv_range(start +  3 * inc, sat, val,  3,  4); \
    rgblight_sethsv_range(start +  4 * inc, sat, val,  4,  5); \
    rgblight_sethsv_range(start +  5 * inc, sat, val,  5,  6); \
    rgblight_sethsv_range(start +  6 * inc, sat, val,  6,  7); \
    rgblight_sethsv_range(start +  7 * inc, sat, val,  7,  8); \
    rgblight_sethsv_range(start +  8 * inc, sat, val,  8,  9); \
    rgblight_sethsv_range(start +  9 * inc, sat, val,  9, 10); \
    rgblight_sethsv_range(start + 10 * inc, sat, val, 10, 11); \
    rgblight_sethsv_range(start + 11 * inc, sat, val, 11, 12); \
    rgblight_sethsv_range(start + 12 * inc, sat, val, 12, 13); \
    rgblight_sethsv_range(start + 13 * inc, sat, val, 13, 14); \
    rgblight_sethsv_range(start + 14 * inc, sat, val, 14, 15); \
    rgblight_sethsv_range(start + 15 * inc, sat, val, 15, 16);
