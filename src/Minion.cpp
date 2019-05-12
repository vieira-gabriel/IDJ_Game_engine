#include "Minion.h"

#define MINION_SOURCE "assets/img/minion.png"
#define BULLET_SOURCE "assets/img/minionbullet1.png"

Minion::Minion(GameObject &associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated)
{
    Sprite *minion = new Sprite(associated, MINION_SOURCE);

    float scale = (float(rand() % 50 + 1) / 100.0) + 1.0;
    minion->SetScaleX(scale, scale);

    associated.AddComponent(minion);

    arc = arcOffsetDeg * (PI / 180);

    this->alienCenter = alienCenter;
    shared_ptr<GameObject> shared_alienCenter = alienCenter.lock();

    Vec2 distance = Vec2(200, 0);

    if (shared_alienCenter != nullptr) // If Alien is not dead
    {
        distance.GetRotated(arc); // Rotates minion around the Alien

        distance += shared_alienCenter->box.CenterPoint(); // Sets distance to move
        distance.x -= associated.box.w / 2;
        distance.y -= associated.box.h / 2;

        associated.box.x = distance.x + shared_alienCenter->box.CenterPoint().x; // Moves minion to distance in x axis calculated
        associated.box.y = distance.y + shared_alienCenter->box.CenterPoint().x; // Moves minion to distance in y axis calculated
    }
    else
        associated.RequestDelete();
}

void Minion::Update(float dt)
{
    shared_ptr<GameObject> shared_alienCenter = alienCenter.lock();
    Vec2 distance = Vec2(200, 0);

    if (shared_alienCenter != nullptr) // If Alien is not dead
    {
        associated.angleDeg = arc * (180 / PI);
        distance.GetRotated(arc); // Rotates minion around the Alien

        distance += shared_alienCenter->box.CenterPoint();
        distance.x -= associated.box.w / 2;
        distance.y -= associated.box.h / 2;

        associated.box.x = distance.x; // Moves minion to distance in x axis calculated
        associated.box.y = distance.y; // Moves minion to distance in y axis calculated

        arc += MINION_AGULAR_VEL * dt; // Updates arc
    }
    else
        associated.RequestDelete();
}

void Minion::Render()
{
}

bool Minion::Is(string type)
{
    return (type == "Minion");
}

void Minion::Shoot(Vec2 target)
{
    GameObject *bullet_GO = new GameObject;
    weak_ptr<GameObject> weak_bullet = Game::GetInstance().GetState().AddObject(bullet_GO);
    shared_ptr<GameObject> shared_bullet = weak_bullet.lock();

    float angle = (target - associated.box.CenterPoint()).Inclination();

    Bullet *bullet = new Bullet(*shared_bullet, angle, BULLET_SPEED, BULLET_DAMAGE, BULLET_DISTANCE, BULLET_SOURCE);

    shared_bullet->box += associated.box.CenterPoint();
    shared_bullet->box.x -= shared_bullet->box.w / 2;
    shared_bullet->box.y -= shared_bullet->box.h / 2; // Centralizes the reference

    shared_bullet->AddComponent(bullet); //adds bullet compoonent
}
