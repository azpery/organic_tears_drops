#ifndef Chips_h
#define Chips_h
#include "Arduino.h"
#include <FastLED.h>

class Chips
{
public:
    Chips(int num_of_leds, struct CRGB * leds);
    void next();

private:
    int _num_of_leds;
    struct CRGB * _leds;
    int _index;
};
#endif