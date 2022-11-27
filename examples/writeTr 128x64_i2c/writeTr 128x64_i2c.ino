/**
 * @file writeTr_128x64_i2c.ino
 * @author Hakan ÖZMEN (hakkanr@gmail.com)
 * @brief
 * @version 1.0
 * @date 2022-11-28
 * @section for more information please visit :
 * https://www.devrelerim.com/2022/11/ssd1306tur-ssd1306-oled-ekran-turkce.html
 * https://www.youtube.com/HakkanR
 * https://github.com/HakkanR/SSD1306TUR
 * @copyright Copyright (c) 2022
 * BDS License, all above text must be included any redistribution.
 */
#include <Wire.h>
#include <SSD1306TUR.h>
#include "TrFonts/FreeSansBold12pt7bTR.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1		// Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
SSD1306TUR display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void TrTextsOnScr();
void setup()
{
	Serial.begin(115200);
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			; // Don't proceed, loop forever
	}
	// Clear the buffer
	display.clearDisplay();
	TrTextsOnScr();
}

void loop()
{
	// put your main code here, to run repeatedly:
}
void TrTextsOnScr()
{
	display.setTextColor(SSD1306_WHITE);
	display.clearDisplay();
	display.setTextSize(1);
	display.println("       SSD1306");
	display.setFont(&FreeSansBold12pt7bTR);
	display.setCursor(20, 22);
	display.print("Türkçe");
	display.display();
	delay(3000);
}