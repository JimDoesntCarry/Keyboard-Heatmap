#include "gamemanager.h"
#include "graphics.h"

GameManager* gamemanager::sInstance = NULL;

GameManager* gamemanager::Instance() {
  if(sInstance == NULL){
    sInstance = new GameManager();
  }
  return  sInstance;
}

void gamemanager::Release(){
  delete sInstance;
  sInstance = NULL;
}

gamemanager::GameManager(){
  mQuit = false;
  mGraphics = graphics::Instance();
  if(graphics::Initialized()){
    mQuit = true;
  }
}

gamemanager::~GameManager(){
  graphics::Release();
  mGraphics = NULL;
}

void GameManager::Run(){
  while(mQuit == false) {
    while(SDL_PollEvent(&mEvents) != NULL){
      if(mEvents.type == SDL_QUIT){
        mQuit = true;
      }
      mGraphics->Render();
    }
  }
}
