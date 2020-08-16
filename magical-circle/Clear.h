#include "Scene.h"

#ifndef Clear_h
#define Clear_h
extern Arduboy2 arduboy;

class Game;

class Clear : public Scene
{
  public:
  Game* game;
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
