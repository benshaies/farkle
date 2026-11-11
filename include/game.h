#ifndef GAME_H
#define GAME_H
#include "raylib.h"

typedef struct{
  int value;
  bool scored;
  Rectangle rec;
}Dice;

typedef struct{
  Dice dice[6];
  int currentScore;
}Roll;

typedef enum{
  NOTHING,
  ROLLED,
  SCORING,
}GameState;

typedef struct{
  GameState state;
  int selectedDie;
  int score; 
}Game;



void gameInit();

void gameUpdate();

void gameDraw();

#endif // !GAME_H
