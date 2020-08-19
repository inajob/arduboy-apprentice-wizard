#include "Title.h"

void Title::init(Game *pgame){
  game = pgame;
  game->loadExample(random(10));
  cursor = 0;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    game->loadExample(game->stage);
    game->anim = 0;
    switch(cursor){
      case 0:
        game->isPractice = false;
        return GAME;
        break;
      case 1:
        // not implement
        break;
      case 2:
        game->isPractice = true;
        return GAME;
        break;
      case 3:
        game->isJP = !game->isJP;
        break;
    }
    return STAY;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 3){
      cursor ++;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(game->stage > 0) game->stage --;
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    game->stage ++;
  }
  game->anim += 0.1;
  return STAY;
}

void Title::draw(){
  arduboy.clear();

  for(byte i = 0; i < game->MAX_SHAPE; i ++){
    game->drawShape(game->exampleShapes[i], 64-1, 0);
  }

  arduboy.setCursor(0,0);
  arduboy.print(F("\x0f APPRENTICE WIZARD \x0f"));

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("by @ina_ani"));

  arduboy.setCursor(8 ,9*2);
  arduboy.print(F("Arcade "));
  arduboy.println(game->stage + 1);
  arduboy.setCursor(8 ,9*3);
  arduboy.println(F("Time Attack"));
  arduboy.setCursor(8 ,9*4);
  arduboy.println(F("Practice"));
  arduboy.setCursor(8 ,9*5);
  arduboy.print(F("Language: "));
  if(game->isJP){arduboy.println("JP");}else{arduboy.println("EN");}


  arduboy.setCursor(0 ,18 + 9 * cursor);
  if(arduboy.everyXFrames(2)){
    arduboy.print(F("\xdb"));
  }
}
