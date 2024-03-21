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
    setSpeed(100);
    // for(int i = 0; i < _amountOfChips; i++){
    //     _chipsG[i].setBrightness(10+i*40);
    //     _chipsD[i].setBrightness(10+i*40);
    // }
}
