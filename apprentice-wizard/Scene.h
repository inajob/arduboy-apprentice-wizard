#include <Arduboy2.h>

#ifndef Scene_h
#define Scene_h

enum SceneID {
STAY,
TITLE,
READY,
GAME,
CLEAR,
ALLCLEAR
};

class Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
