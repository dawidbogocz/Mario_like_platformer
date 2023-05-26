#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>

Block::Block(Type type, const int x, const int y)
{
    std::filesystem::path tmp{ std::filesystem::current_path() / "Textures/Blocks.png" };
    std::string text{ tmp.string() };

    sf::Texture sprite;
    textures.load(type, text, sf::IntRect(Sprite::getSpriteSize() * type, 0, Sprite::getSpriteSize(), Sprite::getSpriteSize()));

    block.setTexture(textures.get(type));

    block.setPosition(x, y);
}

void Block::draw(sf::RenderWindow& window)
{
    window.draw(block);
}