// New background colour
#define TFT_BROWN 0x38E0

// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 1000

#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  targetTime = millis();

  // First we test them with a background colour set
  tft.setTextSize(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Test 2", 0, 0, 4);
  tft.drawString("defghijklmno", 0, 26, 4);
  tft.drawString("pqrstuvwxyz", 0, 52, 4);
  int xpos = 0;
  xpos += tft.drawString("{|}~", 0, 78, 4);
  tft.drawChar(127, xpos, 78, 4);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);

  tft.drawString("Test 4", 0, 0, 7);
  tft.drawString("4567", 0, 60, 7);
  delay(WAIT);

  tft.setTextColor(TFT_MAGENTA, TFT_BROWN);

  tft.drawNumber(millis() - targetTime, 0, 180, 4);
  delay(4000);;

  // Now test them with transparent background
  targetTime = millis();

  tft.setTextSize(1);
  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_GREEN);

  tft.drawString("18  !\"#$%&'()*+,-./0123456", 0, 0, 2);
  tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
  tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
  tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
  xpos = 0;
  xpos += tft.drawString("xyz{|}~", 0, 64, 2);
  tft.drawChar(127, xpos, 64, 2);

  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.drawString("23 890:.", 0, 0, 7);
  tft.drawString("", 0, 60, 7);
  
  delay(4000);;
}
