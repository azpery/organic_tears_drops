#include "Arduino.h"
#include <FastLED.h>

#include "scenario.h"

Scenario::Scenario()
{
    for(int i = 0; i < _amountOfChips * 2; i++){
        _chips[i] = Chips();
    }
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i] = Chips();
        _chipsD[i] = Chips();
    }

    _speed = 0;
    _index = 0;
    _amountOfChips = 5;

}

Scenario::Scenario(Chips chips[], Chips chipsG[], Chips chipsD[],  int amountOfChips)
{
    _amountOfChips = amountOfChips;
    for(int i = 0; i < _amountOfChips * 2; i++){
        _chips[i] = chips[i];
    }
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i] = chipsG[i];
        _chipsD[i] = chipsD[i];
    }
    _speed = 0;
    _index = 0;
}

bool Scenario::loop()
{
    if(run()){
        _loopCounter++;
    }
    // delay(_speed);
    _index++;
    if(_index > 2147483640){
        _index = 0;
    }
    if(_loopCounter >= _amountOfLoop){
        _loopCounter = 0;
        return true;
    }
    return false;
}



void Scenario::setup()
{
    
}

void Scenario::setSpeed(int speed)
{
    if(speed > 100)
    {
        speed = 100;
    }
    if(speed < 0)
    {
        speed = 0;
    }
    _speed = 100-speed;
}

void Scenario::setAmountOfLoops(int amountOfLoops)
{
    _amountOfLoop = amountOfLoops;
}