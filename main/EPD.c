#include "EPD.h"


esp_err_t epaper_init()
{
    epaper_rst(); // Reset EPAPER

    waitUntilIdle();
    
    epaper_write_cmd(0x12);

    waitUntilIdle();

    epaper_write_cmd(0x01);
    epaper_write_data(0xC7);
    epaper_write_data(0x00);
    epaper_write_data(0x01);


    epaper_write_cmd(0x11);
    epaper_write_data(0x03);

    epaper_write_cmd(0x44);
    epaper_write_data(0x00);
    epaper_write_data(0x18);

    epaper_write_cmd(0x45);
    epaper_write_data(0x00);
    epaper_write_data(0x00);
    epaper_write_data(0xC7);
    epaper_write_data(0x00);

    epaper_write_cmd(0x3C);
    epaper_write_data(0x01);

    epaper_write_cmd(0x18);
    epaper_write_data(0x80);

    epaper_write_cmd(0x22);
    epaper_write_data(0xB1);
 
    epaper_write_cmd(0x20);

    waitUntilIdle();

    return ESP_OK;
}

esp_err_t epaper_update(){

    //Set RAM position
    epaper_write_cmd(0x4E);
    epaper_write_data(0x00);
    
    waitUntilIdle();

    epaper_write_cmd(0x4F);
    epaper_write_data(0x00);
    epaper_write_data(0x00);

    waitUntilIdle();

    //Send the screen buffer
	epaper_write_cmd(0x24);
	for (int j = 0; j < SCREEN_BUFFER_H; j++) {
		for (int i = 0; i < SCREEN_BUFFER_W; i++) {
            epaper_write_data(screenBuffer[i][j]);
		}
	}

    waitUntilIdle();

    //Send update command
    epaper_write_cmd(0x22);
    epaper_write_data(0xF7); 
    epaper_write_cmd(0x20);  

    waitUntilIdle();

    return ESP_OK;
}

esp_err_t epaper_clear(){

    //Set all bytes to white
    memset(screenBuffer,0xFF,SCREEN_BUFFER_H * SCREEN_BUFFER_W);

    return ESP_OK;
}

esp_err_t epaper_deepsleep(){

    waitUntilIdle();

    //Send deep sleep command
    epaper_write_cmd(0x10);
    epaper_write_data(0x01);

    return ESP_OK;

}