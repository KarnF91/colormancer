#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "colors.h"

float f_abs(float v) {
    uint32_t bits = *(uint32_t*)&v;
    bits &= 0x7fffffff;
    return *(float*)&bits;
}

float f_mod(float x, float y) {
    return x - (y * (x / y));
}

cmColor base_color(cmColor colors) {
    int red = colors.red;
    int green = colors.green;
    int blue = colors.blue;

    printf("RGB: %i %i %i: \x1b[48;2;%i;%i;%im          \x1b[0m\n", red, green, blue, red, green, blue);
}

int min_rgb(int r, int g, int b) {
    if (r < g && r < b) {
	return r;
    } else if (g < b) {
	return g;
    } else {
	return b;
    };
}

int max_rgb(int r, int g, int b) {
    if (r > g && r > b) {
	return r;
    } else if (g > b) {
	return g;
    } else {
	return b;
    };
}

float fmin_rgb(float r, float g, float b) {
    cmColor colors;

    int red = colors.red;
    int green = colors.green;
    int blue = colors.blue;

    float rf = red / 255;
    float gf = green / 255;
    float bf = blue / 255;

    if (r < g && r < b) {
	return r;
    } else if (g < b) {
	return g;
    } else {
	return b;
    };
}

float fmax_rgb(float r, float g, float b) {
    cmColor colors;

    int red = colors.red;
    int green = colors.green;
    int blue = colors.blue;

    float rf = red / 255;
    float gf = green / 255;
    float bf = blue / 255;

    if (r > g && r > b) {
	return r;
    } else if (g > b) {
	return g;
    } else {
	return b;
    };
}

cmColor complementary(cmColor colors) {
    int max_red = 255;
    int max_green = 255;
    int max_blue = 255;

    int comp_red = max_red - colors.red;
    int comp_green = max_green - colors.green;
    int comp_blue = max_blue - colors.blue;

    printf("RGB: %i %i %i: \x1b[48;2;%i;%i;%im          \x1b[0m\n", comp_red, comp_green, comp_blue, comp_red, comp_green, comp_blue);
}

cmHSV get_HSV(cmColor colors) {
    cmHSV hsv;
    
    float h = hsv.hue;
    float s = hsv.saturation;
    float v = hsv.value;

    float red = colors.red;
    float green = colors.green;
    float blue = colors.blue;

    float rf = red / 255, gf = green / 255, bf = blue / 255;
    
    float min = fmin_rgb(rf, gf, bf);
    float max = fmax_rgb(rf, gf, bf);

    float c = max - min;

    if (c == 0) {
	h = 0;
    } else if (v == rf) {
	h = 60 * (0 + (gf - bf) / c);
    } else if (v == gf) {
	h = 60 * (2 + (bf - rf) / c);
    } else {
	h = 60 * (4 + (rf - gf) / c);
    };

    if (h < 0) {
	h = h + 360;
    } else {
	h;
    };
 
    v = max;

    if (v == 0) {
	s = 0;
    } else {
	s = c / v;
    };

    v = v * 100;
    s = s * 100;

    printf("HSV: %f %f %f\n", h, s, v);

    hsv.hue = h;
    hsv.saturation = s;
    hsv.value = v;

    return hsv;
}

