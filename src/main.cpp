#include <Arduino.h>
#include "SSD1306TUR.h"
//#include "Fonts/FreeSerifItalic9pt7b.h"
//#include "Fonts/FreeSerif24pt7b.h"
#include "TrFonts/FreeSansBold12pt7bTR.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
SSD1306TUR display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void testscrolltext(void);
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
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  testscrolltext();
}

void loop() {
  // put your main code here, to run repeatedly:
}
void testscrolltext(void)
{
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.setTextSize(1);
  display.println("       SSD1306");
  display.setFont(&FreeSansBold12pt7bTR);
  display.setCursor(20, 22);
  display.print("Türkçe");
  display.display(); // Show initial text
  delay(3000);
  

  // Scroll in various directions, pausing in-between:
  // display.startscrollright(0x00, 0x0F);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
  // display.startscrollleft(0x00, 0x0F);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
  // display.startscrolldiagright(0x00, 0x07);
  // delay(2000);
  // display.startscrolldiagleft(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
}