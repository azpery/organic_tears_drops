#include "Arduino.h"
#include <FastLED.h>

#include "scenarioWaveColors.h"

bool ScenarioWaveColors::run()
{
    if (_mode == 2)
    {

        for (int i = 0; i < _amountOfChips * 2 ; i++)
        {
            getChips(i)->addToHsv();
            if (getChips(i)->ondulate() && i == _amountOfChips *2  - 1)
            {
                // if (_loopCounter == 20)
                // {
                //     for (int j = 0; j < _amountOfChips * 2; j++)
                //     {
                //         _chips[j].setBrightness(10 + ((_amountOfChips * 2 - 1) - j) * 15);
                //     }
                //     // _mode = 3;
                // }
                return true;
            }
        }

        return false;
    }
    else if (_mode == 3)
    {
        for (int i = 0; i < _amountOfChips * 2; i++)
        {
            getChips(i)->addToHsv();
            if (getChips(i)->ondulate() && i == _amountOfChips * 2 - 1)
            {

                return true;
            }
        }

        return false;
    }
    else
    {
        for (int i = 0; i < _amountOfChips; i++)
        {
            _chipsG[i].addToHsv();
            _chipsD[i].addToHsv();
            if (_mode == 0)
            {
                _chipsG[i].ondulate();
                if (_chipsD[i].ondulate() && i == _amountOfChips - 1)
                {
                    // if (_loopCounter == 5)
                    //     _mode = 1;
                    return true;
                }
            }
            else if (_mode == 1)
            {
                _chipsG[i].fadeUp(10);
                if (_chipsD[i].fadeUp(10) && i == _amountOfChips - 1)
                {
                    // _mode = 2;
                    return true;
                }
            }
        }
    }
    return false;
}

void ScenarioWaveColors::setup()
{
    _amountOfLoop = 15;
    setSpeed(100);
    if(_mode == 3){
        for (int j = 0; j < _amountOfChips * 2; j++)
        {
            getChips(j)->setBrightness(10 + ((_amountOfChips * 2 - 1) - j) * 15);
            getChips(j)->createHsv(j * 10);
        }
    }else if(_mode == 2){
        for (int i = 0; i < _amountOfChips * 2; i++)
        {
            getChips(i)->setBrightness(10 + i * 15);
            // getChips(i)->setBrightness(10 + ((_amountOfChips*2-1) - i) * 15);
            getChips(i)->createHsv(i * 10);
        }
    }else{
        for (int i = 0; i < _amountOfChips; i++)
        {
            _chipsG[i].setBrightness(10 + i * 40);
            _chipsD[i].setBrightness(10 + i * 40);
            _chipsG[i].createHsv(i * 10);
            _chipsD[i].createHsv(i * 10);
        }
        
    }
}