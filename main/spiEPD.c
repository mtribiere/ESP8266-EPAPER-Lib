#include "spiEPD.h"

static void IRAM_ATTR gpio_isr_handler(void *arg)
{
    //If the received interrupt is from BSY pin
    if((uint32_t)arg == EPAPER_BSY_GPIO)
        isEpaperBusy = gpio_get_level(EPAPER_BSY_GPIO);
    
}

esp_err_t delay_ms(uint32_t time)
{
    vTaskDelay(time / portTICK_RATE_MS);
    return ESP_OK;
}

esp_err_t waitUntilIdle(){

    delay_ms(10);

    while(isEpaperBusy);

    delay_ms(100);
    return ESP_OK;
}

esp_err_t epaper_rst()
{
    gpio_set_level(EPAPER_RST_GPIO, 1);
    delay_ms(200);
    gpio_set_level(EPAPER_RST_GPIO, 0);
    delay_ms(10);
    gpio_set_level(EPAPER_RST_GPIO, 1);
    delay_ms(200);
    return ESP_OK;
}

esp_err_t epaper_set_dc(uint32_t level){
    gpio_set_level(EPAPER_DC_GPIO,level);
    return ESP_OK;
}

esp_err_t IRAM_ATTR begin_spi_transaction(){
    
    //Begin transaction
    gpio_set_level(EPAPER_CS_GPIO,0);

    return ESP_OK;
}

esp_err_t IRAM_ATTR end_spi_transaction(){
    
    //End transaction
    gpio_set_level(EPAPER_CS_GPIO,1);

    return ESP_OK;
}

// Write an 8-bit cmd
esp_err_t IRAM_ATTR epaper_write_cmd(uint8_t cmd){

    //Prepare data structure
    uint32_t buf = ((uint32_t) cmd << 24); // In order to improve the transmission efficiency, it is recommended that the external incoming data is (uint32_t *) type data, do not use other type data.
    trans.mosi = &buf;

    //Indicate command
    epaper_set_dc(0);
    
    //Begin transaction
    begin_spi_transaction();
    
    //Set 8 bits of commands
    spi_trans(HSPI_HOST, &trans);

    //End transaction
    end_spi_transaction();

    return ESP_OK;
}

esp_err_t IRAM_ATTR epaper_write_data(uint8_t data){

    //Prepare data structure
    uint32_t buf = ((uint32_t)data << 24); // In order to improve the transmission efficiency, it is recommended that the external incoming data is (uint32_t *) type data, do not use other type data.
    trans.mosi = &buf;

    //Indicate data
    epaper_set_dc(1);

    //Begin transaction
    begin_spi_transaction();

    //Set 8 bits of data
    spi_trans(HSPI_HOST, &trans);

    //End transaction
    end_spi_transaction();

    return ESP_OK;
}

esp_err_t init_GPIO(){

    //Init output GPIO
    gpio_config_t io_conf = {0};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = EPAPER_PIN_OUTPUT_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);

    //Init input GPIO
    io_conf.intr_type = GPIO_INTR_ANYEDGE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = EPAPER_PIN_INPUT_SEL;
    io_conf.pull_down_en = 1;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    //install gpio isr service
    gpio_install_isr_service(0);

    //Hook the handler to the pin
    gpio_isr_handler_add(EPAPER_BSY_GPIO, gpio_isr_handler, (void *)EPAPER_BSY_GPIO);

    //Set the default state to unbusy
    isEpaperBusy = 0;

    return ESP_OK;
}

esp_err_t init_SPI(){

    //Init the SPI interface
    spi_config_t spi_config = {0};
    // Load default interface parameters
    // CS_EN:1, MISO_EN:1, MOSI_EN:1, BYTE_TX_ORDER:1, BYTE_TX_ORDER:1, BIT_RX_ORDER:0, BIT_TX_ORDER:0, CPHA:0, CPOL:0
    spi_config.interface.val = SPI_DEFAULT_INTERFACE;
    // Turn off default interrupt enable
    spi_intr_enable_t intr_config = {0};
    spi_config.intr_enable = intr_config;
    // Enable MOSI pin
    spi_config.interface.mosi_en = 1;
    // Cancel hardware cs
    spi_config.interface.cs_en = 0;
    // MISO pin is used for DC
    spi_config.interface.miso_en = 0;
    // CPOL: 1, CPHA: 1
    spi_config.interface.cpol = SPI_CPOL_HIGH;
    spi_config.interface.cpha = SPI_CPHA_HIGH;
    // Set SPI to master mode
    // 8266 Only support half-duplex
    spi_config.mode = SPI_MASTER_MODE;
    // Set the SPI clock frequency division factor
    spi_config.clk_div = SPI_2MHz_DIV;

    spi_config.interface.byte_tx_order = SPI_BYTE_ORDER_MSB_FIRST;
    spi_config.interface.bit_tx_order = SPI_BIT_ORDER_LSB_FIRST;

    spi_init(HSPI_HOST, &spi_config);

    //Init the transmission structure
    memset(&trans, 0x0, sizeof(trans));

    trans.bits.val = 0;
    trans.bits.cmd = 0;
    trans.bits.addr = 0;
    trans.bits.mosi = 8;

    trans.cmd = NULL;
    trans.addr = NULL;
    trans.mosi = NULL;

    return ESP_OK;
}