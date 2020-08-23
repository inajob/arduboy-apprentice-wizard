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
  static const byte MAX_SHAPE=32;
  static const byte MAX_STAGE=16;
  struct Shape shapes[MAX_SHAPE];
  struct Shape exampleShapes[MAX_SHAPE];
  enum ShapeType mode = CIRCLE;
  byte shapeIndex = 0;
  struct Position cursor = {0, 0};
  byte size = 1;
  double anim = 0;
  double scale = 1;
  byte count;
  byte stage = 0;
  bool showCursor = true;
  bool showShapeSelector = false;
  byte shapeSelectorTimer = 0;
  bool isPractice = false;
  bool isJP = false;
  uint16_t timer = 0;
  bool isTimeAttack = false;

  void loadExample(byte n);
  bool equalShape(struct Shape s1, struct Shape s2);
  void clear();
  bool check();
  void drawRect(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawUtri(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawDtri(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawVLine(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawCircle(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawShape(struct Shape s, int8_t ox = 0, int8_t oy = 0);
  void drawShapeSelector();
  void gameDraw();
  void drawCursor(uint8_t col);

  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
