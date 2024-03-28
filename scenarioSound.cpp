#include "Arduino.h"
#include <FastLED.h>

#include "scenarioSound.h"

bool ScenarioSound::run()
{
    for (int i = 0; i < _amountOfChips; i++)
    {
        _chipsG[i].doubleRainbow(random(100, random(500, random(600, random(600, random(600, 1023))))));
        _chipsD[i].doubleRainbow(random(100, random(500, random(600, random(600, random(600, 1023))))));
    }
    EVERY_N_MILLISECONDS(500)
    {
        for (int i = 0; i < _amountOfChips; i++)
        {
            _chipsG[i].doubleRainbow(900 - ((_amountOfChips - i  - 1) * 100));
            _chipsD[i].doubleRainbow(900 - ((_amountOfChips - i  - 1) * 100));
        }
    }

    EVERY_N_BSECONDS(30){
        _end = true;
    }
    return _end;
}
void ScenarioSound::setup()
{
    _amountOfLoop = 1;
    for (int i = 0; i < _amountOfChips * 2; i++)
    {
        getChips(i)->setColor(CRGB::Black);
    }
}