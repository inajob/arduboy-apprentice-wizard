#include "Scene.h"
#include "Game.h"

#ifndef Ready_h
#define Ready_h
extern Arduboy2 arduboy;

class Ready : public Scene
{
  public:
  uint8_t counter;
  uint8_t stage;
  Game* game;
  void init(Game *pgame);
  virtual void init(){}; // WARNING: not use default init()
  virtual SceneID run();
  virtual void draw();
};

#endif
