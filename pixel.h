#ifndef Pixel_h
#define Pixel_h
#include "Arduino.h"
#include <FastLED.h>

class Pixel
{
    public:
        Pixel(int amountOfPixels, int pos);
        Pixel();
        bool nextPosition();
        void nextChips(int maxChips);
        void nextIndex(int amountOfPixels);
        int _chips = 0;
        int _amountOfPixels = 1;
        int _index = 0;
        bool _direction = true;
        bool _chipsDirection = true;
        int _speed = 1;
        CRGB _color = CRGB::Red;
};
#endif