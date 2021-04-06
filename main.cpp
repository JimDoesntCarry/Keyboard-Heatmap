#include <iostream>
#include <SDL2/SDL.h>
#include "gamemanager.h"
#include "graphics.h"
using namespace std;

int main(int argc, char ** argv) {
  GameManager* game = gamemanager::Instance();
  game->Run();

  GameManager::Release();
  game = NULL;
  return 0;
}
