#ifndef ScenarioHeartBeat_h
#define ScenarioHeartBeat_h
#include "chips.h"
#include "scenario.h"

class ScenarioHeartBeat: public Scenario
{        
    using Scenario::Scenario;
    public:
        bool run();
        void setup();
    
    private:
        int _index = 0;
        bool fadeUpAndDown(int index);
    
};
#endif