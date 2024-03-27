#ifndef ScenarioPixel_h
#define ScenarioPixel_h
#include "chips.h"
#include "scenario.h"
#include "pixel.h"

class ScenarioPixel: public Scenario
{        
    using Scenario::Scenario;
    public:
        ScenarioPixel(Chips chips[], Chips chipsG[], Chips chipsD[], int amountOfChips);
        bool run();
        void setup();
    
    private:
        int _amountOfPixels = 1;
        Pixel _pixels[20];
        int _i = 0;
    
};
#endif