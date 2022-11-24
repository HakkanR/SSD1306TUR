/**
 * @file SSD1306TUR.h
 * @author Hakan ÖZMEN (hakkanr@gmail.com)
 * @brief
 * This is a library based on Adafruit's SSD1306 library for monochrome oled
 * displays, It targets to bring ability to use Turkish alphabet freely with these
 * oled screens. Adafruit_SSD1306 and Adafruit_GFX libraries are needed to use this
 * library but not enought to have Turkish letters, You should use font files in folder
 * TrFonts of this library. Notice that file names end with TR expression.
 *
 * @version 1.0.1
 * @date 2022-11-09
 * @section for more information please visit :
 * https://www.devrelerim.com/2022/11/ssd1306tur-ssd1306-oled-ekran-turkce.html
 * https://www.youtube.com/HakkanR
 * https://github.com/HakkanR/SSD1306TUR
 * @copyright
 * BDS License, all above text must be included any redistribution.
 *
 */
#ifndef SSD1306TUR_H_
#define SSD1306TUR_H_
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Corner Defines for Circle Helper Function
#define CORNLUP 1 // Top left corner of a circle
#define CORNLDN 8 // Buttom left corner of a circle
#define CORNRUP 2 // Top right corner of a circle
#define CORNRDN 4 // Buttom right corner of a circle

class SSD1306TUR : public Adafruit_SSD1306
{
public:
	// NEW CONSTRUCTORS -- recommended for new projects
	SSD1306TUR(uint8_t w, uint8_t h, TwoWire *twi,
			   int8_t rst_pin = -1, uint32_t clkDuring = 400000UL,
			   uint32_t clkAfter = 100000UL);
	SSD1306TUR(uint8_t w, uint8_t h, int8_t mosi_pin, int8_t sclk_pin,
			   int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);
	SSD1306TUR(uint8_t w, uint8_t h, SPIClass *spi, int8_t dc_pin,
			   int8_t rst_pin, int8_t cs_pin, uint32_t bitrate = 8000000UL);

	// DEPRECATED CONSTRUCTORS - for back compatibility, avoid in new projects
	SSD1306TUR(int8_t mosi_pin, int8_t sclk_pin, int8_t dc_pin,
			   int8_t rst_pin, int8_t cs_pin);
	SSD1306TUR(int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);
	SSD1306TUR(int8_t rst_pin = -1);
	virtual size_t write(uint8_t);
private:
	void resetFs();
private:
	uint8_t f195 = 0, f196 = 0, f197 = 0;
	uint8_t sent = 1;
};

#endif