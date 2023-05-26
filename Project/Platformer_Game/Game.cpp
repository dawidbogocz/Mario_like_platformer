#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <filesystem>
import Menu;

Game::Game(const int width, const int height, const std::string title, int lvl):
    window(sf::VideoMode(width, height), title),
    player(world)
{
    window.setFramerateLimit(60);

    enemies.emplace_back(std::make_unique<Enemy>(60.f, 11.f, world, 1));
    enemies.emplace_back(std::make_unique<Enemy>(45.f, 11.f, world, 2));
    enemies.emplace_back(std::make_unique<Enemy>(25.f, 11.f, world, 1));
    enemies.emplace_back(std::make_unique<Enemy>(65.f, 11.f, world, 2));
    enemies.emplace_back(std::make_unique<Enemy>(95.f, 11.f, world, 2));
    enemies.emplace_back(std::make_unique<Enemy>(150.f, 11.f, world, 2));
    enemies.emplace_back(std::make_unique<Enemy>(120.f, 11.f, world, 1));

    world.loadMap(lvl);
}

void Game::run()
{
    sf::View view;

    const double viewZoom = 0.5;

    view.setSize(window.getSize().x * viewZoom, window.getSize().y * viewZoom);

    window.setView(view);
    
    while (window.isOpen()){

        window.setActive();
        window.requestFocus();
    
        inputs(window);

        updateObjects(window, view);

        if (gameOver || gameWon) {
            display(window);
            window.clear(sf::Color::White);
            window.display();
            gameOver = false;
            gameWon = false;
            window.close();
            return;
        }

        drawObjects(window);
    }

}

void Game::display(sf::RenderWindow& window)
{
    sf::Font font;
    std::filesystem::path tmp{ std::filesystem::current_path() / "Font.ttf" };
    std::string fnt{ tmp.string() };
    if (!font.loadFromFile("Font.ttf"))
        std::cout << "Failed to open font" << std::endl;

    sf::Text text;
    text.setFont(font);
    if (gameOver == true) {
        text.setString("GAME OVER");
        text.setFillColor(sf::Color::Red);
    }
    else if (gameWon == true) {
        text.setString("YOU WON");
        text.setFillColor(sf::Color::Yellow);
    }

    text.setCharacterSize(50);

    sf::View view;

    view.setSize(window.getSize().x, window.getSize().y);

    view.setCenter(text.getPosition().x + text.getGlobalBounds().width / 2, text.getPosition().y + text.getGlobalBounds().height / 2);

    window.setView(view);

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(2));

}

void Game::inputs(sf::RenderWindow& window)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.jump();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.endMove();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.move(Player::Right);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.move(Player::Left);
    }

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up) {
            player.endJump();
        }
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) {
            player.endMove();
        }
    }
        
}

void Game::updateObjects(sf::RenderWindow& window, sf::View& view)
{
    player.updatePosition();

    if (world.finish(player.getPosX()))
    {
        gameWon = true;
        return;
    }

    if (!player.alive())
    {
        gameOver = true;
    }
        
    std::for_each(enemies.begin(), enemies.end(), 
        [](std::unique_ptr<Enemy>& ENMY){
        ENMY->updatePosition();
        }
    );

    checkForEnemyCollision();
    removeCorpse();
    
    view.setCenter(sf::Vector2f(player.getSprite().getPosition().x, 175));
    
    if (view.getCenter().x < view.getSize().x / 2) {
        view.setCenter(sf::Vector2f(view.getSize().x / 2, 175));
    }

    window.setView(view);
}

void Game::drawObjects(sf::RenderWindow& window)
{
    window.clear(sf::Color::Cyan);

    world.draw(window);
    player.draw(window);
    

    std::for_each(enemies.begin(), enemies.end(), [&window](std::unique_ptr<Enemy>& ENMY){
        ENMY->draw(window);
        }
    );

    window.display();
}

void Game::checkForEnemyCollision()
{
    std::for_each(enemies.begin(), enemies.end(), [&](std::unique_ptr<Enemy>& e)
    {
        if (player.getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
        {

            float slope = fabsf((e->getPosY() - player.getPosY()) / (e->getPosX() - player.getPosX()));

            if ((slope >= 1) && player.worldBottom() < e->worldBottom())
            {
                if (e->iskillable()) {
                    e->kill();
                    player.stomp();
                }
                else {
                    player.stomp2();
                }
            }
            else
                gameOver = true;

        }
    });
}

void Game::removeCorpse() {
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const std::unique_ptr<Enemy>& e) {
        if (!e->alive() && e->iskillable()) {
            return true;
        }
        else {
            return false;
        }
    }), enemies.end());
}