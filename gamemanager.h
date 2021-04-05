#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H
#include "Graphics.h"

class GameManager{
private:
  static GameManager* sInstance;
  bool mQuit;
  Grpahics* mGraphics;
  SDL_event mEvents;

public:
  static GameManager* Instance();
  static void Release();
  void Run();
private:
  GameManager(); //Constructor
  ~GameManager(); //Deconstructor
}

#endif
https://youtu.be/ATa_joa6Gzg?t=1152s
