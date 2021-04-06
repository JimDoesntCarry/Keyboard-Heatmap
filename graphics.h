#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL2/SDL.h>

class Graphics {
public:
  static const int SCREEN_WIDTH = 500;
  static const int SCREEN_HEIGHT = 500;
private:
  static Graphics* sInstance;
  static bool sInitialized;
  SDL_Window* mWindow;
  SDL_Surface* mBackBuffer;

public:
  static Graphics* Instance();
  static void Release();
  void Render();
private:
  Graphics();
  ~Graphics();
  bool Init();
}
