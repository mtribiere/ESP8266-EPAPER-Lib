#include "painterEPD.h"

#include "font/font20.h"
#include "font/font12.h"

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

    //If coordinates not in range
    if(y >= EPD_HEIGHT || x >= EPD_WIDTH){
        printf("Coor error : (%d;%d)\n",x,y);
        return ESP_FAIL;
    }
    

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

    //Charset pointer
    uint8_t *charset = NULL;

    //Find the correct font size
    switch(fontSize){
        case 20:
            fontPW = FONT_20_WIDTH;
            fontPH = FONT_20_HEIGHT;
            charset = Font_20_table;
            break;
        
        case 12:
            fontPW = FONT_12_WIDTH;
            fontPH = FONT_12_HEIGHT;
            charset = Font_12_table;
            break;
        
        default:
            return ESP_FAIL;
            break;

    }

    fontH = fontPH;
    fontW = ((fontPW%8 == 0) ? fontPW/8 : fontPW/8+1);
   

    //Compute offset
    uint32_t charOffset = (c - ' ')*(fontW*fontH);

    //Draw the char in reverse Y order
    y += fontPH;

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
            if(charset[charOffset+i] & (0x80 >> k))
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

esp_err_t epaper_draw_img(uint8_t x, uint8_t y, uint8_t w, uint8_t h,uint8_t *img){

    //Compute the number of bytes to draw
    uint8_t hByte = h;
    uint8_t wByte = (w%8 == 0 ? w/8 : w/8+1);

    //Draw the img in reverse Y order
    y += h;

    uint8_t startX = x;
    
    //For each byte of the img
    for(int i = 0;i< hByte * wByte;i++){

        //If the line ends
        if(i%wByte == 0){
            y--;
            x = startX;
        }

        for(int k = 0;k<8;k++){

            //If the pixel need to be black
            if(img[i] & (0x80 >> k))
                epaper_draw_pixel(x,y,0);
            
            //Proceed to next pixel
            x++;

        }
     

    }
    

    return ESP_OK;
}