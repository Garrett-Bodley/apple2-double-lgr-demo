#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../include/screen_logic.h"

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

uint8_t simple_sprite[] = {
  0xFF,
  0x81,
  0x81,
  0x99,
  0x99,
  0x81,
  0x81,
  0xFF,
};

void draw_recurse_logo(x, y)
{
  draw_sprite_words_lg80(x, y, simple_sprite, 8);
  // draw_sprite_words_lg80(x, y, sprite1, 16);
  // draw_sprite_words_lg80(x + 8, y, sprite2, 16);
}

void recurse_animation()
{
  uint8_t new_x, new_y;
  uint8_t x = 1;
  uint8_t y = 0;
  uint8_t x_vector = 1;
  uint8_t y_vector = 1;
  volatile uint16_t i;
  while(true)
  {
    draw_recurse_logo(x, y);
    for (i = 0; i < 3000; i++) {
        // Empty loop for delay
    }
    new_x = x + x_vector;
    new_y = y + y_vector;
    if(new_x == 0 || new_x == 68){
      x_vector *= -1;
    }
    if(new_y  == 0 || new_y  == 32){
      y_vector *= -1;
    }
    draw_recurse_logo(x, y);
    x = new_x;
    y = new_y;
  }
}

int main(void)
{
  set_double_low_res();
  fill_lgd_80();
  // draw_sprite_words_lg80(1, 1, simple_sprite, 8);
  // while(true){};
  recurse_animation();
  return 0;
}