#include "Arduino.h"
#include <FastLED.h>

#include "scenarioWaveColors.h"

bool ScenarioWaveColors::run() 
{
    if( _mode == 2){
        if(_loopCounter % 2 == 0){
            for(int i = 0; i < _amountOfChips*2; i++){
                _chips[i].addToHsv();
                if(_chips[i].ondulate() && i == _amountOfChips*2-1){
                    return true;
                }
            }
        }else{
            for(int i = _amountOfChips*2 - 1; i >=0 ; i--){
                _chips[i].addToHsv();
                if(_chips[i].ondulate() && i == 0){
                    return true;
                }
            }
        }
        
        return false;
    }else{
        for(int i = 0; i < _amountOfChips; i++){
            _chipsG[i].addToHsv();
            _chipsD[i].addToHsv();
            if(_mode == 0){
                _chipsG[i].ondulate();
                if(_chipsD[i].ondulate() && i == _amountOfChips-1 ){
                    if(_loopCounter == 5) _mode = 1;
                    return true;
                }
                
            }
            else if(_mode == 1){
                _chipsG[i].fadeUp(10);
                if(_chipsD[i].fadeUp(10) && i == _amountOfChips-1){
                    _mode = 2;
                    return true;
                }
            }
        }
    }
    return false;
}

void ScenarioWaveColors::setup()
{
    _amountOfLoop = 20;
    setSpeed(100);
    for(int i = 0; i < _amountOfChips; i++){
        _chipsG[i].setBrightness(10+i*40);
        _chipsD[i].setBrightness(10+i*40);
        _chipsG[i].createHsv(i*10);
        _chipsD[i].createHsv(i*10);
    }
    for(int i = 0; i < _amountOfChips*2; i++){
        _chips[i].setBrightness(10+i*15);
        _chips[i].createHsv(i*10);
    }
}