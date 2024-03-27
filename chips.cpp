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
    _brightness = 255;
    _waveDirection = false;
    _color = CRGB::Black;
    _colorDirection = true;
    _pin = pin;
    const int PIN = _pin;
    _maxBrightnessRatio = 0;
    _realBrightness = 0;
}

Chips::Chips()
{
    _leds = NULL;
    _num_of_leds = 0;
    _index = 0;
    _direction = true;
    _rainbowDirection = true;
    _waveDirection = false;
    _color = CRGB::Black;
    _colorDirection = true;
    _pin = 0;
    _maxBrightnessRatio = 0;
     _realBrightness = 0;
     _brightness = 255;
    
}

bool Chips::goesUp(){
    return _waveDirection;
}

bool Chips::goesDown(){
    return !_waveDirection;
}

void Chips::setMaxBrightnessRatio(float maxBrightnessRatio){
    if(maxBrightnessRatio < 0){
        _maxBrightnessRatio = 0;
    }else if(maxBrightnessRatio > 1){
        _maxBrightnessRatio = 1;
    }else{
        _maxBrightnessRatio = maxBrightnessRatio;
    }
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

void Chips::initRainbow(){
    CHSV hsv;
    hsv.hue = 20;
    hsv.val = 255;
    hsv.sat = 240;
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i] = hsv;
        hsv.hue += 1;
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
        _leds[i].setHSV(hsv.hue, hsv.sat, hsv.val);
        hsv.hue += 1;
        hsv.val = round(255*_maxBrightnessRatio);
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
    _hsv.hue += 2;
    fill_solid(_leds, _num_of_leds, _hsv);
}

void Chips::createHsv(int hue){
    _hsv.hue = hue;
    _hsv.sat = 255;
    _hsv.val = 255;
}

bool Chips::ondulate(){

    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_realBrightness);
    }

    if(_waveDirection){
        addToBrightness(15);
    }
    if(!_waveDirection){
        addToBrightness(-15);
    }
    if(_brightness <= 0){
        _brightness = 0;
        _waveDirection = true;
    }else if(_brightness >= 255){
        _brightness = 255;
        _waveDirection = false;
        return true;
    }
    return false;
}

void Chips::setColor(CRGB color){
    _color = color;
    fill_solid(_leds, _num_of_leds, color);
}

void Chips::addToColor(){
    if( _color.r >= 255){
        _colorDirection = false;
    }
    if( _color.r <= 0){
        _colorDirection = true;
    }
    if(_colorDirection){
        _color.r++;
    }else{
        _color.r--;
    }
    
    fill_solid(_leds, _num_of_leds, _color);
}

void Chips::setBrightness(int brightness){
    _brightness = brightness;
    if(_brightness > 255){
        _brightness = 255;
    }else if(_brightness < 0){
        _brightness = 0;
    }
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_realBrightness);
    }
    fill_solid(_leds, _num_of_leds, _color);
}

void Chips::deltaBrightness(int delta){
    if(_waveDirection){
        addToBrightness(delta);
    }else{
        addToBrightness(-delta);
    }
    if(_brightness > 255){
        _brightness = 255;
    }else if(_brightness < 0){
        _brightness = 0;
    }
}

bool Chips::fadeUpAndDown(CRGB color, int speed, int maxBrightness){
    fill_solid(_leds, _num_of_leds, color);
    deltaBrightness(speed); 
    for(int i = 0; i < _num_of_leds; i++){
        if(_brightness > maxBrightness){
            _leds[i].maximizeBrightness(maxBrightness);
        }else{
            _leds[i].maximizeBrightness(_realBrightness);
        }
    }
    if(_brightness == 255 || _brightness >= maxBrightness){
        _waveDirection = false;
        return true;
        
    }
    if(_brightness == 0 && !_waveDirection){
        _waveDirection = true;
        return true;
    }

    return false;
}

bool Chips::fadeUp(int speed){
    fill_solid(_leds, _num_of_leds, _color);
    addToBrightness(speed);
    _waveDirection = true;
   
    if(_brightness > 255){
        _brightness = 255;
    }
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_realBrightness);
    }
    if(_brightness == 255){
       return true;
    }

    return false;
}

bool Chips::fadeDown(int speed, int minBrightness){
    fill_solid(_leds, _num_of_leds, _color);
    addToBrightness(-speed, 255, minBrightness);
    _waveDirection = false;
    for(int i = 0; i < _num_of_leds; i++){
        _leds[i].maximizeBrightness(_realBrightness);
    }
    if(_brightness == minBrightness){
        return true;
    }
    return false;
}

void Chips::addToBrightness(int delta, int maxBrightness, int minBrightness){
    _brightness += delta;
    if(_brightness > maxBrightness){
        _brightness = maxBrightness;
    }else if(_brightness < minBrightness){
        _brightness = minBrightness;
    }
    _realBrightness =  round(_maxBrightnessRatio * _brightness);
}

void Chips::turnOff(Pixel pixel){
   
    _realBrightness =  round(_maxBrightnessRatio * _brightness);
    for(int i = -3; i < 4; i++){
        if(pixel._index + i >= 0 && pixel._index + i < _num_of_leds){
            _leds[pixel._index + i] = CRGB::Black;
            _leds[pixel._index + i].maximizeBrightness(_realBrightness);
        }
    }
}

void Chips::turnOn(Pixel pixel){
    
    _realBrightness =  round(_maxBrightnessRatio * _brightness);
    for(int i = -3; i < 4; i++){
        if(pixel._index + i >= 0 && pixel._index + i < _num_of_leds){
            _leds[pixel._index + i] = pixel._color;
            _leds[pixel._index + i].maximizeBrightness(_realBrightness);
        }
    }
}
