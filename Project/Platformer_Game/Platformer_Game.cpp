#include "game.h"
import Menu;

int main()
{
    const std::string title = "POLSL_Adventures";
    const int width = 640;
    const int height = 480;

    //Game game(width, height, title);
    
    sf::RenderWindow window(sf::VideoMode(width, height), title, sf::Style::Default);

    Menu menu(width, height);

    while (window.isOpen())
    {
        window.setActive();
        window.requestFocus();
        sf::Event event;
        

        while (window.pollEvent(event))
        {
            
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::W:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::S:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    Game game1(width, height, title, 1);
                    Game game2(width, height, title, 2);
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        game1.run();
                        break;
                    case 1:
                        game2.run();
                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }
            
        }
        window.clear();

        menu.draw(window);

        window.display();
    }

    return 0;
}
