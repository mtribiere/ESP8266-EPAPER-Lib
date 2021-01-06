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
#include "font/font12.h"
#include "font/font20.h"
#include "img/sun.h"

void app_main(void)
{
    printf("====== Welcome to FreeRTOS ========\n");
    printf("====== ESP8266 Booting up..... ========\n");

    //Init GPIO
    ESP_LOGI(TAG, "Init GPIO");
    init_GPIO();

    //Init HSPI
    ESP_LOGI(TAG, "Init HSPI interface");
    init_SPI();

    //Init EPAPER display
    ESP_LOGI(TAG, "Init EPAPER display");
    epaper_init();
    
    //Draw some stuff
    ESP_LOGI(TAG, "Drawing to the screen");
    epaper_clear();
    epaper_draw_img(65,90,SUN_H,SUN_W,sunImg);

    epaper_draw_string("Hello world !",13,35,60,font20);
    epaper_draw_string("from ESP8266",12,40,52,font12);
    
    //Update the screen
    epaper_update();

    //Turn off the display
    epaper_deepsleep();

    printf("====== Done, have a nice day ! ========\n");

}