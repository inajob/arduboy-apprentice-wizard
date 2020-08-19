#include <Arduboy2.h>
#include "Game.h"
#include "Title.h"
#include "Ready.h"
#include "Clear.h"
#include "misaki_font.h"

Scene* scene;

Title title;
Ready ready;
Game game;
Clear clear;
Arduboy2 arduboy;

void setup(){
  arduboy.begin();
  arduboy.setFrameRate(30);

  game.init();
  title.init(&game);
  ready.init(&game);
  clear.init(&game);
  scene = &title;

}
void drawText(uint8_t x, uint8_t y, const uint8_t *mes, uint8_t cnt)
{
  uint8_t pb;
  uint8_t page;
  uint8_t screen_start = 0;
  uint8_t screen_end = 128;

  if (x < screen_start) {
    x = screen_start;
  }
  
  for (uint8_t i = 0; i < cnt; i++) {
    pb = pgm_read_byte_near(mes + i);

    switch (pb) {
      case MISAKI_FONT_F0_PAGE:
        page = MISAKI_FONT_F0_PAGE;
        continue;
      case MISAKI_FONT_F1_PAGE:
        page = MISAKI_FONT_F1_PAGE;
        continue;
      case MISAKI_FONT_F2_PAGE:
        page = MISAKI_FONT_F2_PAGE;
        continue;
    }

    if (!page) {
      continue;
    }

    switch (page) {
      #ifdef MISAKI_FONT_F0_H
        case MISAKI_FONT_F0_PAGE:
          if (pb > MISAKI_FONT_F0_SIZE) {
            continue;
          }      
          if ((x + 8) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f0[ pb ], MISAKI_FONT_F0_W, 8, WHITE);
          x = x + 8;    
          break;
      #endif
      #ifdef MISAKI_FONT_F1_H
        case MISAKI_FONT_F1_PAGE:
          if (pb > MISAKI_FONT_F1_SIZE) {
            continue;
          }      
          if ((x + 4) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f1[ pb ], MISAKI_FONT_F1_W, 8, WHITE);
          arduboy.drawBitmap(x + 3, y, misaki_font_0x00, 1, 8, WHITE);
          x = x + 4;  
          break;
      #endif
      #ifdef MISAKI_FONT_F2_H
        case MISAKI_FONT_F2_PAGE:
          if (pb > MISAKI_FONT_F2_SIZE) {
            continue;
          }      
          if ((x + 8) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f2[ pb ], MISAKI_FONT_F2_W, 8, WHITE);
          arduboy.drawBitmap(x + 7, y, misaki_font_0x00, 1, 8, WHITE);
          x = x + 8;    
          break;
      #endif
    }
  }
}

void loop(){
  if(!arduboy.nextFrame()){return;}
  arduboy.pollButtons();

  SceneID nextSceneID = scene->run();
  scene->draw();

  switch(nextSceneID){
    case STAY:
      arduboy.display();
      break;
    case TITLE:
      title.init(&game);
      scene = &title;
      break;
    case READY:
      ready.stage = game.stage; // TODO
      scene = &ready;
      break;
    case GAME:
      scene = &game;
      break;
    case CLEAR:
      scene = &clear;
      break;
  }
}
