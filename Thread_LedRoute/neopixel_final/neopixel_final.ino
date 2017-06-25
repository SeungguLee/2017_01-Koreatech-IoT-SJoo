#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 13
#define PIN1 12
#define PIN2 11
#define PIN3 10
#define PIN4 9
#define PIN5 8
#define PIN6 7
#define PIN7 6
#define PIN8 5
#define PIN9 4
#define PIN10 3
#define PIN11 2
int red;
int blue;
int green;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, PIN1, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, PIN2, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(1, PIN3, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(1, PIN4, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(1, PIN5, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(1, PIN6, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(1, PIN7, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(1, PIN8, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(1, PIN9, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(1, PIN10, NEO_GBR + NEO_KHZ400);
Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(1, PIN11, NEO_GBR + NEO_KHZ400);
// IMPORTANT: To reduce NeoPixel burnout risk, add 00 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  strip6.begin();
  strip7.begin();
  strip8.begin();
  strip9.begin();
  strip10.begin();
  strip11.begin();
  
  strip.show(); // Initialize all pixels to 'off'
  strip1.show();
  strip2.show(); // Initialize all pixels to 'off'
  strip3.show();
  strip4.show(); // Initialize all pixels to 'off'
  strip5.show();
  strip6.show(); // Initialize all pixels to 'off'
  strip7.show();
  strip8.show(); // Initialize all pixels to 'off'
  strip9.show();
  strip10.show(); // Initialize all pixels to 'off'
  strip11.show();
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  char ch = Serial.read();
  red = random(256);
  green = random(126) + 130;
  blue = random(126) + 130;
  
  if(ch == '0'){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(0, 0, 0));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(0, 0, 0));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }    
  }else if(ch == '1'){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(red, green, blue));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(0, 0, 0));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(0, 0, 0));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }   
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '2'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(red, green, blue));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(0, 0, 0));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(0, 0, 0));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '3'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(red, green, blue));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(0, 0, 0));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '4'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(red, green, blue));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(0, 0, 0));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '5'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(red, green, blue));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(red, green, blue));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '6'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(red, green, blue));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(red, green, blue));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(0, 0, 0));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '7'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(red, green, blue));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(red, green, blue));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(red, green, blue));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(0, 0, 0));
      strip11.show();
    }
  }else if(ch == '8'){ 
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
      strip.show();
    }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, strip.Color(0, 0, 0));
      strip1.show();
    }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, strip.Color(0, 0, 0));
      strip2.show();
    }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, strip.Color(red, green, blue));
      strip3.show();
    }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, strip.Color(0, 0, 0));
      strip4.show();
    }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, strip.Color(0, 0, 0));
      strip5.show();
    }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, strip.Color(red, green, blue));
      strip6.show();
    }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, strip.Color(0, 0, 0));
      strip7.show();
    }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, strip.Color(0, 0, 0));
      strip8.show();
    }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, strip.Color(red, green, blue));
      strip9.show();
    }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, strip.Color(0, 0, 0));
      strip10.show();
    }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, strip.Color(red, green, blue));
      strip11.show();
    }
  } 
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  Serial.println(c);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
    strip3.setPixelColor(i, c);
    strip3.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
    strip4.setPixelColor(i, c);
    strip4.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
    strip5.setPixelColor(i, c);
    strip5.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip6.numPixels(); i++) {
    strip6.setPixelColor(i, c);
    strip6.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip7.numPixels(); i++) {
    strip7.setPixelColor(i, c);
    strip7.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip8.numPixels(); i++) {
    strip8.setPixelColor(i, c);
    strip8.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip9.numPixels(); i++) {
    strip9.setPixelColor(i, c);
    strip9.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip10.numPixels(); i++) {
    strip10.setPixelColor(i, c);
    strip10.show();
    delay(wait);
  }
    for(uint16_t i=0; i<strip11.numPixels(); i++) {
    strip11.setPixelColor(i, c);
    strip11.show();
    delay(wait);
  }
}

