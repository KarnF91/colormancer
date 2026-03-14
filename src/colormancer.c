#include <stdio.h>
#include <stdlib.h>

#include "colors.h"

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

    int red = colors.red = atoi(argv[1]);
    int green = colors.green = atoi(argv[2]);
    int blue = colors.blue = atoi(argv[3]);

    get_HSV(colors);
    get_HSL(colors);

    base_color(colors);
    complementary(colors);
    get_split_complementary(colors);

    return 0;
}
