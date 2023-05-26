#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

Enemy::Enemy(const int x, const int y, World& world, const int z):
    Entity(world, width, height),
    sprite(width, height, 0.1)
{
    setXVel(acc);
    setDec(1);

    Entity::setPos(x, y);

    enemyType(z);
    /*std::filesystem::path tmp{ std::filesystem::current_path() / "Textures/Enemy.png" };
    std::string text{ tmp.string() };*/

    /*sf::Texture texture;
    texture.loadFromFile(text, sf::IntRect(0, 0, 16, 16));

    sprite.setTexture(texture);*/
}

void Enemy::updatePosition()
{
    if(getXVel() == 0){
        flip();
        setXVel(acc * getDirection());
    }


    Entity::updatePosition();

    sprite.setPosition(getPosX(), getPosY());
}

void Enemy::enemyType(const int typ)
{
    std::string text;

    if (typ == 1) {
        killable = true;
        std::filesystem::path tmp{ std::filesystem::current_path() / "Textures/Enemy1.png" };
        text = tmp.string();
    }
    else if (typ == 2) {
        killable = false;
        std::filesystem::path tmp{ std::filesystem::current_path() / "Textures/Enemy2.png" };
        text = tmp.string();
    }

    sf::Texture texture;
    texture.loadFromFile(text, sf::IntRect(0, 0, 16, 16));

    sprite.setTexture(texture);
}

void Enemy::flip()
{
    if (getDirection() == Left) {
        setDirection(Right);
    }
    else {
        setDirection(Left);
    }

    sprite.flip();
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Sprite Enemy::getSprite() const
{
    return sprite;
}

