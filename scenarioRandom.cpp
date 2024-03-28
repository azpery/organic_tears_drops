#include "Arduino.h"
#include <FastLED.h>

#include "scenarioRandom.h"

bool ScenarioRandom::run() 
{
    EVERY_N_MILLISECONDS(50){

        for(int i = 0; i < _amountOfChips; i++){
            _chipsG[i].randomOnOff();
            _chipsD[i].randomOnOff();
        }
  
    }

    EVERY_N_BSECONDS(30){
        _end = true;
    }
    
    return _end;
}

void ScenarioRandom::setup()
{
    _j = 1;
    _i=1;
    _amountOfLoop = 1;
    for (int i = 0; i < _amountOfChips * 2; i++)
    {
        _chipsG[i].setBrightness(255);
        _chipsD[i].setBrightness(255);
        getChips(i)->setColor(CRGB::Black);
    }
}