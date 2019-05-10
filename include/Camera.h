#pragma once

#include "Vec2.h"
#include "GameObject.h"
#include "InputManager.h"

#define SCR_WIDTH 1024
#define SCR_HEIGHT 600
#define DEFAULT_SPEED 300

using namespace std;

class Camera
{
private:
    static GameObject *focus;

public:
    static Vec2 pos;
    static Vec2 speed;

    static void Follow(GameObject *newFocus);
    static void Unfollow();
    static void Update(float dt);
};