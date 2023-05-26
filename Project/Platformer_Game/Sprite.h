#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>


class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    int getSpriteSize() const;

    void flip();

    void setPosition(float x, float y);

    void setTexture(sf::Texture _texture);

protected:
    sf::Texture sprite;

private:
    const int spriteSize = 16;

    float Coords(const float c) const;
};

#endif