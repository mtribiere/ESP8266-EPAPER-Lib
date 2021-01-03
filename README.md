# ESP8266-EPAPER-Lib
An complete library for driving <b>Epaper display from Waveshare</b>. It's built from the ground up using the public SDK <b>FreeRTOS only</b>.
It has been succeffuly tested on an ESP12E based board with a 1.54" V2 screen. However it should work for any screen size with minor changes.

# Demo
![](https://github.com/mtribiere/ESP8266-EPAPER-Lib/blob/dev/Pics/IMG_20210103_182554.jpg)

# Wiring
| Epaper PIN | ESP Board PIN | FreeRTOS PIN
| :---: | :---: | :---: |
| BUSY | D4 | GPIO 2 |
| RST | D8 | GPIO 15 |
| DC | D6 | GPIO 12 |
| CS | D2 | GPIO 4 |
| CLK | D5 | HSPI_CLK |
| DIN | D7 | HSPI_MOSI |

# Author
Made with ❤️ by mtribiere
