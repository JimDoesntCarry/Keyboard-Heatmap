#include "graphics.h"
using namespace std;

Graphics* graphics::sInstance = NULL;
bool graphics::sInitialized = false;

Graphics* graphics::Instance() {
  if(sInstance == NULL){
    sInstance = new Graphics();
  }
  return sInstance;
}

void Graphics* graphics::Release() {
  delete sInstance;
  sInstance = NULL;
  sInitialized = false;
}

bool graphics::Initialized() {
  return sInitialized;
}

graphics::Graphics(){
  mBackbuffer = NULL;

  sInitialized = Init();
}

graphics::~Graphics(){
  SDL_DestroyWindow(mWindow);
  mWindow = NULL;
  SDL_Quit();
}

bool graphics::Init(){
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL Initialization Error: %s\n", SDL_GetError());
    return false;
  }
  mWindow = SDL_CreateWindow("Heatmap",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(mWindow == NULL){
    print("Windows Creation Error: %s\n", SDL_GetError());
    return false;
  }
  mBackBuffer = SDL_GetWindowSurface(mWindow);
  return true;
}

void graphics::Render(){
  SDL_UpdateWindowSurface(mWindow); //Refreshes Backbuffer of the Window
}
