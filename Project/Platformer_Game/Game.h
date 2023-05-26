#ifndef GAME_H
#define GAME_H

#include "world.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include <string>
#include <cmath>

class Game
{
public:
    Game(const int width, const int height, const std::string title, int lvl);

    void run();

private:

    void display(sf::RenderWindow& window);

    void help(std::string state, std::string font);

    void inputs(sf::RenderWindow& window);

    void updateObjects(sf::RenderWindow& window, sf::View& view);

    void drawObjects(sf::RenderWindow& window);

    void checkForEnemyCollision();

    void removeCorpse();

    std::vector<std::unique_ptr<Enemy>> findNearbyEnemies() const;

    bool gameOver = false;
    bool gameWon = false;
    sf::RenderWindow window;
    World world;
    Player player;
    std::vector<std::unique_ptr<Enemy>> enemies;

};

#endif