#include "../include/game.h"
#include <raylib.h>

int screenWidth = 1280, screenHeight = 720;


Game game;
Roll currentRoll;


void resetDice(){
  for(int i = 0; i < 6; i++){
    currentRoll.dice[i].value = 0;
    currentRoll.dice[i].scored = false;
    currentRoll.dice[i].rec = (Rectangle){100 + (i * 200), 450, 100, 100};
  }
}

// Returns true when roll is done
bool rollDice(){
  for(int i = 0; i < 6; i++){
    if(currentRoll.dice[i].scored)
      continue;

    currentRoll.dice[i].value = GetRandomValue(1, 6);
  } 

  return true;
}

void drawDice(){
  
  for(int i = 0; i < 6; i++){
    if(currentRoll.dice[i].scored)
      continue;
    
    Rectangle rec = currentRoll.dice[i].rec;
    if(game.selectedDie ==  i){
      DrawCircle(rec.x + rec.width/2, rec.y + rec.height/2, rec.width, RED);
    }
    DrawRectangleRec(currentRoll.dice[i].rec, BLACK);

    DrawText(TextFormat("%d", currentRoll.dice[i].value), rec.x + 10, rec.y + 10, 50,BLUE);

    
  }
}

void selectDie(){
    
  if(IsKeyPressed(KEY_D)){
    if(game.selectedDie == 5){
      game.selectedDie = 0;
    }
    else{
      game.selectedDie++;
    }
  }
  else if(IsKeyPressed(KEY_A)){
    if(game.selectedDie == 0){
      game.selectedDie = 5;
    }
    else{
      game.selectedDie--;
    }
  }
}




void gameInit(){
  InitWindow(screenWidth, screenHeight, "Farkle");
  SetTargetFPS(60);

  game.state = NOTHING;
  game.score = 0;
  game.selectedDie = 0;

  resetDice();
}

void gameUpdate(){
  
  switch (game.state){
    case NOTHING:
      if(IsKeyPressed(KEY_SPACE)){
        if(rollDice()){
          game.state = ROLLED;
        }
      }
      break;
    case ROLLED:
      selectDie();
      break;
    case SCORING:
      break;
  }
}

void gameDraw(){
  switch (game.state){
    case NOTHING:
      break;
    case ROLLED:
      drawDice();
      break;
    case SCORING:
      break;
  }
  ClearBackground(RAYWHITE);
  BeginDrawing();

  EndDrawing();

}

