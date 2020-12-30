#ifndef PAINTER_EDP_H
#define PAINTER_EDP_H

#include "EPD.h"

esp_err_t epaper_draw_square(uint8_t x, uint8_t y,uint8_t size);
esp_err_t epaper_draw_pixel(uint8_t x, uint8_t y, uint8_t value);

#endif