#include "ShapeType.h"
#include <avr/pgmspace.h>

const char stageTitle0[] PROGMEM = "SimpleCircle";
const char stageTitle1[] PROGMEM = "SimpleRect";
const char stageTitle2[] PROGMEM = "Sun";
const char stageTitle3[] PROGMEM = "SimpleMagic";
const char stageTitle4[] PROGMEM = "TwinForce";
const char stageTitle5[] PROGMEM = "---";

const char* const stageTitles[] PROGMEM = {
  stageTitle0,
  stageTitle1,
  stageTitle2,
  stageTitle3,
  stageTitle4,
  stageTitle5,
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
  }
};

