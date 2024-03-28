#ifndef ScenarioRandom_h
#define ScenarioRandom_h
#include "chips.h"
#include "scenario.h"
#include "pixel.h"

class ScenarioRandom: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();
        int _i = 1;
        int _j = 1;
    
};
#endif