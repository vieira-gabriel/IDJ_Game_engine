#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Vec2.h"
#include "Rect.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"
#include "Alien.h"
#include "PenguinBody.h"
#include "Collision.h"
#include <SDL_include.h>
#include <string>
#include <vector>
#include <memory>

const string BACKGROUND_SPRITE = "assets/img/ocean.jpg";
#define BACKGROUND_MUSIC "assets/audio/stageState.ogg"
#define PENGUIN_SOURCE "assets/img/penguinface.png"
#define PENGUIN_SOUND "assets/audio/boom.wav"
#define TILE_MAP_SOURCE "assets/map/tileMap.txt"
#define TILE_SET_SOURCE "assets/img/tileset.png"
#define TILE_WIDTH 64
#define TILE_HEIGHT 64
#define MINIONS 4

class State
{
private:
  shared_ptr<GameObject> bg;
  Music music;
  bool quitRequested;
  bool started;
  vector<shared_ptr<GameObject>> objectArray;

  // void Input();

public:
  State();
  ~State();
  bool QuitRequested();
  void LoadAssets();
  void Update(float dt);
  void Render();
  void Start();
  weak_ptr<GameObject> AddObject(GameObject *go);
  weak_ptr<GameObject> GetObjectPtr(GameObject *go);
};