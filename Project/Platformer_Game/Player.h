#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"

class Player: public Entity
{
public:
    Player(World& world);

    void move(Direction dir) override; 
    
    void endMove(); 
    
    void jump();

    void endJump();

    void updatePosition() override;
    
    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    void stomp();
    
    void stomp2();
     
private:
    void setDirection(Direction dir);

    AnimatedSprite sprite;

    static const int height = 2;
    static const int width = 1;

    const float jumpSpeed = -.25f;
    const float acc = .01f;
    const float maxSpeed = .15f;
    const float dec = 0.95f;
    
    bool animateJump = false;

    bool moving = false;

    bool jumpKeyReleased = true;
};

#endif