# SSD1306TUR
 **SSD1306TUR** is a library that allows you to write any **Turkish char** on **SSD1306** monochrome oled  displays freely. Based on Adafuit's SSD1306 oled Display driver can be found on [here](https://github.com/adafruit/Adafruit_SSD1306). Please be sure this lib is present in your system before use this lib.
 
 If you find any problem or bug on this library, please use [Issues](https://github.com/HakkanR/SSD1306TUR/issues) feature on github or contact me on my web page [devrelerim.com](https://www.devrelerim.com/2022/11/ssd1306tur-ssd1306-oled-ekran-turkce.htm).

 You can follow me on:
 * [Youtube](https://www.youtube.com/HakkanR)
 * [Twitter](https://www.twitter.com/HakkanR)
 * [Instagram](https://www.instagram.com/hakkan_r)
 * [FaceBook](https://www.facebook.com/HakkanR)
 
 ## Basic Usage
 include header file
 ```cpp
 #include <Wire.h>
 #include <SSD1306TUR.h>
 ```
 You should use fonts placed TrFonts directory in this repository by including like this:
```c
#include "TrFonts/FreeSansBold12pt7bTR.h"
```
define LCD specs fit your screen: 
```c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
```
initiate the object as any name you want, I choose display
```c
SSD1306TUR display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
```
begin screen
```c
display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)
```
set text params and just write any Turkish letter by print, println or write functions.

```c
display.setTextColor(SSD1306_WHITE);
display.clearDisplay();
display.setTextSize(1);
display.setFont(&FreeSansBold12pt7bTR);
display.setCursor(20, 22);
display.print("Türkçe");
display.display(); 
```
## Dependencies 
* [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

## Download
You can download this on
* [Github](https://github.com/HakkanR/SSD1306TUR)
* Arduino Library Manager
* PlatformIO Libraries

## Available Fonts 
* FreeSansBold12pt7bTR.h
  
> more fonts will be added in the future, If you interested in creating new fonts to help this repository please feel free to contact me [hakkanr@gmail.com](mailto:hakkanr@gmail.com)
