#ifndef Scenario_h
#define Scenario_h
#include "chips.h"

class Scenario
{
    public:
        Scenario(Chips chips[], Chips chipsG[], Chips chipsD[], int amountOfChips);
        Scenario( Chips chipsG[], Chips chipsD[], int amountOfChips);
        Scenario();
        void setup();
        bool loop();
        void setSpeed(int speed);
        void setAmountOfLoops(int amountOfLoops);
        bool fadeDown();
        bool fadeUp();
        void setMode(int mode);
        Chips * getChips(int index);
        bool _end = false;



    protected:
        Chips  _chipsG[7];
        Chips  _chipsD[7];
        int _amountOfChips;
        int _speed;
        virtual bool run()=0;
        int _index;
        bool _direction = true;
        int _amountOfLoop = 10;
        int _loopCounter = 0;
        int _mode = 0;
        float _maxBrightnessRatio = 0;
        
};
#endif