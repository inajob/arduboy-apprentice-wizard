#include "Clear.h"

void Clear::init(Game *pgame){
  game = pgame;
  count = 0;
}

SceneID Clear::run(){
  if(arduboy.justPressed(A_BUTTON)){
    game->anim = 0;
    game->scale = 1;
    game->clear();
    game->stage ++;
    if(game->stage == game->MAX_STAGE){
      return ALLCLEAR;
    }
    game->loadExample(game->stage);
    game->showCursor = true;
    count = 0;
    return READY;
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
  double p = 1.0*count/200;
  if(p > 0.2){
    p = 0.2;
  }
  game->anim += p;
  game->scale = 0.5*sin(PI/16*count) + 0.8;
  game->showCursor = false;
  return STAY;
}

void Clear::draw(){
  arduboy.clear();
  game->draw();
  arduboy.setCursor(0,0);
  arduboy.println(F("CLEAR"));
}
