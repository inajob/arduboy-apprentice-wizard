#include "ShapeType.h"
#include <avr/pgmspace.h>

#ifndef stage_h
#define stage_h

const byte dataSimpleCircle[] PROGMEM = {
  0,0,CIRCLE, 8,
  0,0,CIRCLE, 7,
  0,0,CIRCLE, 4,
  0,0,  NONE, 0,
};
const byte dataSimpleRect[] PROGMEM = {
  0,0,CIRCLE, 8,
  0,0,CIRCLE, 7,
  0,0,  RECT, 4,
  0,0,  NONE, 0,
};
const byte dataSun[] PROGMEM = {
  0,0,RECT, 6,
  0,1,RECT, 6,
  0,0,CIRCLE, 4,
  0,0,CIRCLE, 5,
  0,0,NONE, 0,
};
const byte dataSimpleMagic[] PROGMEM = {
0,0,RECT, 5,
0,1,RECT, 5,
0,0,CIRCLE, 7,
0,0,CIRCLE, 8,
0,0,CIRCLE, 1,
0,0,CIRCLE, 2,
0,0,CIRCLE, 3,
0,0,NONE, 0,
};
const byte dataTwinForce[] PROGMEM = {
0,0,CIRCLE, 8,
0,0,CIRCLE, 7,
2,0,CIRCLE, 3,
2,4,CIRCLE, 3,
0,0,NONE, 0,
};
const byte dataHolyHex[] PROGMEM = {
0,0,CIRCLE, 8,
0,0,CIRCLE, 7,
0,0,UTRI, 6,
0,0,DTRI, 6,
0,0,NONE, 0,
};
const byte dataLunaPower[] PROGMEM = {
0,0,CIRCLE, 8,
1,0,CIRCLE, 6,
1,0,CIRCLE, 5,
1,0,UTRI, 4,
1,0,DTRI, 4,
0,0,NONE, 0,
};
const byte dataTwinElement[] PROGMEM = {
0,0,CIRCLE, 8,
2,0,CIRCLE, 4,
2,0,CIRCLE, 3,
2,0,RECT, 2,
2,4,CIRCLE, 4,
2,4,UTRI, 3,
2,4,DTRI, 3,
3,2,DTRI, 2,
3,6,DTRI, 2,
0,0,NONE, 0,
};
const byte dataSharpness[] PROGMEM = {
0,0,RECT, 6,
2,0,RECT, 2,
2,2,RECT, 2,
2,4,RECT, 2,
2,6,RECT, 2,
3,1,UTRI, 1,
3,3,UTRI, 1,
3,5,UTRI, 1,
3,7,UTRI, 1,
0,0,NONE, 0,
};
const byte dataSunEnergy[] PROGMEM = {
0,0,CIRCLE, 1,
0,0,CIRCLE, 5,
3,0,VLINE, 1,
3,1,VLINE, 1,
3,2,VLINE, 1,
3,3,VLINE, 1,
3,4,VLINE, 1,
3,5,VLINE, 1,
3,6,VLINE, 1,
3,7,VLINE, 1,
0,0,NONE, 0,
};

byte* stages[] = {
  dataSimpleCircle,
  dataSimpleRect,
  dataSun,
  dataSimpleMagic,
  dataTwinForce,
  dataHolyHex,
  dataLunaPower,
  dataTwinElement,
  dataSharpness,
  dataSunEnergy,
};

#endif
