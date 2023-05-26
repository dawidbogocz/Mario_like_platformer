#include "player.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <filesystem>

Player::Player(World& world) :
    Entity(world, width, height),
    sprite(width, height)
{
    setMaxSpeed(maxSpeed);
    setAcc(acc);
    setJump(jumpSpeed);
    std::filesystem::path tmp{ std::filesystem::current_path() / "Textures/herochar.png"};
    std::string text{ tmp.string()};

    sf::Texture texture;
    texture.loadFromFile(text, sf::IntRect(0, 0, 80, 32));

    sprite.setTexture(texture);
}
void Player::stomp(){
    setYVel(jumpSpeed / 2);
}
void Player::stomp2()
{
    setYVel(jumpSpeed);
}
void Player::jump()
{
    if (!jumpKeyReleased) {
        return;
    }
    jumpKeyReleased = false;

    if(onGround())
    {
        Entity::jump();
    }
}

void Player::endJump()
{    
    if (getYVel() < jumpSpeed / 2) {
        setYVel(jumpSpeed / 2);
    }
    jumpKeyReleased = true;
}

void Player::move(Direction dir)
{
    setDirection(dir);
    Entity::move(dir);
}

void Player::endMove()
{
    moving = false;
}

void Player::updatePosition()
{
    if (!onGround()) {
        sprite.set(4);
    }
    else if (sprite.getCurrentTexture() == 4) { 
        sprite.set(0); 
    }
    else if (moving) {
        sprite.update(0, 2);
    }
    else {
        sprite.update(0, 0);
    }
    
    Entity::updatePosition();

    sprite.setPosition(getPosX(), getPosY());
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Sprite Player::getSprite() const
{
    return sprite;
}

void Player::setDirection(Direction new_dir)
{
    moving = true;
    if(getDirection() != new_dir)
    {
        sprite.flip();
        Entity::setDirection(new_dir);
    }
}

