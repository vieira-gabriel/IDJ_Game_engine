#pragma once

#include "State.h"
#include "TitleState.h"
#include "EndState.h"
#include "GameData.h"

class StageState : public State
{
private:
    TileSet *tileSet;
    Music backgroundMusic;

public:
    StageState(/* args */);
    ~StageState();

    void LoadAssets();
    void Update(float dt);
    void Render();

    void Start();
    void Pause();
    void Resume();
};