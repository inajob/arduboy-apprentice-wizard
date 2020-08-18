#include "ShapeType.h"
#include <avr/pgmspace.h>

const char stageTitle0[] PROGMEM = "SimpleCircle";
const char stageTitle1[] PROGMEM = "SimpleRect";
const char stageTitle2[] PROGMEM = "SunLight";
const char stageTitle3[] PROGMEM = "SimpleMagic";
const char stageTitle4[] PROGMEM = "TwinForce";
const char stageTitle5[] PROGMEM = "HolyHex";
const char stageTitle6[] PROGMEM = "LunaPower";
const char stageTitle7[] PROGMEM = "TwinElement";
const char stageTitle8[] PROGMEM = "Sharpness";
const char stageTitle9[] PROGMEM = "SunEnergy";
const char stageTitle10[] PROGMEM = "---";

const char* const stageTitles[] PROGMEM = {
  stageTitle0,
  stageTitle1,
  stageTitle2,
  stageTitle3,
  stageTitle4,
  stageTitle5,
  stageTitle6,
  stageTitle7,
  stageTitle8,
  stageTitle9,
  stageTitle10,
};


const byte stages[][10][4] PROGMEM = {
  { // simple circle
    {0,0,CIRCLE, 8},
    {0,0,CIRCLE, 7},
    {0,0,CIRCLE, 4},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // simple rect
    {0,0,CIRCLE, 8},
    {0,0,CIRCLE, 7},
    {0,0,RECT, 4},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // sun
    {0,0,RECT, 6},
    {0,1,RECT, 6},
    {0,0,CIRCLE, 4},
    {0,0,CIRCLE, 5},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // simple magic
    {0,0,RECT, 5},
    {0,1,RECT, 5},
    {0,0,CIRCLE, 7},
    {0,0,CIRCLE, 8},
    {0,0,CIRCLE, 1},
    {0,0,CIRCLE, 2},
    {0,0,CIRCLE, 3},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // twin force
    {0,0,CIRCLE, 8},
    {0,0,CIRCLE, 7},
    {2,0,CIRCLE, 3},
    {2,4,CIRCLE, 3},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // holy hex
    {0,0,CIRCLE, 8},
    {0,0,CIRCLE, 7},
    {0,0,UTRI, 6},
    {0,0,DTRI, 6},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // luna power
    {0,0,CIRCLE, 8},
    {1,0,CIRCLE, 6},
    {1,0,CIRCLE, 5},
    {1,0,UTRI, 4},
    {1,0,DTRI, 4},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
    {0,0,NONE, 0},
  },
  { // twin element
    {0,0,CIRCLE, 8},
    {2,0,CIRCLE, 4},
    {2,0,CIRCLE, 3},
    {2,0,RECT, 2},
    {2,4,CIRCLE, 4},
    {2,4,UTRI, 3},
    {2,4,DTRI, 3},
    {3,2,DTRI, 2},
    {3,6,DTRI, 2},
    {0,0,NONE, 0},
  },
  { // sharpness
    {0,0,RECT, 6},
    {2,0,RECT, 2},
    {2,2,RECT, 2},
    {2,4,RECT, 2},
    {2,6,RECT, 2},
    {3,1,UTRI, 1},
    {3,3,UTRI, 1},
    {3,5,UTRI, 1},
    {3,7,UTRI, 1},
    {0,0,NONE, 0},
  },
  { // sun energy
    {0,0,CIRCLE, 1},
    {0,0,CIRCLE, 5},
    {3,0,VLINE, 1},
    {3,1,VLINE, 1},
    {3,2,VLINE, 1},
    {3,3,VLINE, 1},
    {3,4,VLINE, 1},
    {3,5,VLINE, 1},
    {3,6,VLINE, 1},
    {3,7,VLINE, 1},
  },


};

