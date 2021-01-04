#ifndef PAINTER_EDP_H
#define PAINTER_EDP_H

#include "EPD.h"

//Define pixel color
#define BLACK 0
#define WHITE 1

//Define directions
enum Direction {UP, RIGHT, DOWN, LEFT};

//Define font struct
typedef struct{
    uint16_t fontW; //Using 16 bits int to help memory management
    uint16_t fontH; //
    uint8_t *charset;
}Font;

esp_err_t epaper_draw_pixel(uint8_t x, uint8_t y, uint8_t value);

esp_err_t epaper_draw_square(uint8_t x, uint8_t y,uint8_t size);
esp_err_t epaper_draw_line(uint8_t x, uint8_t y, enum Direction direction, uint8_t length ,uint8_t width);

esp_err_t epaper_draw_char(char c,uint8_t x, uint8_t y, Font font);
esp_err_t epaper_draw_string(char *str,uint32_t size,uint8_t x, uint8_t y, Font font);
esp_err_t epaper_draw_img(uint8_t x, uint8_t y, uint8_t w, uint8_t h,uint8_t *img);

#endif