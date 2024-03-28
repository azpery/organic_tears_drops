#ifndef Chips_h
#define Chips_h
#include "Arduino.h"
#include "pixel.h"
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
        bool fadeUpAndDown(CRGB color, int speed, int maxBrightness = 255);
        bool fadeDown(int speed, int minBrightness = 0);
        void addToHsv();
        void createHsv(int hue);
        void setMaxBrightnessRatio(float maxBrightnessRatio);
        bool goesUp();
        bool goesDown();
        void turnOff(Pixel pixel);
        void turnOn(Pixel pixel);
        void initRainbow();
        void randomOnOff();
        void doubleRainbow(long react);
        CRGB scroll(int pos); 

    private:
        int _num_of_leds;
        int _midway;
        struct CRGB * _leds;
        int _index;
        int _brightness;
        int _realBrightness;
        float _maxBrightnessRatio;
        bool _direction;
        bool _rainbowDirection;
        bool _waveDirection;
        bool _colorDirection;
        CRGB _color;
        CHSV _hsv;
        int _pin;
        void runForward();
        void runBackward();
        void addToBrightness(int delta, int maxBrightness = 255, int minBrightness = 0);
        long post_react = 0;
};
#endif