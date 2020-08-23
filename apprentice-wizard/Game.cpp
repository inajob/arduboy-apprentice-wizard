#include "Game.h"
#include "stage.h"
#include "ArduboyTones.h"

extern ArduboyTones sound;

void Game::loadExample(byte n){
  cursor.r = 0;
  cursor.theta = 0;
  size = 4;

  byte* stage = stages[n];

  for(byte i = 0; i < MAX_SHAPE; i ++){
      exampleShapes[i].type = NONE;
  }
  for(byte i = 0; i < MAX_SHAPE; i ++){
    struct Shape s;
    s.pos.r =     pgm_read_byte(stage + i*4);
    s.pos.theta = pgm_read_byte(stage + i*4 + 1);
    s.type =      pgm_read_byte(stage + i*4 + 2);
    s.size =      pgm_read_byte(stage + i*4 + 3);
    if(s.type == NONE){
      break;
    }
    exampleShapes[i] = s;
  }
}

bool Game::equalShape(struct Shape s1, struct Shape s2){
  if(s1.type == UTRI && s2.type == DTRI || s1.type == DTRI && s2.type == UTRI){
    if(s1.pos.r == 0 && s2.pos.r == 0 && s1.size == s2.size){
      return (s1.pos.theta+4)%8 == s2.pos.theta;
    }
  }
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
    case UTRI:
    case DTRI:
      return s1.pos.r == s2.pos.r &&
        s1.pos.theta == s2.pos.theta &&
        s1.size == s2.size;
    case VLINE:
      // ignore size
      return s1.pos.r == s2.pos.r &&
        s1.pos.theta == s2.pos.theta;
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

void Game::drawRect(struct Shape s, int8_t ox, int8_t oy){
  double rx0 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        )/sqrt(2);
  double ry0 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        )/sqrt(2);
  double rx1 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 1.0/2))/sqrt(2);
  double ry1 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 1.0/2))/sqrt(2);
  double rx2 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/2))/sqrt(2);
  double ry2 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/2))/sqrt(2);
  double rx3 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 3.0/2))/sqrt(2);
  double ry3 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 3.0/2))/sqrt(2);

  double x0 = rx0 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x2 = rx2 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y2 = ry2 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x3 = rx3 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y3 = ry3 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;

  arduboy.drawLine(ox + x0, oy + y0, ox + x1, oy + y1);
  arduboy.drawLine(ox + x1, oy + y1, ox + x2, oy + y2);
  arduboy.drawLine(ox + x2, oy + y2, ox + x3, oy + y3);
  arduboy.drawLine(ox + x3, oy + y3, ox + x0, oy + y0);
}
void Game::drawUtri(struct Shape s, int8_t ox, int8_t oy){
  double rx0 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        )/sqrt(2);
  double ry0 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        )/sqrt(2);
  double rx1 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/3))/sqrt(2);
  double ry1 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/3))/sqrt(2);
  double rx2 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 4.0/3))/sqrt(2);
  double ry2 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 4.0/3))/sqrt(2);

  double x0 = rx0 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x2 = rx2 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y2 = ry2 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;

  arduboy.drawLine(ox + x0, oy + y0, ox + x1, oy + y1);
  arduboy.drawLine(ox + x1, oy + y1, ox + x2, oy + y2);
  arduboy.drawLine(ox + x2, oy + y2, ox + x0, oy + y0);
}
void Game::drawDtri(struct Shape s, int8_t ox, int8_t oy){
  double rx0 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8         + 1.0/3))/sqrt(2);
  double ry0 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8         + 1.0/3))/sqrt(2);
  double rx1 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/3 + 1.0/3))/sqrt(2);
  double ry1 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 2.0/3 + 1.0/3))/sqrt(2);
  double rx2 = (7.0*s.size)*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 4.0/3 + 1.0/3))/sqrt(2);
  double ry2 = (7.0*s.size)*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8 + 4.0/3 + 1.0/3))/sqrt(2);

  double x0 = rx0 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x2 = rx2 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y2 = ry2 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;

  arduboy.drawLine(ox + x0, oy + y0, ox + x1, oy + y1);
  arduboy.drawLine(ox + x1, oy + y1, ox + x2, oy + y2);
  arduboy.drawLine(ox + x2, oy + y2, ox + x0, oy + y0);
}
void Game::drawVLine(struct Shape s, int8_t ox, int8_t oy){
  double rx0 = (4.0*(0))*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        );
  double ry0 = (4.0*(0))*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)        );
  double rx1 = (4.0*(2))*scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8));
  double ry1 = (4.0*(2))*scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8));

  double x0 = rx0 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y0 = ry0 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double x1 = rx1 + 8*s.pos.r * scale * cos(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;
  double y1 = ry1 + 8*s.pos.r * scale * sin(PI*(2.0*(s.pos.theta - cursor.theta - anim - 2)/8)) + 32;

  arduboy.drawLine(ox + x0, oy + y0, ox + x1, oy + y1);
  arduboy.drawLine(ox + x1, oy + y1, ox + x0, oy + y0);
}


