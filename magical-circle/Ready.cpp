#include "Ready.h"
#include "misaki_font.h"

#include "ArduboyTones.h"
extern ArduboyTones sound;

const char stageTitle0[] PROGMEM = "SimpleCircle";
const char stageTitle1[] PROGMEM = "SimpleRect";
const char stageTitle2[] PROGMEM = "SunLight";
const char stageTitle3[] PROGMEM = "SimpleMagic";
const char stageTitle4[] PROGMEM = "TwinForce";
const char stageTitle5[] PROGMEM = "HolyHex";
const char stageTitle6[] PROGMEM = "LunaPower";
const char stageTitle7[] PROGMEM = "TwinElement";
const char stageTitle8[] PROGMEM = "Sharpness";
const char stageTitle9[] PROGMEM = "SunEnergy";
const char stageTitle10[] PROGMEM = "Face";
const char stageTitle11[] PROGMEM = "SquarFlower";
const char stageTitle12[] PROGMEM = "TriplePower";

const char* const stageTitles[] PROGMEM = {
  stageTitle0,
  stageTitle1,
  stageTitle2,
  stageTitle3,
  stageTitle4,
  stageTitle5,
  stageTitle6,
  stageTitle7,
  stageTitle8,
  stageTitle9,
  stageTitle10,
  stageTitle11,
  stageTitle12,
};


void Ready::init(Game* pgame){
  game = pgame;
  counter = 100;
}

SceneID Ready::run(){
  if(arduboy.justPressed(A_BUTTON)){
    sound.tone(880, 100);
    return GAME;
  }
  if(arduboy.justPressed(UP_BUTTON)){
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
  }

  //counter--;
  //if(counter == 0){
  //  counter = 100;
  //  return GAME;
  //}
  return STAY;
}

PROGMEM const uint8_t jpInstruction1[] = { 0xf0, 0x5f,0x48,0x57,0x7d,0x48,0x7d,0x48,0x3a, };
PROGMEM const uint8_t jpBigger[] = { 0xf0, 0x4c,0x4c,0x4f,0x51,0x5b,0x8d, }; 
PROGMEM const uint8_t jpSmaller[] = { 0xf0, 0x63,0x46,0x57,0x51,0x5b,0x8d, };
PROGMEM const uint8_t jpDrawShape[] = { 0xf1, 0x21,0x1a,0x00, 0xf0, 0x5c,0x53,0x46,0x94,0x4a,0x4e,0x51, };
PROGMEM const uint8_t jpReset[] = { 0xf0, 0x86,0x8c,0x6c,0x4c,0x5b, };
PROGMEM const uint8_t jpInstruction2[] = { 0xf0, 0x5f,0x48,0x57,0x7d,0x48,0x7d,0x48,0x3b, };
PROGMEM const uint8_t jpChangeShape[] = { 0xf0, 0x5c,0x53,0x46,0x94,0x4f,0x8c,0x4d,0x4a,0x8d, };
PROGMEM const uint8_t jpInstruction3[] = { 0xf0, 0x5f,0x48,0x57,0x7d,0x48,0x7d,0x48,0x3c, };
PROGMEM const uint8_t jpRotate[] = { 0xf0, 0x4d,0x46,0x68,0x95, };
PROGMEM const uint8_t jpInstruction4[] = { 0xf0, 0x5f,0x48,0x57,0x7d,0x48,0x7d,0x48,0x3d, };
PROGMEM const uint8_t jpMoveUp[] = { 0xf0, 0x48,0x4a,0x7a,0x48,0x56,0x4d,0x5b, };
PROGMEM const uint8_t jpMoveDown[] = { 0xf0, 0x59,0x61,0x7a,0x48,0x56,0x4d,0x5b, };
PROGMEM const uint8_t jpNoInstruction[] = { 0xf0, 0x4c,0x59,0x4a,0x8d,0x55,0x6a,0x71,0x6c,0x6d,0x84,0x6c,0x46, };

void Ready::draw(){
  char buf[32];

  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("STAGE"));
  arduboy.print(stage + 1);
  arduboy.print(':');
  strcpy_P(buf, (char*)pgm_read_word(&stageTitles[stage]));
  arduboy.println(buf);
  //arduboy.println(counter);

  arduboy.setCursor(0,16);
  if(game->isJP){
    switch(stage){
      case 0:
        drawText(8, 16, jpInstruction1, sizeof(jpInstruction1));
        arduboy.setCursor(0, 16 + 8*1);
        arduboy.println("  \x18  :");
        drawText(8*5, 16 + 8, jpBigger, sizeof(jpBigger));
        arduboy.println("  \x19  :");
        drawText(8*5, 16 + 8*2, jpSmaller, sizeof(jpSmaller));
        arduboy.println("  A  :");
        drawText(8*5, 16 + 8*3, jpDrawShape, sizeof(jpDrawShape));
        arduboy.println("  B+A:");
        drawText(8*5, 16 + 8*4, jpReset, sizeof(jpReset));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 1:
        drawText(8, 16, jpInstruction2, sizeof(jpInstruction2));
        arduboy.setCursor(0, 16 + 8*1);
        arduboy.println(F("  \x1B,\x1A :"));
        drawText(8*5, 16 + 8, jpChangeShape, sizeof(jpChangeShape));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 2:
      case 3:
        drawText(8, 16, jpInstruction3, sizeof(jpInstruction3));
        arduboy.setCursor(0, 16 + 8*1);
        arduboy.println(F("  B+\x1B,\x1A :"));
        drawText(8*6, 16 + 8, jpRotate, sizeof(jpRotate));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 4:
        drawText(8, 16, jpInstruction4, sizeof(jpInstruction4));
        arduboy.setCursor(0, 16 + 8*1);
        arduboy.println(F("  B+\x18 :"));
        drawText(8*5, 16 + 8, jpMoveUp, sizeof(jpMoveUp));
        arduboy.println(F("  B+\x18 :"));
        drawText(8*5, 16 + 8*2, jpMoveDown, sizeof(jpMoveDown));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      default:
        drawText(8, 16, jpNoInstruction, sizeof(jpNoInstruction));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
    }
  }else{
    switch(stage){
      case 0:
        arduboy.println(F(" --INSTRUCTION1--"));
        arduboy.println(F("  \x18   :BIGGER"));
        arduboy.println(F("  \x19   :SMALLER"));
        arduboy.println(F("  A   :DRAW SHAPE"));
        arduboy.println(F("  B+A :RESET"));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 1:
        arduboy.println(F(" --INSTRUCTION2--"));
        arduboy.println(F("  \x1B,\x1A :CHANGE SHAPE"));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 2:
      case 3:
        arduboy.println(F(" --INSTRUCTION3--"));
        arduboy.println(F("  B+\x1B,\x1A :ROTATE"));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      case 4:
        arduboy.println(F(" --INSTRUCTION4--"));
        arduboy.println(F("  B+\x18 :MOVE UP"));
        arduboy.println(F("  B+\x19 :MOVE DOWN"));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
      default:
        arduboy.println(F(" NOTHING TO TEACH..."));
        arduboy.drawRect(4,16-2, 128 - 8, 8*5+3);
        break;
    }
  }
}
