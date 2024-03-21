#ifndef ScenarioWave_h
#define ScenarioWave_h
#include "chips.h"
#include "scenario.h"

class ScenarioWave: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();
    
    
};
#endif