#include "Title.h"
#include "misaki_font.h"
#include "ArduboyTones.h"

extern ArduboyTones sound;

void Title::init(Game *pgame){
  game = pgame;
  game->loadExample(random(game->MAX_STAGE));
  cursor = 0;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    game->anim = 0;
    switch(cursor){
      case 0:
        game->loadExample(game->stage);
        game->isPractice = false;
        game->isTimeAttack = false;
        sound.tone(880, 100);
        return READY;
        break;
      case 1:
        game->loadExample(game->stage);
        game->isPractice = false;
        game->isTimeAttack = true;
        sound.tone(880, 100);
        return GAME;
        break;
      case 2:
        game->isPractice = true;
        sound.tone(880, 100);
        return GAME;
        break;
      case 3:
        game->isJP = !game->isJP;
        sound.tone(880, 100);
        break;
    }
    return STAY;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
      sound.tone(440, 50);
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 3){
      cursor ++;
      sound.tone(440, 50);
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    //if(game->stage > 0) game->stage --;
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    /*
    game->stage ++;
    if(game->stage == game->MAX_STAGE){
      game->stage--;
    }
    */
  }
  game->anim += 0.1;
  return STAY;
}

PROGMEM const uint8_t jpTitle[] = { 0xf0, 0x81,0x6c,0x8b,0x46, 0xf1, 0x00, 0xf0, 0x80,0x7d,0x48,0x66,0x4d,0x46};
PROGMEM const uint8_t jpArcade[] = { 0xf0, 0x97,0xee,0xa6,0xee,0xbe};
PROGMEM const uint8_t jpTimeAttack[] = { 0xf0, 0xb4,0x99,0xd5,0x97,0xb4,0xb8,0xa4};
PROGMEM const uint8_t jpPractice[] = { 0xf0, 0x8e,0x95,0x59,0x87,0x48};
PROGMEM const uint8_t jpLanguage[] = { 0xf0, 0x54,0x95,0x56};

void Title::draw(){
  arduboy.clear();

  for(byte i = 0; i < game->MAX_SHAPE; i ++){
    game->drawShape(game->exampleShapes[i], 64-1, 0);
  }

  if(game->isJP){
    arduboy.setCursor(0,0);
    drawText(0,0,jpTitle,sizeof(jpTitle));
    arduboy.drawLine(0,9,100,9);

    arduboy.setCursor(48,9 + 9 * 5);
    arduboy.print(F("by @ina_ani"));

    arduboy.setCursor(8 ,9*2);
    drawText(8, 9*2, jpArcade, sizeof(jpArcade));
    arduboy.setCursor(50,9*2);
    //arduboy.println(game->stage + 1);
    arduboy.setCursor(8 ,9*3);
    drawText(8, 9*3, jpTimeAttack, sizeof(jpTimeAttack));
    arduboy.setCursor(8 ,9*4);
    drawText(8, 9*4, jpPractice, sizeof(jpPractice));
    arduboy.setCursor(8 ,9*5);
    drawText(8, 9*5, jpLanguage, sizeof(jpLanguage));
    arduboy.setCursor(40, 9*5);
    if(game->isJP){arduboy.println("JP");}else{arduboy.println("EN");}
  }else{
    arduboy.setCursor(0,0);
    arduboy.print(F("\x0f APPRENTICE WIZARD \x0f"));

    arduboy.setCursor(48,9 + 9 * 5);
    arduboy.print(F("by @ina_ani"));

    arduboy.setCursor(8 ,9*2);
    arduboy.print(F("Arcade "));
    //arduboy.println(game->stage + 1);
    arduboy.setCursor(8 ,9*3);
    arduboy.println(F("Time Attack"));
    arduboy.setCursor(8 ,9*4);
    arduboy.println(F("Practice"));
    arduboy.setCursor(8 ,9*5);
    arduboy.print(F("Language: "));
    if(game->isJP){arduboy.println("JP");}else{arduboy.println("EN");}
  }


  arduboy.setCursor(0 ,18 + 9 * cursor);
  if(arduboy.everyXFrames(2)){
    arduboy.print(F("\xdb"));
  }
}
