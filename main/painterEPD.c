#include "painterEPD.h"
#include "font20.h"
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

esp_err_t epaper_draw_char(char c,uint8_t x, uint8_t y, uint8_t fontSize){

    //Font size in bytes
    uint8_t fontW;
    uint8_t fontH;
    
    //Font size in pixel
    uint8_t fontPW;
    uint8_t fontPH;

    //Find the correct font size
    switch(fontSize){
        case 20:
            fontPW = FONT_20_WIDTH;
            fontPH = FONT_20_HEIGHT;
            break;
        
        default:
            return ESP_FAIL;
            break;

    }

    fontH = FONT_20_HEIGHT;
    fontW = (FONT_20_WIDTH%8 == 0 ? FONT_20_WIDTH/8 : FONT_20_WIDTH/8+1);
   

    //Compute offset
    uint32_t charOffset = (c - ' ')*(fontW*fontH);

    //Draw the char in reverse Y order
    y += (fontPH-1);

    uint8_t startX = x;
    
    //Draw the char
    for(int i = 0;i<fontW*fontH;i++){

        //If the line ends
        if(i%fontW == 0){
            y--;
            x = startX;
        }

        for(int k = 0;k<8;k++){

            //If the pixel need to be black
            if(Font_20_table[charOffset+i] & (0x80 >> k))
                epaper_draw_pixel(x,y,0);
            
            //Proceed to next pixel
            x++;

        }
     

    }

    return ESP_OK;
}

esp_err_t epaper_draw_string(char *str,uint32_t size,uint8_t x, uint8_t y, uint8_t fontSize){

    for(int i = 0;i<size;i++){
        epaper_draw_char(str[i],x+i*10,y,fontSize);
    }

    return ESP_OK;
}

esp_err_t epaper_draw_img_fill(uint8_t x, uint8_t y, uint8_t *img){

    int imgOffset = 0;
    for(int j = SCREEN_BUFFER_H-1; j>0;j--) {
        for(int i = 0; i<SCREEN_BUFFER_W;i++){
            screenBuffer[i][j] = img[imgOffset];
            imgOffset++;
        }
    }

    return ESP_OK;
}