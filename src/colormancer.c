#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "formatted_print.h"

int main(int argc, char *argv[]) {
  cmColor colors;

  int red = colors.red = atoi(argv[2]);
  int green = colors.green = atoi(argv[3]);
  int blue = colors.blue = atoi(argv[4]);

  int c;
  int option_index = 0;

  while (1) {

    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"full", required_argument, NULL, 'f'},
        {"complementary", required_argument, NULL, 'c'},
        {"split", required_argument, NULL, 's'},
        {"analogous", required_argument, NULL, 'a'},
        {"triadric", required_argument, NULL, 't'},
        {"tetradic", required_argument, NULL, 'q'},
        {0, 0, 0, 0},
    };

    int option_index = 0;

    c = getopt_long(argc, argv, "hf:c:s:a:t:q:", long_options, &option_index);

    if (c == -1)
      break;

    switch (c) {
    case 'h':
      printf("colormancer [option] [r g b]\n");
      break;

    case 'f':
      base_color(colors);
      complementary_color(colors);
      split_complementary_color(colors);
      analogous_color(colors);
      triadic_color(colors);
      tetradic_color(colors);

      break;

    case 'c':
      base_color(colors);
      complementary_color(colors);

      break;

    case 's':
      base_color(colors);
      split_complementary_color(colors);

      break;

    case 'a':
      base_color(colors);
      analogous_color(colors);

      break;

    case 't':
      base_color(colors);
      triadic_color(colors);

      break;

    case 'q':
      base_color(colors);
      tetradic_color(colors);

      break;

    default:
      base_color(colors);
    };
  }

  return 0;
}
