#ifndef ScenarioWaveColors_h
#define ScenarioWaveColors_h
#include "chips.h"
#include "scenario.h"

class ScenarioWaveColors: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();
    
    
};
#endif