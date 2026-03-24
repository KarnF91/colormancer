#include <stdio.h>

#include "colors.h"
#include "formatted_print.h"

cmColor base_color(cmColor colors) {
  int red = colors.red;
  int green = colors.green;
  int blue = colors.blue;

  int maxr = 255 - red, maxg = 255 - green, maxb = 255 - blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         red, green, blue, maxr, maxg, maxb, red, green, blue);
}

cmColor complementary_color(cmColor colors) {
  cmColor comp_color = complementary(colors);

  int red = comp_color.red, green = comp_color.green, blue = comp_color.blue;

  int read_red = 255 - red, read_green = 255 - green, read_blue = 255 - blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         red, green, blue, read_red, read_green, read_blue, red, green, blue);
}

cmColor split_complementary_color(cmColor colors) {
  cmColor pos_color = get_pos_split_complementary(colors);
  cmColor neg_color = get_neg_split_complementary(colors);

  int pos_red = pos_color.red, pos_green = pos_color.green,
      pos_blue = pos_color.blue;
  int neg_red = neg_color.red, neg_green = neg_color.green,
      neg_blue = neg_color.blue;

  int read_pred = 255 - pos_red, read_pgreen = 255 - pos_green,
      read_pblue = 255 - pos_blue;
  int read_nred = 255 - neg_red, read_ngreen = 255 - neg_green,
      read_nblue = 255 - neg_blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         pos_red, pos_green, pos_blue, read_pred, read_pgreen, read_pblue,
         pos_red, pos_green, pos_blue);
  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         neg_red, neg_green, neg_blue, read_nred, read_ngreen, read_nblue,
         neg_red, neg_green, neg_blue);
}

cmColor analogous_color(cmColor colors) {
  cmColor pos_color = get_pos_analogous(colors);
  cmColor neg_color = get_neg_analogous(colors);

  int pos_red = pos_color.red, pos_green = pos_color.green,
      pos_blue = pos_color.blue;
  int neg_red = neg_color.red, neg_green = neg_color.green,
      neg_blue = neg_color.blue;

  int read_pred = 255 - pos_red, read_pgreen = 255 - pos_green,
      read_pblue = 255 - pos_blue;
  int read_nred = 255 - neg_red, read_ngreen = 255 - neg_green,
      read_nblue = 255 - neg_blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         pos_red, pos_green, pos_blue, read_pred, read_pgreen, read_pblue,
         pos_red, pos_green, pos_blue);
  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         neg_red, neg_green, neg_blue, read_nred, read_ngreen, read_nblue,
         neg_red, neg_green, neg_blue);
}

cmColor triadic_color(cmColor colors) {
  cmColor first_tri_color = get_first_triadic(colors);
  cmColor second_triadic_color = get_second_triadic(colors);

  int first_red = first_tri_color.red, first_green = first_tri_color.green,
      first_blue = first_tri_color.blue;
  int second_red = second_triadic_color.red,
      second_green = second_triadic_color.green,
      second_blue = second_triadic_color.blue;

  int read_fstred = 255 - first_red, read_fstgreen = 255 - first_green,
      read_fstblue = 255 - first_blue;
  int read_sndred = 255 - second_red, read_sndgreen = 255 - second_green,
      read_sndblue = 255 - second_blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         first_red, first_green, first_blue, read_fstred, read_fstgreen,
         read_fstblue, first_red, first_green, first_blue);
  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         second_red, second_green, second_blue, read_sndred, read_sndgreen,
         read_sndblue, second_red, second_green, second_blue);
}

cmColor tetradic_color(cmColor colors) {
  cmColor first_tetra_color = get_first_tetradic(colors);
  cmColor second_tetra_color = get_second_tetradic(colors);
  cmColor third_tetra_color = get_third_tetradic(colors);

  int first_red = first_tetra_color.red, first_green = first_tetra_color.green,
      first_blue = first_tetra_color.blue;
  int second_red = second_tetra_color.red,
      second_green = second_tetra_color.green,
      second_blue = second_tetra_color.blue;
  int third_red = third_tetra_color.red, third_green = third_tetra_color.green,
      third_blue = third_tetra_color.blue;

  int read_fstred = 255 - first_red, read_fstgreen = 255 - first_green,
      read_fstblue = 255 - first_blue;
  int read_sndred = 255 - second_red, read_sndgreen = 255 - second_green,
      read_sndblue = 255 - second_blue;
  int read_trdred = 255 - third_red, read_trdgreen = 255 - third_green,
      read_trdblue = 255 - third_blue;

  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         first_red, first_green, first_blue, read_fstred, read_fstgreen,
         read_fstblue, first_red, first_green, first_blue);
  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         second_red, second_green, second_blue, read_sndred, read_sndgreen,
         read_sndblue, second_red, second_green, second_blue);
  printf("\x1b[48;2;%i;%i;%im\x1b[38;2;%i;%i;%im %i, %i, %i \x1b[0m\x1b[0m\n",
         third_red, third_green, third_blue, read_trdred, read_trdgreen,
         read_trdblue, third_red, third_green, third_blue);
}
