#include "Arduino.h"
#include <FastLED.h>

#include "scenarioStart.h"

bool ScenarioStart::run()
{
    bool end = fadeUpAndDown(_index);
    if (end)
    {
        if (_direction)
        {
            _index++;
        }
        else
        {
            _index--;
        }
        if (_index >= _amountOfChips)
        {
            _index = 0;
            // _direction = false;
            return true;
        }
        if (_index < 0)
        {
            _index = 0;
            _direction = true;
            return true;
        }
    }
    return false;
}

bool ScenarioStart::fadeUpAndDown(int index)
{
    bool r = true;

    for(int i = 0; i < _amountOfChips; i++){
        if(i != _index){
            _chipsG[i].fadeDown(40) ;
            _chipsD[i].fadeDown(40) ;
        }
    }

    r = _chipsG[_index].fadeUp(100) && r;
    r = _chipsD[_index].fadeUp(100) && r;

    if(_index > _amountOfChips-1){
        _chipsG[_index+1].fadeUp(10) ;
        _chipsD[_index+1].fadeUp(10);
    }

    return r;
}

void ScenarioStart::setup()
{
    setSpeed(100);
    _amountOfLoop = 10;
    CRGB colors[] = {CRGB(255, 255, 175), CRGB(255, 255, 102), CRGB(255, 204, 0), CRGB(255, 153, 0), CRGB(255, 102, 0), CRGB(255, 51, 0), CRGB(255, 0, 0), CRGB(255, 0, 51), CRGB(255, 0, 102), CRGB(255, 0, 153), CRGB(255, 0, 204), CRGB(255, 0, 255), CRGB(204, 0, 255), CRGB(153, 0, 255), CRGB(102, 0, 255), CRGB(51, 0, 255), CRGB(0, 0, 255), CRGB(0, 51, 255), CRGB(0, 102, 255), CRGB(0, 153, 255), CRGB(0, 204, 255), CRGB(0, 255, 255), CRGB(0, 255, 204), CRGB(0, 255, 153), CRGB(0, 255, 102), CRGB(0, 255, 51)};

    for (int i = 0; i < _amountOfChips; i++)
    {
        _chipsG[i].setColor(colors[i]);
        _chipsD[i].setColor(colors[i]);
        _chipsG[i].setBrightness(0);
        _chipsD[i].setBrightness(0);
    }
}