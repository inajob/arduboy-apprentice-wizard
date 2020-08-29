#include "AllClear.h"
#include "misaki_font.h"

void AllClear::init(Game *pgame){
  count = 0;
  game = pgame;
}

SceneID AllClear::run(){
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
  count ++;
  return STAY;
}
PROGMEM const uint8_t jpThanks[] = { 0xf0, 0x44,0x5f,0x95,0x69,0x51,0x8e,0x68,0x44,0x8c,0x4e,0x6a,0x48,0x09,0x09, };
void AllClear::draw(){
  arduboy.clear();
  if(game->isJP){
    arduboy.setCursor(0,0);
    arduboy.println(F("ALL CLEAR"));
    if(game->isTimeAttack){
      arduboy.print("Time: ");
      arduboy.println(game->timer);
    }else{
      arduboy.println();
    }
    drawText(0, 8*3, jpThanks, sizeof(jpThanks));
    arduboy.println();
    arduboy.println();
    arduboy.println();
    arduboy.println(F("    APPRENTICE WIZARD"));
    arduboy.println(F("              Ver 1.2"));
    arduboy.println(F("          by @ina_ani"));
  }else{
    arduboy.setCursor(0,0);
    arduboy.println(F("ALL CLEAR"));
    if(game->isTimeAttack){
      arduboy.print("Time: ");
      arduboy.println(game->timer);
    }else{
      arduboy.println();
    }
    arduboy.println(F("THANK YOU FOR"));
    arduboy.println(F("        YOUR PLAY!!"));
    arduboy.println();
    arduboy.println(F("    APPRENTICE WIZARD"));
    arduboy.println(F("              Ver 1.2"));
    arduboy.println(F("          by @ina_ani"));
  }
}
