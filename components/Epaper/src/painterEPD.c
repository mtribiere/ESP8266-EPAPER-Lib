#include "painterEPD.h"


esp_err_t epaper_inverse_color(){

    for(int j = 0;j<SCREEN_BUFFER_H;j++){
        for(int i = 0;i<SCREEN_BUFFER_W;i++){
            screenBuffer[i][j] = ~screenBuffer[i][j];
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

esp_err_t epaper_draw_square(uint8_t x, uint8_t y,uint8_t size){

    //Draw a black square in screenBuffer
    for(int j=y;j<y+size;j++){

        for(int i=x;i<x+size;i++){

            epaper_draw_pixel(i,j,BLACK);

        }

    }
    return ESP_OK;
}

esp_err_t epaper_draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {

   //If straight vertical line
   if(x0 == x1){

        while(y0 != y1){
            epaper_draw_pixel(x0, y0 , BLACK);
            if(y0<y1)
                y0++;
            else
                y0--;
        }


    }else{

        //If straight horizontal line
        if(y0 == y1){

            while(x0 != x1){
                epaper_draw_pixel(x0,y0,BLACK);
                if(x0<x1)
                    x0++;
                else
                    x0--;
            }

        }else{
            
            /* Bresenham line algorithm */
            int dx = x1 - x0 >= 0 ? x1 - x0 : x0 - x1;
            int sx = x0 < x1 ? 1 : -1;
            int dy = y1 - y0 <= 0 ? y1 - y0 : y0 - y1;
            int sy = y0 < y1 ? 1 : -1;
            int err = dx + dy;

            while((x0 != x1) && (y0 != y1)) {
                epaper_draw_pixel(x0, y0 , BLACK);
                if (2 * err >= dy) {     
                    err += dy;
                    x0 += sx;
                }
                if (2 * err <= dx) {
                    err += dx; 
                    y0 += sy;
                }
            }
        }
    }


    return ESP_OK;
}


esp_err_t epaper_draw_char(char c,uint8_t x, uint8_t y, Font font){
    
    //Font size in pixel
    uint8_t fontPW = font.fontW;
    uint8_t fontPH = font.fontH;

    //Charset pointer
    uint8_t *charset = font.charset;

    uint8_t fontH = fontPH;
    uint8_t fontW = ((fontPW%8 == 0) ? fontPW/8 : fontPW/8+1);
   

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
                epaper_draw_pixel(x,y,BLACK);
            
            //Proceed to next pixel
            x++;

        }
     

    }

    return ESP_OK;
}

esp_err_t epaper_draw_string(char *str,uint32_t size,uint8_t x, uint8_t y, Font font){

    for(int i = 0;i<size;i++){
        epaper_draw_char(str[i],x+i*10,y,font);
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
                epaper_draw_pixel(x,y,BLACK);
            
            //Proceed to next pixel
            x++;

        }
     

    }
    

    return ESP_OK;
}