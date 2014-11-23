/* LedStripSnowflake: Example Arduino sketch that shows
 * how to make a variable falling snowflake pattern on an
 * Addressable RGB LED Strip.
 *
 * To use this, you will need to plug an Addressable RGB LED
 * strip into pin 12.  After uploading the sketch,
 * you should see a falling white snowflake.
 *
 */

#include <PololuLedStrip.h>

// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<12> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 16
#define DELAY 30
rgb_color colours[LED_COUNT];
int length = 2;
int pause = 500;

rgb_color white = (rgb_color){255, 255, 255};
rgb_color black = (rgb_color){0, 0, 0};

int start=LED_COUNT;

void setup()
{
}

void loop()
{  
  for(int i = 0; i < LED_COUNT; i++) {    
    if(i==start) {
      for(int j = 0; j < length && i < LED_COUNT; i++, j++) {
        colours[i] = white;
      }
    }
    else {
      colours[i] = black;
    }
  }
  
  // Write the colors to the LED strip.
  ledStrip.write(colours, LED_COUNT);

  delay(DELAY);
  
  start--;
  if (start <0) {
    start=LED_COUNT;
    
    pause = random(500, 2000);
    delay(pause);
    
    length = random(2, 5);
  }
}
