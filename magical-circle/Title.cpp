#include "Title.h"

void Title::init(Game *pgame){
  game = pgame;
  cursor = 0;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    game->loadExample(game->stage);
    return READY;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 2){
      cursor ++;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(game->stage > 0) game->stage --;
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    game->stage ++;
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
  arduboy.print(F("ARCADE "));
  arduboy.println(game->stage + 1);
  arduboy.setCursor(8 ,18);
  arduboy.println(F("TIME ATTACK"));
  arduboy.setCursor(8 ,27);
  arduboy.println(F("PRACTICE"));

  arduboy.setCursor(0 ,9 + 9 * cursor);
  if(arduboy.everyXFrames(2)){
    arduboy.print(F(">"));
  }
}
