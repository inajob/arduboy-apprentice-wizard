#include "Ready.h"
#include "stage.h"

void Ready::init(){
  counter = 100;
}

SceneID Ready::run(){
  if(arduboy.justPressed(A_BUTTON)){
    return GAME;
  }
  if(arduboy.justPressed(UP_BUTTON)){
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
  }

  //counter--;
  //if(counter == 0){
  //  counter = 100;
  //  return GAME;
  //}
  return STAY;
}

void Ready::draw(){
  char buf[32];

  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("STAGE"));
  arduboy.print(stage + 1);
  arduboy.print(':');
  strcpy_P(buf, (char*)pgm_read_word(&stageTitles[stage]));
  arduboy.println(buf);
  //arduboy.println(counter);

  arduboy.setCursor(0,16);
  switch(stage){
    case 0:
      arduboy.println(F(" --INSTRUCTION1--"));
      arduboy.println(F("  \x18   :BIGGER"));
      arduboy.println(F("  \x19   :SMALLER"));
      arduboy.println(F("  A   :DRAW SHAPE"));
      arduboy.println(F("  B+A :RESET"));
      arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
      break;
    case 1:
      arduboy.println(F(" --INSTRUCTION2--"));
      arduboy.println(F("  \x1B,\x1A :CHANGE SHAPE"));
      arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
      break;
    case 2:
    case 3:
      arduboy.println(F(" --INSTRUCTION3--"));
      arduboy.println(F("  B+\x1B,\x1A :ROTATE"));
      arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
      break;
    case 4:
      arduboy.println(F(" --INSTRUCTION4--"));
      arduboy.println(F("  B+\x18 :MOVE UP"));
      arduboy.println(F("  B+\x19 :MOVE DOWN"));
      arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
      break;

  }
}
