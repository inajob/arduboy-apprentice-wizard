#include "Scene.h"
#include "ShapeType.h"

#ifndef Game_h
#define Game_h
extern Arduboy2 arduboy;


struct Position{
  byte r;
  byte theta;
};

struct Shape {
  struct Position pos;
  enum ShapeType type;
  byte size;
};

class Game : public Scene
{
  public:
  const byte MAX_SHAPE=10;
  struct Shape shapes[MAX_SHAPE];
  struct Shape exampleShapes[MAX_SHAPE];

  virtual bool equalShape(struct Shape s1, struct Shape s2);
  virtual void clear();
  virtual bool check();
  virtual void drawRect(struct Shape s, byte ox = 0, byte oy = 0);
  virtual void drawCircle(struct Shape s, byte ox = 0, byte oy = 0);
  virtual void drawShape(struct Shape s, byte ox = 0, byte oy = 0);
  virtual void gameDraw();
  virtual void drawCursor(uint8_t col);
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