void Game::drawCircle(struct Shape s, int8_t ox, int8_t oy){
  arduboy.drawCircle(
    32 + 8*s.pos.r*scale*cos(PI*2/8*(s.pos.theta - cursor.theta - anim - 2)) + ox,
    32 + 8*s.pos.r*scale*sin(PI*2/8*(s.pos.theta - cursor.theta - anim - 2)) + oy,
    s.size * 4 * scale
  );
}
void Game::drawShape(struct Shape s, int8_t ox, int8_t oy){
  switch(s.type){
    case NONE:
      break;
    case RECT:
      drawRect(s, ox, oy);
      break;
    case CIRCLE:
      drawCircle(s, ox, oy);
      break;
    case UTRI:
      drawUtri(s, ox, oy);
      break;
    case DTRI:
      drawDtri(s, ox, oy);
      break;
    case VLINE:
      drawVLine(s, ox, oy);
      break;

  }
}

void Game::gameDraw(){
  for(byte i = 0; i < MAX_SHAPE; i ++){
    drawShape(shapes[i]);
    if(!isFreestyle){
      drawShape(exampleShapes[i], 64, 0);
    }
  }
  if(isFreestyle){
    arduboy.setCursor(64+16,0);
    arduboy.println(F("Freestyle"));
  }
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

void Game::drawShapeSelector(){
  arduboy.fillRect(0, 16, 128, 32, BLACK);
  arduboy.drawRect(0, 16, 128, 32);

  struct Shape s;
  s.pos.r = 0;
  s.pos.theta = cursor.theta;
  s.type = RECT;
  s.size = 2;
  drawShape(s, -16, 0);
  s.type = CIRCLE;
  drawShape(s, 8, 0);
  s.type = UTRI;
  drawShape(s, 32, 0);
  s.type = DTRI;
  drawShape(s, 56, 0);
  s.type = VLINE;
  drawShape(s, 56 + 24, 0);

  if(count%2 == 0){
    arduboy.drawRect(24*(mode - 1) + 4, 16+4, 24, 24);
  }
}

void Game::init(){
  loadExample(0);
}

SceneID Game::run(){
  if(abs(anim) > 0.01){
    anim = (abs(anim) - 0.1)*(anim/abs(anim));
  }

  if(!isFreestyle && check()){
    sound.tone(NOTE_C5, 200, NOTE_C6, 200, NOTE_C7, 400);
    return CLEAR;
  }

  if(arduboy.justPressed(A_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      sound.tone(880, 100, 440, 100, 220, 100);
      clear();
      if(isFreestyle){
        return TITLE;
      }
    }else{
      // put shape
      if(shapeIndex < MAX_SHAPE){
        struct Shape* cur = &shapes[shapeIndex];
        cur->type = mode;
        cur->pos = cursor;
        cur->size = size;

        // check already draw the shape
        bool hit = false;
        for(byte i = 0; i < shapeIndex; i ++){
          if(equalShape(*cur, shapes[i])){
            hit = true;
            break;
          }
        }
        if(hit == false){
          sound.tone(880, 100);
          shapeIndex ++;
        }else{
          cur->type = NONE;
        }
      }
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
      sound.tone(220, 25, 440, 25);
    }else{
      if(size == 8){
        size = 1;
      }else{
        size ++;
      }
      sound.tone(440, 50);
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(arduboy.pressed(B_BUTTON)){
      if(cursor.r == 0){
        cursor.r = 3;
      }else{
        cursor.r --;
      }
      sound.tone(440, 25, 220, 25);
    }else{
      if(size == 1){
        size = 8;
      }else{
        size --;
      }
      sound.tone(440, 50);
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
      sound.tone(440, 25, 220, 25);
    }else{
      switch(mode){
        case RECT: mode = CIRCLE; break;
        case CIRCLE: mode = UTRI; break;
        case UTRI: mode = DTRI; break;
        case DTRI: mode = VLINE; break;
        case VLINE: mode = RECT; break;
        case NONE: break;
      }
      shapeSelectorTimer = 8;
      sound.tone(440, 50);
    }
  }
  if(arduboy.pressed(RIGHT_BUTTON)){
    if(!arduboy.pressed(B_BUTTON)){
      shapeSelectorTimer = 8;
      sound.tone(440, 50);
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
      sound.tone(220, 25, 440, 25);
    }else{
      switch(mode){
        case RECT: mode = VLINE; break;
        case VLINE: mode = DTRI; break;
        case DTRI: mode = UTRI; break;
        case UTRI: mode = CIRCLE; break;
        case CIRCLE: mode = RECT; break;
        case NONE: break;
      }
      shapeSelectorTimer = 8;
      sound.tone(440, 50);
    }
  }
  if(arduboy.pressed(LEFT_BUTTON)){
    if(!arduboy.pressed(B_BUTTON)){
      shapeSelectorTimer = 8;
      sound.tone(440, 50);
    }
  }

  count ++;
  if(isTimeAttack){
    timer ++;
  }
  if(shapeSelectorTimer > 0){
    shapeSelectorTimer --;
  }

  return STAY;
}

void Game::draw(){
  arduboy.clear();
  arduboy.drawRect(0,0,128,64);
  gameDraw();
  if(count%2 == 0 && showCursor){
    drawCursor(WHITE);
  }

  if(isTimeAttack){
    arduboy.setCursor(1, 63-8);
    arduboy.print(timer);
  }
  if(shapeSelectorTimer > 0){
    drawShapeSelector();
  }
}
