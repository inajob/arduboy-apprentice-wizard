#include "Scene.h"
#include "Game.h"

#ifndef Clear_h
#define Clear_h
extern Arduboy2 arduboy;

class Clear : public Scene
{
  public:
  Game* game;
  unsigned int count = 0;
  virtual void init(){}; // WARNING: not use default init()
  void init(Game *pgame);
  virtual SceneID run();
  virtual void draw();
};

#endif
