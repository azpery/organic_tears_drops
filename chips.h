#ifndef Chips_h
#define Chips_h
#include "Arduino.h"
#include <FastLED.h>

class Chips
{
    public:
        Chips(int num_of_leds, struct CRGB * leds, bool direction, int pin);
        Chips();
        void run();
        bool rainbow();
        bool ondulate();
        void setColor(CRGB color);
        void setBrightness(int brightness);
        void deltaBrightness(int delta);
        void addToColor();
        struct CRGB * getLeds();
        int getNumOfLeds();
        int getPin();
        bool fadeUp( int speed);
        bool fadeUpAndDown(CRGB color, int speed);
        void addToHsv();
        void createHsv(int hue);


    private:
        int _num_of_leds;
        struct CRGB * _leds;
        int _index;
        int _brightness;
        bool _direction;
        bool _rainbowDirection;
        bool _waveDirection;
        bool _colorDirection;
        CRGB _color;
        CHSV _hsv;
        int _pin;
        void runForward();
        void runBackward();
};
#endif