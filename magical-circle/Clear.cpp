#include "Clear.h"

void Clear::init(Game *pgame){
  game = pgame;
  count = 0;
}

SceneID Clear::run(){
  if(arduboy.justPressed(A_BUTTON)){
    game->anim = 0;
    game->clear();
    game->stage ++;
    game->loadExample(game->stage);
    count = 0;
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
  count ++;
  double p = 1.0*count/50;
  if(p > 0.5){
    p = 0.5;
  }
  game->anim += p;
  return STAY;
}

void Clear::draw(){
  arduboy.clear();
  game->draw();
  arduboy.setCursor(0,0);
  arduboy.println(F("CLEAR"));
}
