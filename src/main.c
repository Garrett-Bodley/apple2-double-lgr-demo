#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../include/screen_logic.h"

int main(void)
{
  uint8_t sprite1[] = {
    0xFF,
    0x80,
    0xbf,
    0x95,
    0xbf,
    0xa4,
    0xbf,
    0xbf,
    0x80,
    0xff,
    0x0f,
    0x0f,
    0x7f,
    0xea,
    0xd5,
    0xff,
  };

  uint8_t sprite2[] = {
    0xf0,
    0x10,
    0xd0,
    0xd0,
    0xd0,
    0xd0,
    0xd0,
    0xd0,
    0x10,
    0xf0,
    0x00,
    0x00,
    0xe0,
    0xb0,
    0x70,
    0xf0
  };

  printf("Hello, World!\n");

  set_double_low_res();
  clear_lgd_80();
  draw_sprite_words_lg80(0, 0, sprite1, 16);
  draw_sprite_words_lg80(8, 0, sprite2, 16);

  draw_sprite_words_lg80(68, 0, sprite1, 16);
  draw_sprite_words_lg80(76, 0, sprite2, 16);

  draw_sprite_words_lg80(0, 32, sprite1, 16);
  draw_sprite_words_lg80(8, 32, sprite2, 16);

  draw_sprite_words_lg80(68, 32, sprite1, 16);
  draw_sprite_words_lg80(76, 32, sprite2, 16);

  draw_sprite_words_lg80(34, 16, sprite1, 16);
  draw_sprite_words_lg80(42, 16, sprite2, 16);

  // This matters when compiling to a disk image
  //
  // If you don't add an infinite loop the emulator will quickly execute
  // and exit your program before you're able to see the output.
  while(true);
  return 0;
}