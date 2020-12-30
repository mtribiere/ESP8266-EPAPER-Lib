/* spi_epaper example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.


   WIRING : 
   BUSY -> D4
   RST  -> D8
   DC   -> D6
   CS   -> D2
   CLK  -> D5
   DIN  -> D7

*/

#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp8266/gpio_struct.h"
#include "esp8266/spi_struct.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_libc.h"

#include "driver/gpio.h"
#include "driver/spi.h"

const char *TAG = "spi_epaper";

#include "spiEPD.h"
#include "EPD.h"
#include "painterEPD.h"
//#include "img.h" 

void app_main(void)
{
    //Init GPIO
    ESP_LOGI(TAG, "Init GPIO");
    init_GPIO();

    //Init HSPI
    ESP_LOGI(TAG, "Init HSPI interface");
    init_SPI();

    //Init EPAPER display
    ESP_LOGI(TAG, "Init EPAPER display");
    epaper_init();

    ESP_LOGI(TAG, "Init sequence done");


    //Draw some stuff
    epaper_clear();
    epaper_draw_square(10,10,10);
    epaper_draw_square(30,30,30);
    epaper_draw_square(70,70,70);
    epaper_update();

}