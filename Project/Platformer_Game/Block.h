#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include "sprite.h"
#include "Resources.h"

class Block: public Sprite
{
public:
    enum Type
    {
        Crate,
        Stone,
        Empty,
        Gold,
        Grass,
        Grass_L_Corner,
        Grass_L,
        Dirt,
        Grass_R,
        Grass_R_Corner,
        Pilar_L_Top,
        Pilar_R_Top,
        Pilar_L,
        Pilar_R
    };
    
    Block(Type type, const int x, const int y);

    void draw(sf::RenderWindow& window);

private:
    Resources<sf::Texture, Type> textures;

    Sprite block;

    //const std::string mapFilename = "Textures/Blocks.png";
};

#endif