# ESP8266-EPAPER-Lib
An still in development library for driving <b>Epaper display from Waveshare</b>. It's built from the ground up using the public SDK <b>FreeRTOS only</b>.
It has been successfully tested on an ESP12E-based board with a 1.54" V2 EPaper screen. However it should work for any screen size with minor changes.

# Demo
<img src="Pics/IMG_20210103_182554.jpg" width="600">

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
