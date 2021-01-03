#ifndef PAINTER_EDP_H
#define PAINTER_EDP_H

#include "EPD.h"


esp_err_t epaper_draw_square(uint8_t x, uint8_t y,uint8_t size);
esp_err_t epaper_draw_pixel(uint8_t x, uint8_t y, uint8_t value);

esp_err_t epaper_draw_char(char c,uint8_t x, uint8_t y, uint8_t fontSize);
esp_err_t epaper_draw_string(char *str,uint32_t size,uint8_t x, uint8_t y, uint8_t fontSize);
esp_err_t epaper_draw_img(uint8_t x, uint8_t y, uint8_t w, uint8_t h,uint8_t *img);

#endif