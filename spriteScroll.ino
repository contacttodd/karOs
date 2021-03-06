// Size of sprite image for the scrolling text, this requires ~14 Kbytes of RAM
#define IWIDTH  320
#define IHEIGHT 30

// Pause in milliseconds to set scroll speed
#define WAIT 30

#include <TFT_eSPI.h>                 // Include the graphics library (this includes the sprite functions)

TFT_eSPI    tft = TFT_eSPI();         // Create object "tft"

TFT_eSprite img = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object
//                                    // the pointer is used by pushSprite() to push it onto the TFT

// -------------------------------------------------------------------------
// Setup
// -------------------------------------------------------------------------
void setup(void) {
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLUE);
}

// -------------------------------------------------------------------------
// Main loop
// -------------------------------------------------------------------------
void loop() {

  while (1)
  {
    // Create the sprite and clear background to black
    img.createSprite(IWIDTH, IHEIGHT);
    
    for (int pos = IWIDTH; pos > 0; pos--)
    {
      build_banner("Hello World", pos);
      img.pushSprite(0, 0);

      delay(WAIT);
    }

    // Delete sprite to free up the memory
    img.deleteSprite();
  }
}

// #########################################################################
// Build the scrolling sprite image from scratch, draw text at x = xpos
// #########################################################################

void build_banner(String msg, int xpos)
{
  int h = IHEIGHT;
  img.fillSprite(40);
  
  // Now print text on top of the graphics
  img.setTextSize(1);           // Font size scaling is x1
  img.setTextFont(4);           // Font 4 selected
  img.setTextColor(TFT_WHITE);  // Black text, no background colour
  img.setTextWrap(false);       // Turn of wrap so we can print past end of sprite

  // Need to print twice so text appears to wrap around at left and right edges
  img.setCursor(xpos, 2);  // Print text at xpos
  img.print(msg);

  img.setCursor(xpos - IWIDTH, 2); // Print text at xpos - sprite width
  img.print(msg);
}
