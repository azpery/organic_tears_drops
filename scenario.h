#ifndef Scenario_h
#define Scenario_h
#include "chips.h"

class Scenario
{
    public:
        Scenario(Chips chips[], Chips chipsG[], Chips chipsD[], int amountOfChips);
        Scenario();
        void setup();
        bool loop();
        void setSpeed(int speed);
        void setAmountOfLoops(int amountOfLoops);


    protected:
        Chips  _chipsG[7];
        Chips  _chipsD[7];
        Chips  _chips[14];
        int _amountOfChips;
        int _speed;
        virtual bool run()=0;
        int _index;
        bool _direction = true;
        int _amountOfLoop = 10;
        int _loopCounter = 0;
        int _mode = 0;
        
};
#endif