cmHSL get_HSL(cmColor colors) {
    cmHSL hsl;

    float h = hsl.hue;
    float s = hsl.saturation;
    float l = hsl.lightness;

    float red = colors.red;
    float green = colors.green;
    float blue = colors.blue;

    float rf = red / 255, gf = green / 255, bf = blue / 255;

    float min = fmin_rgb(rf, gf, bf);
    float max = fmax_rgb(rf, gf, bf);

    l = (max + min) / 2;

    if (l < 0.5) {
	s = (max - min) / (max + min);
    } else {
	s = (max - min) / (2.0 - (max + min));
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

    if (h < 0) {
	h = h + 360;
    } else {
	h = h * 60;
    };

    s = s * 100;
    l = l * 100;

    printf("HSL: %f %f %f\n", h, s, l);

    hsl.hue = h;
    hsl.saturation = s;
    hsl.lightness = l;

    return hsl;
}

void get_split_complementary(cmColor colors) {
    float red = colors.red;
    float green = colors.green;
    float blue = colors.blue;

    float rf = red /255, gf = green / 255, bf = blue / 255;

    float min = fmin_rgb(rf, gf, bf);
    float max = fmax_rgb(rf, gf, bf);

    cmHSL hsl;

    float h = hsl.hue;
    float s = hsl.saturation;
    float l = hsl.lightness;

    float c;
    float x;
    float m;

    l = (max + min) / 2;

    if (l < 0.5) {
	s = (max - min) / (max + min);
    } else {
	s = (max - min) / (2.0 - (max + min));
    };

    if (max == rf) {
	h = (gf - bf) / (max - min);
    } else if (max == gf) {
	h = 2.0 + (bf - rf) / (max - min);
    } else {
	h = 4.0 + (rf - gf) / (max - min);
    };

    if (h < 0) {
	h = h + 360;
    } else {
	h = h * 60;
    };

    float comp_color = h + 180;

    if (comp_color > 360) {
	comp_color = comp_color - 360;
    } else {
	comp_color = comp_color;
    };

    float pos_split = comp_color + 30;

    if (pos_split > 360) {
	pos_split = pos_split - 360;
    } else {
	pos_split = pos_split;
    };

    float neg_split = comp_color - 30;

    if (neg_split < 0) {
	neg_split = neg_split + 360;
    } else {
	neg_split = neg_split;
    };

    cmHSL negHSL;
    cmHSL posHSL;

    negHSL.hue = neg_split;
    negHSL.saturation = s;
    negHSL.lightness = l;

    posHSL.hue = pos_split;
    posHSL.saturation = s;
    posHSL.lightness = l;

    cmColor negColor;
    cmColor posColor;

    negColor = convertHSL_to_RGB(negHSL);
    posColor = convertHSL_to_RGB(posHSL);

    printf("RGB: %i %i %i: \x1b[48;2;%i;%i;%im          \x1b[0m\n", posColor.red, posColor.green, posColor.blue, posColor.red, posColor.green, posColor.blue);
    printf("RGB: %i %i %i: \x1b[48;2;%i;%i;%im          \x1b[0m\n", negColor.red, negColor.green, negColor.blue, negColor.red, negColor.green, negColor.blue);
}

cmColor convertHSL_to_RGB(cmHSL hsl) {
    float h, s, l;

    h = hsl.hue;
    s = hsl.saturation;
    l = hsl.lightness;

    float norm_hue = h / 360;
    float norm_sat = s;
    float norm_light = l;

    float c, x, m;

    c = (1 - (f_abs(2 * l - 1))) * norm_sat;

    x = c * (((f_abs(norm_hue * 6)) / 2 - 1));

    m = norm_light - (c / 2);

    if (c < 0.0) {
	c = -c;
    };

    if (x < 0.0) {
	x = -x;
    };

    if (m < 0.0) {
	m = -m;
    };

    if (h < 0) {
	h = 0;
    };

    if (h >= 360) {
	h = 360;
    };

    float norm_r, norm_g, norm_b;
    
    if (0.0 <= h && h < 60) {
	norm_r = c;
	norm_g = x;
	norm_b = 0;
    } else if (60 <= h && h < 120) {
	norm_r = x;
	norm_g = c;
	norm_b = 0;
    } else if (120 <= h && h < 180) {
	norm_r = 0;
	norm_g = c;
	norm_b = x;
    } else if (180 <= h && h< 240) {
	norm_r = 0;
	norm_g = x;
	norm_b = c;
    } else if (240 <= h && h< 300) {
	norm_r = x;
	norm_g = 0;
	norm_b = c;
    } else if (300 <= h && h < 360) {
	norm_r = c;
	norm_g = 0;
	norm_b = x;
    } else {
	printf("error: hue value is not in a 0-360 value\n");
    };

    int final_red, final_green, final_blue;

    final_red = (norm_r + m) * 255;
    final_green = (norm_g + m) * 255;
    final_blue = (norm_b + m) * 255;

    if (final_red > 255) {
	final_red = 255;
    };

    if (final_red < 0) {
	final_red = 0;
    };

    if (final_green > 255) {
	final_green = 255;
    };

    if (final_green < 0) {
	final_green = 0;
    };

    if (final_blue > 255) {
	final_blue = 255;
    };

    if (final_green < 0) {
	final_green = 0;
    };

    /*printf("Norms R: %f, G: %f, B: %f\n", norm_r, norm_g, norm_b);
    printf("Finals R: %i, G: %i, B: %i\n", final_red, final_green, final_blue);*/

    cmColor colors;

    colors.red = final_red;
    colors.green = final_green;
    colors.blue = final_blue;

    return colors;
}
