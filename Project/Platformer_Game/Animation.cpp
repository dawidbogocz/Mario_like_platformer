#include "Animation.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(const int width, const int height, const double speed):
    width(width),
    height(height),
    speed(speed)
{
    setTextureRect(sf::IntRect(0, 0, width * getSpriteSize(), height * getSpriteSize()));
}

void AnimatedSprite::set(const int sprite)
{
    currentTexture = sprite;
    setTextureRect(sf::IntRect(sprite * getSpriteSize(), 0, 16, 32));
}

void AnimatedSprite::update(const int startTexture, const int endTexture)
{
    static bool goingRight = true;

    if (currentTexture == endTexture || currentTexture == 0) {
        goingRight = !goingRight;
    }if (currentTexture <= endTexture && goingRight) {
        animate(endTexture);
    }
    else {
        animate(startTexture);
    }

}

int AnimatedSprite::getCurrentTexture() const
{
    return currentTexture;
}


void AnimatedSprite::animate(const int targetTexture)
{
    if (targetTexture == currentTexture) {
        return;
    }

    auto now = clock::now();

    std::chrono::duration<double> duration = now - lastframe;
    if (duration.count() > speed) {
        int x;
        if (currentTexture < targetTexture) {
            x = getTextureRect().left + getSpriteSize();
        }
        else {
            x = getTextureRect().left - getSpriteSize();
        }

        setTextureRect(sf::IntRect(x, 0, 16, 32));

        currentTexture = x / getSpriteSize();
        lastframe = clock::now();
    }
}