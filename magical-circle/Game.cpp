#include "Game.h"
#include "stage.h"

void Game::loadExample(byte n){
  cursor.r = 0;
  cursor.theta = 0;
  size = 4;
  for(byte i = 0; i < MAX_SHAPE; i ++){
    struct Shape s;
    s.pos.r = pgm_read_byte_near(&stages[n][i][0]);
    s.pos.theta = pgm_read_byte_near(&stages[n][i][1]);
    s.type = pgm_read_byte_near(&stages[n][i][2]);
    s.size = pgm_read_byte_near(&stages[n][i][3]);
    exampleShapes[i] = s;
  }
}

bool Game::equalShape(struct Shape s1, struct Shape s2){
  if(s1.type != s2.type){return false;}
  switch(s1.type){
    case NONE:
      return true;
    case RECT:
      if(s1.pos.r == 0 && s1.pos.r == s2.pos.r){
        return (s1.size == s2.size) &&
          (s1.pos.theta%2 == s2.pos.theta%2);
      }
      return s1.pos.r == s2.pos.r &&
             s1.pos.theta == s2.pos.theta &&
             s1.size == s2.size;

    case CIRCLE:
      if(s1.pos.r == 0 && s1.pos.r == s2.pos.r){
        return s1.size == s2.size;
      }
      return s1.pos.r == s2.pos.r &&
        s1.pos.theta == s2.pos.theta &&
        s1.size == s2.size;
  }
  return false;
}

void Game::clear(){
  for(byte i = 0; i < MAX_SHAPE; i ++){
    shapes[i].type = NONE;
  }
  shapeIndex = 0;
}

bool Game::check(){
  bool flag;
  for(byte i = 0; i < MAX_SHAPE; i ++){
    flag = false;
    for(byte j = 0; j < MAX_SHAPE; j ++){
      if(equalShape(exampleShapes[i], shapes[j])){
        flag = true;
        break;
      }
    }
    if(flag == false){return false;}
  }
  for(byte i = 0; i < MAX_SHAPE; i ++){
    flag = false;
    for(byte j = 0; j < MAX_SHAPE; j ++){
      if(equalShape(exampleShapes[j], shapes[i])){
        flag = true;
        break;
      }
    }
    if(flag == false){return false;}
  }
  return true;
}

void Game::drawRect(struct Shape s, byte ox, byte oy){
  double rx0 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)            )/sqrt(2);
  double ry0 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)            )/sqrt(2);
  double rx1 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 1.0/2))/sqrt(2);
  double ry1 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 1.0/2))/sqrt(2);
  double rx2 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/2))/sqrt(2);
  double ry2 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/2))/sqrt(2);
  double rx3 = (7.0*s.size) * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 3.0/2))/sqrt(2);
  double ry3 = (7.0*s.size) * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 3.0/2))/sqrt(2);

  double x0 = rx0 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x2 = rx2 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y2 = ry2 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x3 = rx3 + 8*s.pos.r * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y3 = ry3 + 8*s.pos.r * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;

  arduboy.drawLine(ox + x0, oy + y0, ox + x1, oy + y1);
  arduboy.drawLine(ox + x1, oy + y1, ox + x2, oy + y2);
  arduboy.drawLine(ox + x2, oy + y2, ox + x3, oy + y3);
  arduboy.drawLine(ox + x3, oy + y3, ox + x0, oy + y0);
}
void Game::drawCircle(struct Shape s, byte ox, byte oy){
  arduboy.drawCircle(
    32 + 8*s.pos.r*cos(PI*2/8*(s.pos.theta - cursor.theta - anim - 2)) + ox,
    32 + 8*s.pos.r*sin(PI*2/8*(s.pos.theta - cursor.theta - anim - 2)) + oy,
    s.size * 4
  );
}
void Game::drawShape(struct Shape s, byte ox, byte oy){
  switch(s.type){
    case NONE:
      break;
    case RECT:
      drawRect(s, ox, oy);
      break;
    case CIRCLE:
      drawCircle(s, ox, oy);
      break;
  }
}

void Game::gameDraw(){
  for(byte i = 0; i < MAX_SHAPE; i ++){
    drawShape(shapes[i]);
    drawShape(exampleShapes[i], 64, 0);
  }
  arduboy.setCursor(0,0);
}

void Game::drawCursor(uint8_t col){
  // draw (-0.5, -0.5) - (0.5, 0.5)
  struct Shape s;
  s.type = mode;
  s.pos = cursor;
  s.size = size;
  double preAnim = anim;
  anim = 0;
  drawShape(s);
  anim = preAnim;

  arduboy.drawCircle(32, 32, 2);
  arduboy.drawLine(32, 32,
    32 + 8*cos(PI*2.0*(-cursor.theta-anim-2)/8),
    32 + 8*sin(PI*2.0*(-cursor.theta-anim-2)/8));
  arduboy.fillCircle(32, 32 - 8*cursor.r, 1);
}

byte count = 0;

void Game::init(){
  loadExample(0);
}

SceneID Game::run(){
  if(abs(anim) > 0.01){
    anim = (abs(anim) - 0.1)*(anim/abs(anim));
  }

  if(check()){
    clear();
    stage ++;
    loadExample(stage);
    return CLEAR;
  }

  if(arduboy.justPressed(A_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      clear();
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
    if(arduboy.pressed(B_BUTTON)){
      if(cursor.theta == 0){
        cursor.theta = 7;
      }else{
        cursor.theta --;
      }
      anim = 1.0;
    }else{
      switch(mode){
        case RECT: mode = CIRCLE; break;
        case CIRCLE: mode = RECT; break;
        case NONE: break;
      }
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      if(cursor.theta == 7){
        cursor.theta = 0;
      }else{
        cursor.theta ++;
      }
      anim = -1.0;
    }else{
      switch(mode){
        case RECT: mode = CIRCLE; break;
        case CIRCLE: mode = RECT; break;
        case NONE: break;
      }
    }
  }
  count ++;

  return STAY;
}

void Game::draw(){
  arduboy.clear();
  arduboy.drawRect(0,0,128,64);
  gameDraw();
  if(count%2 == 0){
    drawCursor(WHITE);
  }
  arduboy.setCursor(0,0);
  arduboy.println(F("Game"));
}
