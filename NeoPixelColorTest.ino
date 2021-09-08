#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>    // https://github.com/adafruit/Adafruit_NeoPixel

#define NEOPIXEL_PIN 3
#define NUM_PIXELS 32

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(120000);
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop()
{
  uint8_t R=(uint8_t)PromptAndGetIntRange("RED:",0,255);
  Serial.println(R);
  strip.clear();
  strip.show();
  uint8_t G=(uint8_t)PromptAndGetIntRange("GREEN:",0,255);
  Serial.println(G);
  uint8_t B=(uint8_t)PromptAndGetIntRange("BLUE:",0,255);
  Serial.println(B);

  uint32_t c=Adafruit_NeoPixel::Color(R,G,B);
  
  Serial.println();
  Serial.print("Color value: 0x");
  Serial.print(c,HEX);
  Serial.println();
  
  LightThePixels(c);
}

int PromptAndGetIntRange(char *pmt, int mn, int mx)
{
  int x;
  do
  {
    Serial.println(pmt);
    x=Serial.parseInt();
  } while (x<mn || x>mx);
  return x;
}

void LightThePixels(uint32_t c)
{
  strip.fill(c);
  delay(10);
  strip.show();
}
