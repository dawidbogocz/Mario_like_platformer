#include "sprite.h"
#include <iostream>

int Sprite::getSpriteSize() const
{
    return spriteSize;
}

void Sprite::flip()
{
    if(getScale().x > 0){
        setOrigin({getLocalBounds().width, 0});
        setScale(sf::Vector2f(-1, 1));
    }
    else{
        setOrigin({0, 0});
        setScale(sf::Vector2f(1, 1));
    }
}

void Sprite::setPosition(float x, float y)
{
    sf::Sprite::setPosition(Coords(x), Coords(y));
}

void Sprite::setTexture(sf::Texture _texture)
{
    sprite = _texture;
    sf::Sprite::setTexture(sprite);
};

float Sprite::Coords(const float c) const
{
    return c*spriteSize;
}
