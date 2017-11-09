// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).
 
#include <Adafruit_NeoPixel.h>
 
#define PIN      6
#define N_LEDS 16
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.setBrightness(50);
}

uint32_t colours[16] = { strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(0,255,0),
                        strip.Color(255,255,0),
                        strip.Color(255,255,0),
                        strip.Color(255,255,0),
                        strip.Color(255,255,0),
                        strip.Color(255,0,0),
                        strip.Color(255,0,0),
                        strip.Color(255,0,0),
                        strip.Color(255,0,0)};
                        
 
void loop() {
  //chase(strip.Color(255, 0, 0)); // Red
  //chase(strip.Color(0, 255, 0)); // Green
  //chase(strip.Color(0, 0, 255)); // Blue
  //chase(strip.Color(255, 255, 255)); // White
  bar();
}

static all_same_colour(uint32_t colour) {
   for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i , colour); // Draw new pixel
   }
    
    strip.show();

}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.show();
      delay(25);
  }

  for(uint16_t i=0; i < 5; i++) {
    all_same_colour(strip.Color(255,255,255));
    delay(10);
    all_same_colour(0);
    delay(10);

  }
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(strip.numPixels()-i , 0); // Draw new pixel
      strip.show();
      delay(25);
  }

  
}

static set_bar(uint8_t value) {
  all_same_colour(0);

  for(uint8_t i=0; i< value; i++) {
    strip.setPixelColor(i  , colours[i]); // Draw new pixel
  }

  strip.show();
}

static void bar(void) {

  for(uint16_t i=0; i<=strip.numPixels(); i++) {
      set_bar(i);
      delay(25);
  }

  delay(100);

  for(uint16_t i=0; i < 10; i++) {
    all_same_colour(strip.Color(255,255,255));
    delay(20);
    all_same_colour(0);
    delay(20);
  }


  for(uint16_t i=0; i<= strip.numPixels(); i++) {
      set_bar(strip.numPixels() -i);
      delay(25);
  }
}

