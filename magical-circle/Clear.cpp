#include "Clear.h"

void Clear::init(Game *pgame){
  game = pgame
}

SceneID Clear::run(){
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

  return STAY;
}

void Clear::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.println(F("CLEAR"));
}
