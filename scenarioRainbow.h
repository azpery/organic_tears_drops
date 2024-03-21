#ifndef ScenarioRainbow_h
#define ScenarioRainbow_h
#include "chips.h"
#include "scenario.h"

class ScenarioRainbow: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();

};
#endif