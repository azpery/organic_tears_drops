#include "Arduino.h"
#include <FastLED.h>

#include "scenarioWave.h"

bool ScenarioWave::run() 
{
    CRGB colors[] = {CRGB(255,255,175), CRGB(255,255,102), CRGB(255,204,0), CRGB(255,153,0), CRGB(255,102,0), CRGB(255,51,0), CRGB(255,0,0), CRGB(255,0,51), CRGB(255,0,102), CRGB(255,0,153), CRGB(255,0,204), CRGB(255,0,255), CRGB(204,0,255), CRGB(153,0,255), CRGB(102,0,255), CRGB(51,0,255), CRGB(0,0,255), CRGB(0,51,255), CRGB(0,102,255), CRGB(0,153,255), CRGB(0,204,255), CRGB(0,255,255), CRGB(0,255,204), CRGB(0,255,153), CRGB(0,255,102), CRGB(0,255,51)};

    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setColor(colors[i]);
        _chipsD[i].setColor(colors[i]);
        // _chips[i].rainbow();
        // _chips[i].deltaBrightness(i);
        _chipsG[i].ondulate();
        if(_chipsD[i].ondulate() && i == _amountOfChips-1){
            return true;
        }
    }
    return false;
}

void ScenarioWave::setup()
{
    setSpeed(100);
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setBrightness(10+i*40);
        _chipsD[i].setBrightness(10+i*40);
    }
}