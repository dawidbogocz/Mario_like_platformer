#ifndef Entity_H
#define Entity_H

#include "world.h"
#include "Animation.h"
#include <string>


class Entity
{
public:
    Entity(World& world, const int width, const int height);

    virtual ~Entity(){
    };

    void setJump(const float value);

    void setAcc(const float value);

    void setMaxSpeed(const float value);

    void setDec(const float value);

    void setYVel(const float value);
    
    void setXVel(const float value);
    
    float getYVel() const;

    float getXVel() const;

    float getPosX() const;

    float getPosY() const;

    void setPos(const float x, const float y);

    virtual sf::Sprite getSprite() const = 0;

    enum Direction
    {
        Left = -1,
        Right = 1
    };

    void kill();

    virtual void move(Direction dir);

    void jump();

    virtual void updatePosition();

    Direction getDirection() const;
    
    void setDirection(Direction dir);

    bool onGround() const;

    virtual void draw(sf::RenderWindow& window) = 0;

    bool alive(){
        return isAlive;
    }

    float worldBottom() const
    {
        return posY + height;
    }

private:

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;

    
    World& world;

    const int height;
    const int width;

    bool _onGround = false;

    float jumpSpeed = 0;
    float acc = 0;
    float maxSpeed = 0;
    float dec = 0.95f;

    float velY = 0;
    float velX = 0;
    float posX = 5.f;
    float posY = 11.f;
    
    Direction dir = Right;

    bool isAlive = true;

};

#endif