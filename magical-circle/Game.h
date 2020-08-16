#include "Scene.h"

#ifndef Game_h
#define Game_h
extern Arduboy2 arduboy;

class Game : public Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
