#include "Scene.h"
#include "Game.h"

#ifndef AllClear_h
#define AllClear_h
extern Arduboy2 arduboy;

class AllClear : public Scene
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
