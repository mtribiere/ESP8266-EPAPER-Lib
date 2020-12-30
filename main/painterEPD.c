#include "painterEPD.h"

esp_err_t epaper_draw_square(uint8_t x, uint8_t y,uint8_t size){

    //Draw a black square in screenBuffer
    for(int j=y;j<y+size;j++){

        for(int i=x;i<x+size;i++){

            epaper_draw_pixel(i,j,0);

        }

    }
    return ESP_OK;
}

esp_err_t epaper_draw_pixel(uint8_t x, uint8_t y, uint8_t value){

    //If the value is white
    if(value){
        screenBuffer[(x - (x%8))/8][y] |= (~(0x80 >> (x%8)));
    }else{ //If the value is black
         screenBuffer[(x - (x%8))/8][y] &= (~(0x80 >> (x%8)));
    }

    return ESP_OK;
}