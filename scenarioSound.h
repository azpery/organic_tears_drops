#ifndef ScenarioSound_h
#define ScenarioSound_h
#include "chips.h"
#include "scenario.h"
#include "pixel.h"

class ScenarioSound: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();
    
    private:
        // int _amountOfPixels = 1;
        // Pixel _pixels[1];
        // int _i = 0;
    
};
#endif