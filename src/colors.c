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

cmColor base_color(cmColor colors) {
    int red = colors.red;
    int green = colors.green;
    int blue = colors.blue;

    int maxr = 255 - red, maxg = 255 - green, maxb = 255 - blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", red, green, blue, maxr, maxg, maxb, red, green, blue);
}

cmColor complementary_color(cmColor colors) {
    cmColor comp_color = complementary(colors);

    int red = comp_color.red, green = comp_color.green, blue = comp_color.blue;

    int read_red = 255 - red, read_green = 255 - green, read_blue = 255 - blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", red, green, blue, read_red, read_green, read_blue, red, green, blue);
}

cmColor split_complementary_color(cmColor colors) {
    cmColor pos_color = get_pos_split_complementary(colors);
    cmColor neg_color = get_neg_split_complementary(colors);

    int pos_red = pos_color.red, pos_green = pos_color.green, pos_blue = pos_color.blue;
    int neg_red = neg_color.red, neg_green = neg_color.green, neg_blue = neg_color.blue;

    int read_pred = 255 - pos_red, read_pgreen = 255 - pos_green, read_pblue = 255 - pos_blue;
    int read_nred = 255 - neg_red, read_ngreen = 255 - neg_green, read_nblue = 255 - neg_blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", pos_red, pos_green, pos_blue, read_pred, read_pgreen, read_pblue, pos_red, pos_green, pos_blue);
    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", neg_red, neg_green, neg_blue, read_nred, read_ngreen, read_nblue, neg_red, neg_green, neg_blue);
}

cmColor analogous_color(cmColor colors) {
    cmColor pos_color = get_pos_analogous(colors);
    cmColor neg_color = get_neg_analogous(colors);

    int pos_red = pos_color.red, pos_green = pos_color.green, pos_blue = pos_color.blue;
    int neg_red = neg_color.red, neg_green = neg_color.green, neg_blue = neg_color.blue;

    int read_pred = 255 - pos_red, read_pgreen = 255 - pos_green, read_pblue = 255 - pos_blue;
    int read_nred = 255 - neg_red, read_ngreen = 255 - neg_green, read_nblue = 255 - neg_blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", pos_red, pos_green, pos_blue, read_pred, read_pgreen, read_pblue, pos_red, pos_green, pos_blue);
    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", neg_red, neg_green, neg_blue, read_nred, read_ngreen, read_nblue, neg_red, neg_green, neg_blue);
}

cmColor triadic_color(cmColor colors) {
    cmColor first_tri_color = get_first_triadic(colors);
    cmColor second_triadic_color = get_second_triadic(colors);

    int first_red = first_tri_color.red, first_green = first_tri_color.green, first_blue = first_tri_color.blue;
    int second_red = second_triadic_color.red, second_green = second_triadic_color.green, second_blue = second_triadic_color.blue;

    int read_fstred = 255 - first_red, read_fstgreen = 255 - first_green, read_fstblue = 255 - first_blue;
    int read_sndred = 255 - second_red, read_sndgreen = 255 - second_green, read_sndblue = 255 - second_blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", first_red, first_green, first_blue, read_fstred, read_fstgreen, read_fstblue, first_red, first_green, first_blue);
    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", second_red, second_green, second_blue, read_sndred, read_sndgreen, read_sndblue, second_red, second_green, second_blue);
}

cmColor tetradic_color(cmColor colors) {
    cmColor first_tetra_color = get_first_tetradic(colors);
    cmColor second_tetra_color = get_second_tetradic(colors);
    cmColor third_tetra_color = get_third_tetradic(colors);

    int first_red = first_tetra_color.red, first_green = first_tetra_color.green, first_blue = first_tetra_color.blue;
    int second_red = second_tetra_color.red, second_green = second_tetra_color.green, second_blue = second_tetra_color.blue;
    int third_red = third_tetra_color.red, third_green = third_tetra_color.green, third_blue = third_tetra_color.blue;

    int read_fstred = 255 - first_red, read_fstgreen = 255 - first_green, read_fstblue = 255 - first_blue;
    int read_sndred = 255 - second_red, read_sndgreen = 255 - second_green, read_sndblue = 255 - second_blue;
    int read_trdred = 255 - third_red, read_trdgreen = 255 - third_green, read_trdblue = 255 - third_blue;

    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", first_red, first_green, first_blue, read_fstred, read_fstgreen, read_fstblue, first_red, first_green, first_blue);
    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", second_red, second_green, second_blue, read_sndred, read_sndgreen, read_sndblue, second_red, second_green, second_blue);
    printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n", third_red, third_green, third_blue, read_trdred, read_trdgreen, read_trdblue, third_red, third_green, third_blue);
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

    int red = colors.red;
    int green = colors.green;
    int blue = colors.blue;

    int comp_red = max_red - colors.red;
    int comp_green = max_green - colors.green;
    int comp_blue = max_blue - colors.blue;

    cmColor compcolor;

    compcolor.red = comp_red;
    compcolor.green = comp_green;
    compcolor.blue = comp_blue;

    return compcolor;
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

    hsl.hue = h;
    hsl.saturation = s;
    hsl.lightness = l;

    return hsl;
}

cmColor get_pos_split_complementary(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue;
    float s = hsl.saturation;
    float l = hsl.lightness;

    float comp_color = h + 180;

    if (comp_color > 360) {
	comp_color = comp_color - 360;
    } else if (comp_color < 0) {
	comp_color = comp_color + 360;
    } else {
	comp_color = comp_color;
    };

    float pos_split = comp_color + 30;

    if (pos_split > 360) {
	pos_split = pos_split - 360;
    } else if (pos_split < 0) {
	pos_split = pos_split + 360;
    } else {
	pos_split = pos_split;
    };

    cmHSL posHSL;

    posHSL.hue = pos_split;
    posHSL.saturation = s;
    posHSL.lightness = l;

    cmColor posColor;

    posColor = convertHSL_to_RGB(posHSL);

    int pos_mr = 255 - posColor.red, pos_mg = 255 - posColor.green, pos_mb = 255 - posColor.blue;

    return posColor;
}

