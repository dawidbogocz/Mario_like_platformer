#include "Entity.h"
#include <iostream>
#include <cmath>

Entity::Entity(World& world, const int width, const int height):
    world(world),
    width(width),
    height(height)
{}

void Entity::setJump(const float value)
{
    jumpSpeed = value;
}

void Entity::setAcc(const float value)
{
    acc = value;
}

void Entity::setMaxSpeed(const float value)
{
    maxSpeed = value;
}

void Entity::setDec(const float value)
{
    dec = value;
}

void Entity::setYVel(const float value)
{
    velY = value;
}

void Entity::setXVel(const float value)
{
    velX = value;
}

float Entity::getYVel() const
{
    return velY;
}

float Entity::getXVel() const
{
    return velX;
}

float Entity::getPosX() const
{
    return posX;
}

float Entity::getPosY() const
{
    return posY;
}

void Entity::setPos(const float x, const float y)
{
    posX = x;
    posY = y;
}

void Entity::kill()
{
    isAlive = false;
}

void Entity::move(Direction dir)
{
    setDirection(dir);
    velX = velX + dir * acc;
    if (fabsf(velX) > maxSpeed) {
        velX = dir * maxSpeed;
    }
}

void Entity::jump()
{
    setYVel(jumpSpeed);
}

void Entity::updatePosition()
{   
    velY += world.getGravity();
    posY += velY;
    checkForGround();

    if (!alive()) {
        return;
    }

    checkForRoof();

    velX *= dec;
    posX += velX; 
    checkForWall(); 
}

Entity::Direction Entity::getDirection() const
{
    return dir;
}

void Entity::setDirection(Direction new_dir)
{
    if (dir != new_dir) {
        dir = new_dir;
    }
}

bool Entity::onGround() const
{
    return _onGround;
}


int Entity::bufferedRoundoff(float i) const
{
    if (i == (int)i) { 
        return i - 1; 
    }
    else {
        return i;
    }
}

int Entity::left() const
{
    return posX;
}
int Entity::right() const
{
    return bufferedRoundoff(posX + width);
}
int Entity::top() const
{
    return posY;
}
int Entity::bottom() const
{
    return bufferedRoundoff(posY + height);
}

void Entity::checkForGround()
{
    if (posY > world.worldBottom() - height) {
        isAlive = false;
        return;
    }

    if( world.Solid(bottom(), left()) || world.Solid(bottom(), right()))  {
        posY = top();
        velY = 0;
        _onGround = true;
    }
    else _onGround = false;
}

void Entity::checkForRoof()
{
    if( world.Solid( top(), left() ) || world.Solid( top(), right() ) ){
        posY = top() + 1;
        velY = -velY;
    }
}

void Entity::checkForWall()
{
    if(posX < 0){
        posX = 0;
        velX = 0;
    }
    if(posX > world.worldEnd() - width){
        posX = world.worldEnd() - width;
        velX = 0;
    }

    auto isWall = [&](const float x){
        for(int i = 0; i < height; i++)
            if (world.Solid(top() + i, x)) {
                return true;
            }
        
        if (world.Solid(bottom(), x)) {
            return true;
        }
        return false;
    };

    if(isWall(left())){
        posX = left() + 1;
        velX = 0;
    }

    if(isWall(right())){
        posX = right() - 1;
        velX = 0;
    }
}

