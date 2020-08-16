#include "Title.h"

void Title::init(){
  cursor = 0;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    return READY;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 0){
      cursor ++;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
  }
  return STAY;
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("APPRENTICE WIZARD"));

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("BY @ina_ani"));

  arduboy.setCursor(8 ,9);
  arduboy.print(F("ARCADE"));

  arduboy.setCursor(0 ,9 + 9 * cursor);
  if(arduboy.everyXFrames(2)){
    arduboy.print(F(">"));
  }
}
