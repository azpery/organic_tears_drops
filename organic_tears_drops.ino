#include <FastLED.h>
#include "chips.h"
#include "scenario.h"
#include "scenarioRainbow.h"
#include "scenarioWave.h"
#include "scenarioStart.h"
#include "scenarioWaveColors.h"
#include "scenarioHeartBeat.h"
#include "scenarioPixel.h"
#include "scenarioRandom.h"
#include "scenarioSound.h"

// Define the array of leds
#define AMOUNT_OF_CHIPS 7
CRGB leds1G[70];
CRGB leds2G[80];
CRGB leds3G[80];
CRGB leds4G[80];
CRGB leds5G[90];
CRGB leds6G[100];
CRGB leds7G[110];

CRGB leds1D[70];
CRGB leds2D[80];
CRGB leds3D[80];
CRGB leds4D[80];
CRGB leds5D[90];
CRGB leds6D[100];
CRGB leds7D[110];

Chips chips1G(70, leds1G, true, 7);
Chips chips2G(80, leds2G, true, 8);
Chips chips3G(80, leds3G, true, 9);
Chips chips4G(80, leds4G, true, 10);
Chips chips5G(90, leds5G, true, 11);
Chips chips6G(100, leds6G, true, 12);
Chips chips7G(110, leds7G, true, 13);

Chips chips1D(70, leds1D, true, 0);
Chips chips2D(80, leds2D, true, 1);
Chips chips3D(80, leds3D, true, 2);
Chips chips4D(80, leds4D, true, 3);
Chips chips5D(90, leds5D, true, 4);
Chips chips6D(100, leds6D, true, 5);
Chips chips7D(110, leds7D, true, 6);

Chips chips[AMOUNT_OF_CHIPS * 2] = {chips7G, chips6G, chips5G, chips4G, chips3G, chips2G, chips1G, chips1D, chips2D, chips3D, chips4D, chips5D, chips6D, chips7D};
Chips chipsG[AMOUNT_OF_CHIPS] = {chips1G, chips2G, chips3G, chips4G, chips5G, chips6G, chips7G};
Chips chipsD[AMOUNT_OF_CHIPS] = {chips1D, chips2D, chips3D, chips4D, chips5D, chips6D, chips7D};

ScenarioRainbow scenarioRainbow(chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioWave scenarioWave(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioStart scenarioStart(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioWaveColors scenarioWaveColors0(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);
ScenarioWaveColors scenarioWaveColors1(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);
ScenarioWaveColors scenarioWaveColors2(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);
ScenarioWaveColors scenarioWaveColors3(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioHeartBeat scenarioHeartBeat(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioPixel scenarioPixel(chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioRandom scenarioRandom(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

ScenarioSound scenarioSound(chips, chipsG, chipsD, AMOUNT_OF_CHIPS);

// Scenario scenarioBase;

int iteration = 8;

void setup()
{
  FastLED.addLeds<NEOPIXEL, 0>(leds1D, chips1D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 1>(leds2D, chips2D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 2>(leds3D, chips3D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 3>(leds4D, chips4D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 4>(leds5D, chips5D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 5>(leds6D, chips6D.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 6>(leds7D, chips7D.getNumOfLeds()); // GRB ordering is assumed

  FastLED.addLeds<NEOPIXEL, 7>(leds1G, chips1G.getNumOfLeds());  // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 8>(leds2G, chips2G.getNumOfLeds());  // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 9>(leds3G, chips3G.getNumOfLeds());  // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 10>(leds4G, chips4G.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 11>(leds5G, chips5G.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 12>(leds6G, chips6G.getNumOfLeds()); // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, 13>(leds7G, chips7G.getNumOfLeds()); // GRB ordering is assumed
  // FastLED.show();
  scenarioRainbow.setup();
  scenarioWave.setup();
  scenarioStart.setup();
  scenarioWaveColors0.setMode(0);
  scenarioWaveColors0.setup();
  scenarioWaveColors1.setMode(1);
  scenarioWaveColors1.setup();
  scenarioWaveColors2.setMode(2);
  scenarioWaveColors2.setup();
  scenarioWaveColors3.setMode(3);
  scenarioWaveColors3.setup();
  scenarioHeartBeat.setup();
  scenarioRandom.setup();
  scenarioPixel.setup();
  scenarioSound.setup();
}

int counter = 0;
int counters[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop()
{
  bool end = false;
  if (counter == 0)
  {
    end = scenarioStart.loop();
  }

  if (counter == 1)
  {
    end = scenarioWave.loop();
  }

  if (counter == 2)
  {
    end = scenarioWaveColors0.loop();
  }
  if (counter == 3)
  {
    end = scenarioWaveColors2.loop();
  }
  if (counter == 4)
  {
    end = scenarioWaveColors3.loop();
  }
  if (counter == 5)
  {
    end = scenarioRainbow.loop();
  }
  if (counter == 6)
  {
    end = scenarioHeartBeat.loop();
  }
  if (counter == 7)
  {
    end = scenarioPixel.loop();
  }
  if (counter == 8)
  {
    end = scenarioRandom.loop();
  }
  if (counter == 9)
  {
    end = scenarioSound.loop();
  }
  if (end)
  {
    counter = random(0, 10);

    // for (int i = 0; i < 10; i++)
    // {
    //   if (counters[i] < counters[counter])
    //   {
    //     counter = i;
    //     counters[i]++;
    //     break;
    //   }
    // }
  }

  FastLED.show();
  iteration++;
  if (iteration > 2000)
  {
    iteration = 0;
  }
}
