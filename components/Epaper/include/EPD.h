#ifndef EDP_H
#define EDP_H

#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"

#include "esp_system.h"
#include "esp_log.h"
#include "esp_libc.h"

#include "spiEPD.h"

#define EPD_WIDTH       200
#define EPD_HEIGHT      200
#define SCREEN_BUFFER_W ((EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1))
#define SCREEN_BUFFER_H EPD_HEIGHT

uint8_t screenBuffer[SCREEN_BUFFER_W][SCREEN_BUFFER_H];

esp_err_t epaper_rst();

esp_err_t epaper_init();

esp_err_t epaper_update();
esp_err_t epaper_clear();

esp_err_t epaper_deepsleep();

#endif