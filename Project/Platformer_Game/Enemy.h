#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "sprite.h"
#include <iostream>

class Enemy: public Entity
{
public:

    Enemy(const int x, const int y, World& world, const int z);

    void updatePosition() override;

    void enemyType(const int typ);

    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    bool iskillable(){
        return killable;
    }

private:
    static const int height = 1;
    static const int width = 1;

    const float acc = .05f;

    AnimatedSprite sprite;

    void flip();

    bool killable = true;
};

#endif