cmColor get_neg_split_complementary(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue;
    float s = hsl.saturation;
    float l = hsl.lightness;

    float comp_color = h + 180;

    if (comp_color > 360) {
	comp_color = comp_color - 360;
    } else if (comp_color < 0) {
	comp_color = comp_color + 360;
    } else {
	comp_color = comp_color;
    };

    float neg_split = comp_color - 30;

    if (neg_split < 0) {
	neg_split = neg_split + 360;
    } else if (neg_split > 360) {
	neg_split = neg_split - 360;
    } else {
	neg_split = neg_split;
    };

    cmHSL negHSL;

    negHSL.hue = neg_split;
    negHSL.saturation = s;
    negHSL.lightness = l;

    cmColor negColor;

    negColor = convertHSL_to_RGB(negHSL);

    int neg_mr = 255 - negColor.red, neg_mg = 255 - negColor.green, neg_mb = 255 - negColor.blue;

    return negColor;
}

cmColor get_pos_analogous(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;

    float pos_split = h + 30;

    if (pos_split < 0) {
	pos_split = pos_split + 360;
    } else if (pos_split > 360) {
	pos_split = pos_split - 360;
    } else {
	pos_split = pos_split;
    };

    cmHSL posHSL;

    posHSL.hue = pos_split;
    posHSL.saturation = s;
    posHSL.lightness = l;

    cmColor posColor = convertHSL_to_RGB(posHSL);

    return posColor;
}

cmColor get_neg_analogous(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;

    float neg_split = h - 30;

    if (neg_split < 0) {
	neg_split = neg_split + 360;
    } else if (neg_split > 360) {
	neg_split = neg_split - 360;
    } else {
	neg_split = neg_split;
    };

    cmHSL negHSL;

    negHSL.hue = neg_split;
    negHSL.saturation = s;
    negHSL.lightness = l;

    cmColor negColor = convertHSL_to_RGB(negHSL);

    return negColor;

}

cmColor get_first_triadic(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;
    float triadic = h + 120;

    if (triadic < 0) {
	triadic = triadic + 360;
    } else if (triadic > 360) {
	triadic = triadic - 360;
    } else {
	triadic = triadic;
    };

    cmHSL triHSL;

    triHSL.hue = triadic;
    triHSL.saturation = s;
    triHSL.lightness = l;

    cmColor triColor = convertHSL_to_RGB(triHSL);

    return triColor;
}

cmColor get_second_triadic(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;
    float triadic = h + 240;

    if (triadic < 0) {
	triadic = triadic + 360;
    } else if (triadic > 360) {
	triadic = triadic - 360;
    } else {
	triadic = triadic;
    };

    cmHSL triHSL;

    triHSL.hue = triadic;
    triHSL.saturation = s;
    triHSL.lightness = l;

    cmColor triColor = convertHSL_to_RGB(triHSL);

    return triColor;
}

cmColor get_third_tetradic(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;
    float tetradic = h + 270;

    if (tetradic < 0) {
	tetradic = tetradic + 360;
    } else if (tetradic > 360) {
	tetradic = tetradic - 360;
    } else {
	tetradic = tetradic;
    };

    cmHSL tetHSL;

    tetHSL.hue = tetradic;
    tetHSL.saturation = s;
    tetHSL.lightness = l;

    cmColor tetColor = convertHSL_to_RGB(tetHSL);

    return tetColor;
}

cmColor get_second_tetradic(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;
    float tetradic = h + 180;

    if (tetradic < 0) {
	tetradic = tetradic + 360;
    } else if (tetradic > 360) {
	tetradic = tetradic - 360;
    } else {
	tetradic = tetradic;
    };

    cmHSL tetHSL;

    tetHSL.hue = tetradic;
    tetHSL.saturation = s;
    tetHSL.lightness = l;

    cmColor tetColor = convertHSL_to_RGB(tetHSL);

    return tetColor;
}

cmColor get_first_tetradic(cmColor colors) {
    cmHSL hsl = get_HSL(colors);

    float h = hsl.hue, s = hsl.saturation, l = hsl.lightness;
    float tetradic = h + 90;

    if (tetradic < 0) {
	tetradic = tetradic + 360;
    } else if (tetradic > 360) {
	tetradic = tetradic - 360;
    } else {
	tetradic = tetradic;
    };

    cmHSL tetHSL;

    tetHSL.hue = tetradic;
    tetHSL.saturation = s;
    tetHSL.lightness = l;

    cmColor tetColor = convertHSL_to_RGB(tetHSL);

    return tetColor;
}

cmColor convertHSL_to_RGB(cmHSL hsl) {
    float h, s, l;

    h = hsl.hue;
    s = hsl.saturation;
    l = hsl.lightness;

    float norm_hue = h;
    float norm_sat = s / 100;
    float norm_light = l / 100;

    float c, x, m;

    if (l <= 0.5) {
	c = norm_sat * 2 * norm_light;
    } else {
	c = norm_sat * (2 - 2 * norm_light);
    };

//    x = c * (((f_abs(norm_hue / 60)) / 2 - 1))

    float ab_val = f_abs(norm_hue / 60);

    x = c * (fmod(ab_val, 2) - 1);

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

    cmColor colors;

    colors.red = final_red;
    colors.green = final_green;
    colors.blue = final_blue;

    return colors;
}
