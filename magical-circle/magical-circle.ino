#include <Arduboy2.h>
#include "Game.h"
#include "Title.h"
#include "Ready.h"
#include "Clear.h"

Scene* scene;

Title title;
Ready ready;
Game game;
Clear clear;
Arduboy2 arduboy;

void setup(){
  arduboy.begin();
  arduboy.setFrameRate(30);

  title.init();
  ready.init();
  game.init();
  clear.init(&game);
  scene = &title;

}


void loop(){
  if(!arduboy.nextFrame()){return;}
  arduboy.pollButtons();

  SceneID nextSceneID = scene->run();
  scene->draw();

  switch(nextSceneID){
    case STAY:
      break;
    case TITLE:
      scene = &title;
      break;
    case READY:
      scene = &ready;
      break;
    case GAME:
      scene = &game;
      break;
    case CLEAR:
      scene = &clear;
      break;
  }
  /*
  */
  arduboy.display();
}
