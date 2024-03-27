#include "Arduino.h"
#include <FastLED.h>

#include "pixel.h"

Pixel::Pixel(int amountOfPixels, int pos)
{
    _chips = 0;
    _index = 0;
    _direction = true;
    _amountOfPixels = amountOfPixels;
    _chipsDirection = true;
    _speed = 2;
    _color = CRGB(255, pos*10, pos);
}

Pixel::Pixel()
{
    _chips = 0;
    _index = 0;
    _direction = false;
    _amountOfPixels = 1;
    _chipsDirection = true;
    _speed = 2;
    _color = CRGB(random(0, 255), random(0, 255), random(0, 255));
}

bool Pixel::nextPosition()
{
    if (_direction)
    {
        if (_chipsDirection)
        {
            _index += _speed;
        }
        else
        {
            _index -= _speed;
        }
    }
    else
    {
        if (_chipsDirection)
        {
            _index -= _speed;
        }
        else
        {
            _index += _speed;
        }
    }
    if (_index >= _amountOfPixels)
    {
        return false;
    }
    if (_index < 0)
    {
        return false;
    }
    return true;
}

void Pixel::nextChips(int maxChips)
{
    if (_direction)
    {
        _chips++;
        if (_chips >= maxChips)
        {
            _chips = 0;
        }
    }
    else
    {
        _chips--;
        if (_chips < 0)
        {
            _chips = maxChips - 1;
        }
    }
    _chipsDirection = !_chipsDirection;
}

void Pixel::nextIndex(int amountOfPixels)
{
    _amountOfPixels = amountOfPixels;

    if (_direction)
    {

        if (_index > 0)
        {
            _index = amountOfPixels - 1;
        }
        else
        {
            _index = 0;
        }
    }else{
        if (_index <= 0)
        {
            _index = 0;
        }
        else
        {
            _index = amountOfPixels - 1;
        }
    }
}
