#include <FastLED.h>
#include "chips.h"

// How many leds in your strip?
#define NUM_LEDS 600

#define DATA_PIN 5

// Define the array of leds
CRGB rawleds[NUM_LEDS];
CRGBSet leds(rawleds, NUM_LEDS);
CRGBSet leds1(leds(0, 80));
CRGBSet leds2(leds(90, 180));
CRGBSet leds3(leds(190, 290));
CRGBSet leds4(leds(300, 380));
CRGBSet leds5(leds(381, 481));
CRGBSet leds6(leds(482, 600));
Chips myClass( 600, leds);
int amount[] = {80, 90, 100, 80, 100, 118};
struct CRGB *ledarray[] = {leds1, leds2, leds3, leds4, leds5, leds6};
int brightness[] = {7, 6, 5, 4, 3, 2};
bool way[] = {true, true, true, true, true, true};
int g[] = {10, 15, 20, 17, 18, 2};
int b[] = {10, 15, 20, 17, 18, 2};

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // GRB ordering is assumed
  fill_solid(leds, 600, CRGB::Black);
  FastLED.show();
}
int i = 0;

void loop()
{
  fill_solid(leds, 600, CRGB::Black);
  for (uint8_t led = 0; led < 6; led++)
  {
    blue(led);
  }
  FastLED.show();
}

int calculateBrightness(int ratio)
{
  return 255 * (ratio / 10);
}

int positions[] = {0, 0, 0, 0, 0, 0};
CRGB colors[] = {CRGB::AliceBlue, CRGB::Purple, CRGB::Green, CRGB::Blue, CRGB::Red, CRGB::SeaGreen};

bool blue(int chips)
{
  positions[chips] = illuminate(chips, positions[chips], colors[chips], 1);
  int nextPos = positions[chips] + 10;
  while (nextPos < amount[chips] * 2)
  {
    illuminate(chips, nextPos, colors[chips], chips + 1);
    nextPos += 10;
  }
}

int illuminate(int chips, int pos, CRGB color, int speed)
{

  if (pos <= amount[chips] - 1)
  {
    ledarray[chips][pos] = color;
  }
  else
  {
    ledarray[chips][pos - amount[chips]] = color;
  }
  if (pos < amount[chips] - 1)
  {
    int nextPos = pos + speed;
    return nextPos;
  }
  else
  {
    return 0;
  }
}
