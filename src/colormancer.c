#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "colors.h"
#include "formatted_print.h"

int main(int argc, char* argv[]) {
    cmColor colors;

    if (argc < 4) {
	printf("Too few arguments. Please provide 3 arguments");
	return 1;
    };

    if (argc > 4) {
	printf("Too many arguments. Please provide 3 arguments");
	return 1;
    };

    if (*argv[1] > 255 | *argv[1] < 0) {
	printf("Argument must be between 0-255");
	return 1;
    };

    if (*argv[2] > 255 | *argv[2] < 0) {
	printf("Argument must be between 0-255");
	return 1;
    };

    if (*argv[3] > 255 | *argv[3] < 0) {
	printf("Argument must be between 0-255");
	return 1;
    };

    int red = colors.red = atoi(argv[1]);
    int green = colors.green = atoi(argv[2]);
    int blue = colors.blue = atoi(argv[3]);

    base_color(colors);
    complementary_color(colors);
    split_complementary_color(colors);
    analogous_color(colors);
    triadic_color(colors);
    tetradic_color(colors);

    return 0;
}
