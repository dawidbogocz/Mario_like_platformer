#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "block.h"
#include <memory>

class World
{
public:
    World() = default;

    void loadMap(int lvl);

    void draw(sf::RenderWindow& window);

    bool Solid(const int x, const int y) const;  

    float getGravity() const;  

    int worldEnd() const;

    int worldBottom() const;

    bool finish(const int x) const;

private:
    std::vector<std::vector<std::unique_ptr<Block>>> map;

    const float gravity = 0.0075f;

    int fin;

};

#endif