#include "Scene.h"
#include "Game.h"

#ifndef Title_h
#define Title_h
extern Arduboy2 arduboy;

class Title : public Scene
{
  byte cursor;
  public:
  Game* game;
  virtual void init(){} // WARNING: not use default init()
  void init(Game *pgame);
  virtual SceneID run();
  virtual void draw();
};

#endif
