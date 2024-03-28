#include "Arduino.h"
#include <FastLED.h>

#include "scenario.h"

Scenario::Scenario()
{
    // for(int i = 0; i < _amountOfChips * 2; i++){
    //     getChips(i) = Chips();
    // }
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
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i] = chipsG[i];
        _chipsD[i] = chipsD[i];
    }
    _speed = 0;
    _index = 0;
}

Scenario::Scenario(Chips chipsG[], Chips chipsD[],  int amountOfChips)
{
     _amountOfChips = amountOfChips;
    
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i] = chipsG[i];
        _chipsD[i] = chipsD[i];
    }
    _speed = 0;
    _index = 0;
}

Chips * Scenario::getChips(int index)
{
    if(index < _amountOfChips){
        return &_chipsG[_amountOfChips - index - 1];
    }else{
        return &_chipsD[index - _amountOfChips];
    }
}

bool Scenario::loop()
{
    fadeUp();
    if(run()){
        _loopCounter++;
    }
    // delay(_speed);
    _index++;
    if(_index > 2147483640){
        _index = 0;
    }
    if(_loopCounter >= _amountOfLoop && fadeDown()){
        _loopCounter = 0;
        _end = false;
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

bool Scenario::fadeDown()
{
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setMaxBrightnessRatio(_maxBrightnessRatio);
        _chipsD[i].setMaxBrightnessRatio(_maxBrightnessRatio);
        getChips(i)->setMaxBrightnessRatio(_maxBrightnessRatio);
        getChips(i + _amountOfChips)->setMaxBrightnessRatio(_maxBrightnessRatio);
    }
    _maxBrightnessRatio -= 0.04;
    if(_maxBrightnessRatio <= 0){
        _maxBrightnessRatio = 0;
        return true;
    }
    return false;
}

bool Scenario::fadeUp()
{
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setMaxBrightnessRatio(_maxBrightnessRatio);
        _chipsD[i].setMaxBrightnessRatio(_maxBrightnessRatio);
        getChips(i)->setMaxBrightnessRatio(_maxBrightnessRatio);
        getChips(i + _amountOfChips)->setMaxBrightnessRatio(_maxBrightnessRatio);
    }
   
    _maxBrightnessRatio += 0.02;
    if(_maxBrightnessRatio >= 1){
        _maxBrightnessRatio = 1;
        return true;
    }
    return false;
}

void Scenario::setMode(int mode)
{
    _mode = mode;
}