#include "Ready.h"

void Ready::init(){
  counter = 100;
}

SceneID Ready::run(){
  if(arduboy.justPressed(A_BUTTON)){
  }
  if(arduboy.justPressed(UP_BUTTON)){
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
  }

  counter--;
  if(counter == 0){
    counter = 100;
    return GAME;
  }
  return STAY;
}

void Ready::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.println(F("Ready?"));
  arduboy.println(counter);
}
