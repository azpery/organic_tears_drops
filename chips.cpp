#include "Arduino.h"
#include <FastLED.h>

#include "chips.h"

Chips::Chips(int num_of_leds, struct CRGB * leds, bool direction, int pin)
{
    _leds = leds;
    _num_of_leds = num_of_leds;
    _index = 0;
    _direction = direction;
    _rainbowDirection = true;
    _brightness = 0;
    _waveDirection = false;
    _color = CRGB::Blue;
    _colorDirection = true;
    _pin = pin;
    const int PIN = _pin;
}

Chips::Chips()
{
    _leds = NULL;
    _num_of_leds = 0;
    _index = 0;
    _direction = true;
    _rainbowDirection = true;
    _waveDirection = false;
    _color = CRGB::Blue;
    _colorDirection = true;
    _pin = 0;
    
}

struct CRGB * Chips::getLeds(){
    return _leds;
}

int Chips::getNumOfLeds(){
    return _num_of_leds;
}

int Chips::getPin(){
    return _pin;
}

void Chips::run()
{
    if(_direction){
        runForward();
    }else{
        runBackward();
    }
}

void Chips::runForward()
{
    if(_index > 0){
        _leds[_index-1] = CRGB::Black;
    }else{
        _leds[_num_of_leds-1] = CRGB::Black;
    }
    _leds[_index] = CRGB::OrangeRed;
    _index++;

    if (_index >= _num_of_leds)
    {
        _index = _num_of_leds-1;
        _direction = false;
    }
}

void Chips::runBackward()
{
    if(_index < _num_of_leds-1){
        _leds[_index+1] = CRGB::Black;
    }else{
        _leds[0] = CRGB::Black;
    }
    _leds[_index] = CRGB::Blue;
    _index--;
    if (_index < 0)
    {
        _index = 0;
        _direction = true;
    }
}

bool Chips::rainbow()
{
    CHSV hsv;
    hsv.hue = 20;
    hsv.val = 255;
    hsv.sat = 240;
    int i = _index+1;
    while(i != _index){
        _leds[i] = hsv;
        hsv.hue += 1;
        i++;
        if(i >= _num_of_leds){
            i = 0;
        }
    }

    if(_direction){
        _index++;
    }else{
        _index--;
    }
    if (_index >= _num_of_leds-1)
    {
        _index = 0;
        return true;
    }
    if (_index < 0)
    {
        _index = _num_of_leds-1;
        return true;
    }
    return false;
    
}

void Chips::addToHsv(){
    _hsv.hue++;
    fill_solid(_leds, _num_of_leds, _hsv);
}

void Chips::createHsv(int hue){
    _hsv.hue = hue;
    _hsv.sat = 128;
    _hsv.val = 255;
}

bool Chips::ondulate(){

    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_brightness);
    }

    if(_waveDirection){
        _brightness +=  10;
    }
    if(!_waveDirection){
        _brightness -= 10;
    }
    if(_brightness <= 0){
        _brightness = 0;
        _waveDirection = true;
        return true;
    }else if(_brightness >= 255){
        _brightness = 255;
        _waveDirection = false;
    }
    return false;
}

void Chips::setColor(CRGB color){
    _color = color;
    fill_solid(_leds, _num_of_leds, color);
}

void Chips::addToColor(){
    _color++;
    fill_solid(_leds, _num_of_leds, _color);
}

void Chips::setBrightness(int brightness){
    _brightness = brightness;
    if(_brightness > 255){
        _brightness = 255;
    }else if(_brightness < 0){
        _brightness = 0;
    }
}

void Chips::deltaBrightness(int delta){
    if(_waveDirection){
        _brightness += delta;
    }else{
        _brightness -= delta;
    }
    if(_brightness > 255){
        _brightness = 255;
    }else if(_brightness < 0){
        _brightness = 0;
    }
}

bool Chips::fadeUpAndDown(CRGB color, int speed){
    fill_solid(_leds, _num_of_leds, color);
    deltaBrightness(speed); 
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_brightness);
    }
    if(_brightness == 255){
        _waveDirection = false;
        
    }
    if(_brightness == 0 && !_waveDirection){
        _waveDirection = true;
        return true;
    }

    return false;
}

bool Chips::fadeUp(int speed){
     _brightness += speed;
      _waveDirection = true;
   
    if(_brightness > 255){
        _brightness = 255;
    }
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_brightness);
    }
    if(_brightness == 255){
       return true;
    }

    return false;
}
