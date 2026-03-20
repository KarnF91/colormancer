#ifndef COLORS_H
#define COLORS_H

typedef struct {
    int red;
    int green;
    int blue;
} cmColor;

typedef struct {
    float hue;
    float saturation;
    float value;
} cmHSV;

typedef struct {
    float hue;
    float saturation;
    float lightness;
} cmHSL;

typedef struct {
    float cyan;
    float magenta;
    float yellow;
    float black;
} cmCMYK;

typedef struct {
    int hue;
    int saturation;
    int lightness;
} cmIntHSL;

float f_abs(float v);
cmColor base_color(cmColor colors);
cmColor complementary_color(cmColor colors);
cmColor split_complementary_color(cmColor colors);
cmColor analogous_color(cmColor colors);
cmColor triadic_color(cmColor colors);
cmColor tetradic_color(cmColor colors);
int min_rgb(int r, int g, int b);
int max_rgb(int r, int g, int b);
cmColor complementary(cmColor colors);
float fmin_rgb(float r, float g, float b);
float fmax_rgb(float r, float g, float b);
cmHSV get_HSV(cmColor colors);
cmHSL get_HSL(cmColor colors);
cmColor get_pos_split_complementary(cmColor colors);
cmColor get_neg_split_complementary(cmColor colors);
cmColor get_pos_analogous(cmColor colors);
cmColor get_neg_analogous(cmColor colors);
cmColor get_first_triadic(cmColor colors);
cmColor get_second_triadic(cmColor colors);
cmColor get_first_tetradic(cmColor colors);
cmColor get_second_tetradic(cmColor colors);
cmColor get_third_tetradic(cmColor colors);
cmColor convertHSL_to_RGB(cmHSL hsl);

#endif
