#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "colors.h"

bool fp_comp(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void test_f_abs() {
    float v1 = -1.234567;
    float v2 = 7.65431;

    float v1_expected = 1.234567;
    float v2_expected = 7.654321;

    float result1 = f_abs(v1);
    float result2 = f_abs(v2);

    if (fp_comp(result1, v1_expected, 0.001000)) {
	printf("test_f_abs 1: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_f_abs 1: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected %f got %f\n", v1_expected, result1);
    };

    if (fp_comp(result2, v2_expected, 0.001000)) {
	printf("test_f_abs 2: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_f_abs 2: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected %f got %f\n", v2_expected, result2);
    };
}

void test_min_rgb() {
    int result = min_rgb(255, 203, 104);

    if (result == 104) {
	printf("test_min_rgb: \x1b[38;2;0;255;0m Passed! \x1b[0m\n"); 
    } else {
	printf("test_min_rgb: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 104 got %i\n", result);
    };

    result = min_rgb(0, 0, 0);

    if (result == 0) {
	printf("test_min_rgb: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_min_rgb: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 0 got %i\n", result);
    };
}

void test_max_rgb() {
    int result = max_rgb(90, 243, 244);

    if (result == 244) {
	printf("test_max_rgb: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_max_rgb: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 244 got %i\n", result);
    };

    result = max_rgb(255, 255, 255);

    if (result == 255) {
	printf("test_max_rgb: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_max_rgb: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 255 got %i\n", result);
    };
}

void test_complementary() {
    cmColor colors;

    colors.red = 100;
    colors.green = 55;
    colors.blue = 255;

    int comp_red = 255 - colors.red;
    int comp_green = 255 - colors.green;
    int comp_blue = 255 - colors.blue;
    
    cmColor result;

    result.red = comp_red;
    result.green = comp_green;
    result.blue = comp_blue;

    if (result.red == 155 && result.green == 200 && result.blue == 0) {
	printf("test_complementary: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_complementary: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 155, 200, 0 got %i %i %i\n", result.red, result.green, result.blue);
    };
}

void test_get_HSV() {
    cmColor colors;

    float red = colors.red;
    float green = colors.green;
    float blue = colors.blue;

    red = 205;
    green = 34;
    blue = 182;

    float rf = red / 255, gf = green / 255, bf = blue / 255;
    float re = 0.803921, ge = 0.133333, be = 0.713725;

    float min = fmin_rgb(rf, gf, bf);
    float max = fmax_rgb(rf, gf, bf);

    if (fp_comp(rf, re, 0.001000) && fp_comp(gf, ge, 0.001000) && fp_comp(bf, be, 0.001000)) {
	printf("test_get_HSV pt1: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt1: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 0.803921 0.133333 0.713725 got %f %f %f\n", rf, gf, bf);
    };

    float c = max - min;

    float c_expected = 0.670588;

    if(fp_comp(c, c_expected, 0.001000)) {
	printf("test_get_HSV pt2: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt2: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 0.670588 got %f\n", c);
    };

    float h, s;
    float v = max;

    if (c == 0) {
	h = 0;
    } else if (v == rf) {
	h = 60 * (0 + (gf - bf) / c);
    } else if (v == gf) {
	h = 60 * (2 + (bf - rf) / c);
    } else {
	h = 60 * (4 + (rf - gf) / c);
    };

    float h_expected = -51.929828;

    if(fp_comp(h, h_expected, 0.001000)) {
	printf("test_get_HSV pt3: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt3: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected -51.929828 got %f\n", h);
    };

    if (h < 0) {
	h = h + 360;
    } else {
	h;
    };

    float adj_h_expected = 308.070171;

    if(fp_comp(h, adj_h_expected, 0.001000)) {
	printf("test_get_HSV pt4: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt4: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 308.070171 got %f\n", h);
    };

    if (v == 0) {
	s = 0;
    } else {
	s = c / v;
    };

    float s_expected = 0.834146;

    if (fp_comp(s, s_expected, 0.001000)) {
	printf("test_get_HSV pt5: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt5: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 0.834146 got %f\n", s);
    };

    v = v * 100;
    s = s * 100;

    float adj_v_expected = 80.3921;
    float adj_s_expected = 83.4146;

    if (fp_comp(v, adj_v_expected, 0.001000) && fp_comp(s, adj_s_expected, 0.001000)) {
	printf("test_get_HSV pt6: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV pt6: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 80.3921 83.4146 got %f %f\n", v, s);
    };

    cmHSV newHSV = get_HSV(colors);

    float final_h = newHSV.hue;
    float final_s = newHSV.saturation;
    float final_v = newHSV.value;

    float final_h_expected = 253.500000;
    float final_s_expected = 78.431374;
    float final_v_expected = 100.000000;

    if (fp_comp(final_h, final_h_expected, 0.001000)) {
	printf("test_get_HSV \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSV \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected %f %f %f got %f %f %f\n", final_h_expected, final_s_expected, final_v_expected, final_h, final_s, final_v);
    };
}

void test_get_HSL() {
    cmColor colors;
    
    float h, s, l;

    float red = colors.red = 94;
    float green = colors.green = 249;
    float blue = colors.blue = 123;

    float rf = red / 255, gf = green / 255, bf = blue / 255;

    float min = fmin_rgb(rf, gf, bf), max = fmax_rgb(rf, gf, bf);

    l = (max - min) / 2; // gf = 0.976470 rf = 0.368627, 0.607843 / 2 = 0.303921

    if (l < 0.5) {
	s = (max - min) / (max + min);
    } else {
	s = (max - min) / (2.0 - (max + min));
    };

    // 0.607843 / 1.345097 = 0.451895
    float s_expected = 0.451895;

    if (fp_comp(s, s_expected, 0.001000)) {
	printf("test_get_HSL pt1: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSL pt1: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected %f got %f\n", s_expected, s);
    };

    if (max == rf) {
	h = (gf - bf) / (max - min);
	if (max - min == 0) {
	    h = 0;
	};
    } else if (max == gf) {
	h = 2.0 + (bf - rf) / (max - min);
	if (max - min == 0) {
	    h = 0;
	};
    } else {
	h = 4.0 + (rf - gf) / (max - min);
	if (max - min == 0) {
	    h = 0;
	};
    };

    // bf = 0.482352 - rf = 0.368627 = 0.113725
    // gf = 0.976470 - rf = 0.368627 = 0.607843
    // 0.113725 / 0.607843 = 0.187096
    // 2 + 0.187096 = 2.187096

    float h_expected = 2.187096;

    if (fp_comp(h, h_expected, 0.001000)) {
	printf("test_get_HSL pt2: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSL pt2: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected 2.187096 got %f\n", h_expected);
    };

    if (h < 0) {
	h = h + 360;
    } else {
	h = h * 60;
    };

    float adj_h_expected = 131.22576;

    if (fp_comp(h, adj_h_expected, 0.001000)) {
	printf("test_get_HSL pt3: \x1b[38;2;0;255;0m Passed! \x1b[0m\n");
    } else {
	printf("test_get_HSL pt3: \x1b[38;2;255;0;0m Failed! \x1b[0m\n");
	printf("expected %f got %f\n", adj_h_expected, h);
    };
}

int main() {
    test_f_abs();
    test_min_rgb();
    test_max_rgb();
    test_complementary();
    test_get_HSV();
    test_get_HSL();

    return 0;
}
