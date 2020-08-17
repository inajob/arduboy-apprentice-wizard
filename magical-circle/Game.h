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
  static const byte MAX_SHAPE=10;
  struct Shape shapes[MAX_SHAPE];
  struct Shape exampleShapes[MAX_SHAPE];
  enum ShapeType mode = CIRCLE;
  byte shapeIndex = 0;
  struct Position cursor = {0, 0};
  byte size = 1;
  double anim = 0;
  double scale = 1;
  byte stage = 0;
  bool showCursor = true;

  virtual void loadExample(byte n);
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
