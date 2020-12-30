#ifndef SPI_EPD
#define SPI_EPD

#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#include "esp8266/gpio_struct.h"
#include "esp8266/spi_struct.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_libc.h"

#include "driver/gpio.h"
#include "driver/spi.h"

#define EPAPER_DC_GPIO     12
#define EPAPER_RST_GPIO    15
#define EPAPER_CS_GPIO      4
#define EPAPER_BSY_GPIO     2
#define EPAPER_PIN_OUTPUT_SEL  (1ULL<<EPAPER_DC_GPIO) | (1ULL<<EPAPER_RST_GPIO) | (1ULL<<EPAPER_CS_GPIO)
#define EPAPER_PIN_INPUT_SEL (1ULL<<EPAPER_BSY_GPIO)

 spi_trans_t trans;

esp_err_t delay_ms(uint32_t time);
esp_err_t waitUntilIdle();

esp_err_t epaper_set_dc(uint32_t level);
esp_err_t IRAM_ATTR begin_spi_transaction();
esp_err_t IRAM_ATTR end_spi_transaction();

esp_err_t IRAM_ATTR epaper_write_cmd(uint8_t cmd);
esp_err_t IRAM_ATTR epaper_write_data(uint8_t data);

esp_err_t init_GPIO();
esp_err_t init_SPI();

#endif