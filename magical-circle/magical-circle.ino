#include <Arduboy2.h>

enum ShapeType {NONE, RECT, CIRCLE};

struct Position{
  byte r;
  byte theta;
};

struct Shape {
  struct Position pos;
  enum ShapeType type;
  byte size;
};

enum ShapeType mode = RECT;
const byte MAX_SHAPE=30;
struct Shape shapes[MAX_SHAPE];
byte shapeIndex = 0;
struct Position cursor = {0, 0};
byte size = 1;

Arduboy2 arduboy;

void setup(){
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void drawRect(struct Shape s){
  double rx0 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)            )/sqrt(2);
  double ry0 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)            )/sqrt(2);
  double rx1 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 1.0/2))/sqrt(2);
  double ry1 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 1.0/2))/sqrt(2);
  double rx2 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 2.0/2))/sqrt(2);
  double ry2 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 2.0/2))/sqrt(2);
  double rx3 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 3.0/2))/sqrt(2);
  double ry3 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8 + 3.0/2))/sqrt(2);

  double x0 = rx0 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double x2 = rx2 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double y2 = ry2 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double x3 = rx3 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;
  double y3 = ry3 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - 2)/8)) + 32;

  arduboy.drawLine(x0,y0, x1,y1);
  arduboy.drawLine(x1,y1, x2,y2);
  arduboy.drawLine(x2,y2, x3,y3);
  arduboy.drawLine(x3,y3, x0,y0);
}
void drawCircle(struct Shape s){
  arduboy.drawCircle(
    32 + 8*s.pos.r*cos(PI*2/8*(s.pos.theta - cursor.theta - 2)),
    32 + 8*s.pos.r*sin(PI*2/8*(s.pos.theta - cursor.theta - 2)),
    s.size * 4
  );
}
void drawShape(struct Shape s){
  switch(s.type){
    case NONE:
      break;
    case RECT:
      drawRect(s);
      break;
    case CIRCLE:
      drawCircle(s);
      break;
  }
}

void draw(){
  for(byte i = 0; i < MAX_SHAPE; i ++){
    drawShape(shapes[i]);
  }
  arduboy.setCursor(0,0);
  switch(mode){
    case RECT:  arduboy.println("RECT");break;
    case CIRCLE:arduboy.println("CIRCLE");break;
  }
}

void drawCursor(uint8_t col){
  // draw (-0.5, -0.5) - (0.5, 0.5)
  struct Shape s;
  s.type = mode;
  s.pos = cursor;
  s.size = size;
  drawShape(s);

  arduboy.drawCircle(32, 32, 2);
  arduboy.fillCircle(32, 32 - 8*cursor.r, 1);
}

byte count = 0;

void loop(){
  if(!arduboy.nextFrame()){return;}
  arduboy.pollButtons();

  if(arduboy.justPressed(A_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      // change
      switch(mode){
        case RECT: mode = CIRCLE; break;
        case CIRCLE: mode = RECT; break;
      }
    }else{
      // put shape
      struct Shape* cur = &shapes[shapeIndex];
      cur->type = mode;
      cur->pos = cursor;
      cur->size = size;
      shapeIndex ++;
    }
  }
  if(arduboy.justPressed(B_BUTTON)){
    // meta key
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      if(cursor.r == 3){
        cursor.r = 0;
      }else{
        cursor.r ++;
      }
    }else{
      if(size == 8){
        size = 1;
      }else{
        size ++;
      }
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      if(cursor.r == 0){
        cursor.r = 3;
      }else{
        cursor.r --;
      }
    }else{
      if(size == 1){
        size = 8;
      }else{
        size --;
      }
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    if(cursor.theta == 0){
      cursor.theta = 7;
    }else{
      cursor.theta --;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(cursor.theta == 7){
      cursor.theta = 0;
    }else{
      cursor.theta ++;
    }
  }
  count ++;

  arduboy.clear();
  arduboy.drawRect(0,0,128,64);
  draw();
  if(count%2 == 0){
    drawCursor(WHITE);
  }
  arduboy.display();
}
