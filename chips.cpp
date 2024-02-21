#include "Arduino.h"
#include <FastLED.h>

#include "chips.h"

Chips::Chips(int num_of_leds, struct CRGB * leds)
{

    _leds = leds;
    _num_of_leds = num_of_leds;
    _index = 0;
}

void Chips::next()
{
    _leds[_index] = CRGB::Black;
    _index++;
    if (_index >= _num_of_leds)
    {
        _index = 0;
    }
}
