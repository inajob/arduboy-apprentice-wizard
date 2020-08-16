#include "Scene.h"

#ifndef Title_h
#define Title_h
extern Arduboy2 arduboy;

class Title : public Scene
{
  byte cursor;
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
