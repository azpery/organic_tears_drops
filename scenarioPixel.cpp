#include "Arduino.h"
#include <FastLED.h>

#include "scenarioPixel.h"

ScenarioPixel::ScenarioPixel(Chips chips[], Chips chipsG[], Chips chipsD[],  int amountOfChips) : Scenario(chips, chipsG, chipsD, amountOfChips)
{
    for(int i = 0; i< _amountOfPixels; i++){
        _pixels[i] = Pixel(0, 1);
    }
}

bool ScenarioPixel::run() 
{
    bool addPixel = false;
    for(int i = 0; i < _amountOfPixels; i++){
        _chipsG[_pixels[i]._chips].turnOff(_pixels[i]);
        _chipsD[_pixels[i]._chips].turnOff(_pixels[i]);
        if(!_pixels[i].nextPosition()){
            
            _pixels[i].nextChips(_amountOfChips);
            _pixels[i].nextIndex(_chipsG[_pixels[i]._chips].getNumOfLeds());
        }
        _chipsG[_pixels[i]._chips].turnOn(_pixels[i]);
        _chipsD[_pixels[i]._chips].turnOn(_pixels[i]);
    }

    _i++;
    if(_i > 10)
    {
        _i = 0;
        if(_amountOfPixels <  sizeof(_pixels) / sizeof(Pixel)){
            _amountOfPixels++;
        }
    }
    if(_amountOfPixels ==  sizeof(_pixels) / sizeof(Pixel)){
        // _amountOfPixels = 0;
        // for(int i = 0; i < _amountOfPixels; i++){
        //     _chipsG[_pixels[i]._chips].turnOff(_pixels[i]);
        //     _chipsD[_pixels[i]._chips].turnOff(_pixels[i]);
        // }
        return true;
    }
    return false;
}

void ScenarioPixel::setup()
{
    _amountOfLoop = 1;
    for(int i = 0; i< sizeof(_pixels) / sizeof(Pixel); i++){
        _pixels[i] = Pixel(_chipsG[i].getNumOfLeds(), i);
    }
    for (int i = 0; i < _amountOfChips * 2; i++)
    {
        _chipsG[i].setBrightness(255);
        _chipsD[i].setBrightness(255);
        _chips[i].setColor(CRGB::Black);
    }
}