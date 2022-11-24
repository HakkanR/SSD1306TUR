/**
 * @file SSD1306TUR.cpp
 * @author Hakan ÖZMEN (hakkanr@gmail.com)
 * @brief
 * * This is a library based on Adafruit's SSD1306 library for monochrome oled
 * displays, It targets to bring ability to use Turkish alphabet freely with these
 * oled screens. Adafruit_SSD1306 and Adafruit_GFX libraries are needed to use this
 * library but not enought to have Turkish letters, You should use font files in folder
 * TrFonts of this library. Notice that file names end with TR expression.
 * @section Dependencies :
 * This library depends on
 * https://github.com/adafruit/Adafruit-GFX-Library Adafruit_GFX, and
 * https://github.com/adafruit/Adafruit_SSD1306 Adafruit_SSD1306
 * be sure you have installed latest versions of these libs before
 * use this lib.
 * @version 1.0.1
 * @date 2022-11-09
 * @section for more information please visit :
 * https://www.devrelerim.com/2022/11/ssd1306tur-ssd1306-oled-ekran-turkce.html
 * https://www.youtube.com/HakkanR
 * https://github.com/HakkanR/SSD1306TUR
 * @copyright
 * BSD License, all above text must be included in any distribution.
 */
#include "SSD1306TUR.h"

SSD1306TUR::SSD1306TUR(uint8_t w, uint8_t h, TwoWire *twi = &Wire,
					   int8_t rst_pin, uint32_t clkDuring,
					   uint32_t clkAfter)
	: Adafruit_SSD1306(w, h, twi, rst_pin, clkDuring, clkAfter)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}
SSD1306TUR::SSD1306TUR(uint8_t w, uint8_t h, int8_t mosi_pin, int8_t sclk_pin,
					   int8_t dc_pin, int8_t rst_pin, int8_t cs_pin)
	: Adafruit_SSD1306(w, h, mosi_pin, sclk_pin, dc_pin, rst_pin, cs_pin)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}
SSD1306TUR::SSD1306TUR(uint8_t w, uint8_t h, SPIClass *spi, int8_t dc_pin,
					   int8_t rst_pin, int8_t cs_pin, uint32_t bitrate)
	: Adafruit_SSD1306(w, h, spi, dc_pin, rst_pin, cs_pin, bitrate)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}
SSD1306TUR::SSD1306TUR(int8_t mosi_pin, int8_t sclk_pin, int8_t dc_pin,
					   int8_t rst_pin, int8_t cs_pin)
	: Adafruit_SSD1306(mosi_pin, sclk_pin, dc_pin, rst_pin, cs_pin)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}
SSD1306TUR::SSD1306TUR(int8_t dc_pin, int8_t rst_pin, int8_t cs_pin)
	: Adafruit_SSD1306(dc_pin, rst_pin, cs_pin)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}

SSD1306TUR::SSD1306TUR(int8_t rst_pin)
	: Adafruit_SSD1306(rst_pin)
{
	textcolor = textbgcolor = SSD1306_WHITE;
}

size_t SSD1306TUR::write(uint8_t chr)
{
	if (chr == 195)
	{
		f195 = 1;
		sent = 0;
		return 1;
	}
	if (chr == 196)
	{
		f196 = 1;
		sent = 0;
		return 1;
	}
	if (chr == 197)
	{
		f197 = 1;
		sent = 0;
		return 1;
	}
	if (f196 == 1)
	{
		resetFs();
		if (chr == 177)
			chr = 0x7F;
		else if (chr == 176)
			chr = 0x80;
		else if (chr == 158)
			chr = 0x81;
		else if (chr == 159)
			chr = 0x82;
	}

	if (f195 == 1)
	{
		resetFs();
		if (chr == 182)
			chr = 0x83;
		else if (chr == 150)
			chr = 0x84;
		else if (chr == 156)
			chr = 0x85;
		else if (chr == 188)
			chr = 0x86;
		else if (chr == 135)
			chr = 0x87;
		else if (chr == 167)
			chr = 0x88;
	}
	if (f197 == 1)
	{
		resetFs();
		if (chr == 158)
			chr = 0x89;
		else if (chr == 159)
			chr = 0x8A;
	}
	return (sent ? Adafruit_SSD1306::write(chr) : 1);
}
void SSD1306TUR::resetFs()
{
	f195 = f196 = f197 = 0;
	sent = 1;
}