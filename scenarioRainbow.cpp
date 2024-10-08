#include "Arduino.h"
#include <FastLED.h>

#include "scenarioRainbow.h"

bool ScenarioRainbow::run() 
{
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].rainbow();
        if(_chipsD[i].rainbow() && i == _amountOfChips-1){
            return true;
        }
        // _chipsG[i].ondulate();
        // _chipsD[i].ondulate();
    }
    return false;   
}

void ScenarioRainbow::setup()
{
    _amountOfLoop = 3;
    setSpeed(100);
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setBrightness(255);
        _chipsD[i].setBrightness(255);
        _chipsG[i].initRainbow();
        _chipsD[i].initRainbow();
    }
}
