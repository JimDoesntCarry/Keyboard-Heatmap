#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H
#include "graphics.h"

class GameManager{
private:
  static GameManager* sInstance;
  bool mQuit;
  Graphics* mGraphics;
  SDL_Event mEvents;

public:
  static GameManager* Instance();
  static void Release();
  void Run();
private:
  GameManager(); //Constructor
  ~GameManager(); //Deconstructor
};
#endif
