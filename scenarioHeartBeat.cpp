#include "Arduino.h"
#include <FastLED.h>

#include "scenarioHeartBeat.h"

bool ScenarioHeartBeat::run()
{
    bool end = false;
    int mode = _mode;
    if(mode != 8){
        for (int i = 0; i < _amountOfChips; i++)
        {
            _chipsG[i].addToColor();
            _chipsD[i].addToColor();
            if(mode == 0){
                _chipsG[i].fadeUp(40);
                if(_chipsD[i].fadeUp(40)){
                    _mode = 1;
                }
            }
            else if(mode == 1){
                _chipsG[i].fadeDown(30, 120);
                if(_chipsD[i].fadeDown(30, 120)){
                    _mode = 2;
                }
            }
            else if(mode == 2){
                _chipsG[i].fadeUp(40);
                if(_chipsD[i].fadeUp(40)){
                    _mode = 3;
                }
            }
            else if(mode == 3){
                _chipsG[i].fadeDown(30, 20);
                if(_chipsD[i].fadeDown(30, 20)){
                    _mode = 4;
                    
                }
            }
            else if(mode == 4){
                _chipsG[i].fadeUp(40);
                if(_chipsD[i].fadeUp(40)){
                    _mode = 5;
                }
            }else if(mode == 5){
                _chipsG[i].fadeDown(30, 120);
                if(_chipsD[i].fadeDown(30, 120)){
                    _mode = 6;
                }
            }else if(mode == 6){
                _chipsG[i].fadeUp(40);
                if(_chipsD[i].fadeUp(40)){
                    _mode = 7;
                }
            }else if(mode == 7){
                _chipsG[i].fadeDown(30, 20);
                if(_chipsD[i].fadeDown(30, 20)){
                    if(rand()%2 == 0){
                        _mode = 0;
                    }else{
                        _mode = 8;
                    }
                }
            }else if(mode == 9){
                _chipsG[i].fadeDown(30);
                if(_chipsD[i].fadeDown(30) && i == _amountOfChips-1){
                    _mode = 0;
                    end = true;
                }
            }

        }
    }
    if(_mode == 8){
        if(fadeUpAndDown(_index)){
            _index++;
            if(_index >= _amountOfChips){
                _index = 0;
                _mode = 9;
            }
        };

    }
    
    return end;
}



bool ScenarioHeartBeat::fadeUpAndDown(int index)
{
    bool r = true;

    for(int i = 0; i < _amountOfChips; i++){
        if(i != _index){
            _chipsG[i].fadeDown(20) ;
            _chipsD[i].fadeDown(20) ;
        }
    }

    r = _chipsG[_index].fadeUp(86) && r;
    r = _chipsD[_index].fadeUp(86) && r;


    return r;
}

void ScenarioHeartBeat::setup()
{
    setSpeed(100);
    _amountOfLoop = 5;
    CRGB colors[] = {CRGB(255, 255, 175), CRGB(255, 255, 102), CRGB(255, 204, 0), CRGB(255, 153, 0), CRGB(255, 102, 0), CRGB(255, 51, 0), CRGB(255, 31, 0), CRGB(255, 0, 51), CRGB(255, 0, 102), CRGB(255, 0, 153), CRGB(255, 0, 204), CRGB(255, 0, 255), CRGB(304, 0, 255), CRGB(153, 0, 255), CRGB(102, 0, 255), CRGB(51, 0, 255), CRGB(0, 0, 255), CRGB(0, 51, 255), CRGB(0, 102, 255), CRGB(0, 153, 255), CRGB(0, 204, 255), CRGB(0, 255, 255), CRGB(0, 255, 204), CRGB(0, 255, 153), CRGB(0, 255, 102), CRGB(0, 255, 51)};

    for (int i = 0; i < _amountOfChips; i++)
    {
        _chipsG[i].setColor(colors[i]);
        _chipsD[i].setColor(colors[i]);
        _chipsG[i].setBrightness(0);
        _chipsD[i].setBrightness(0);
    }
}