//module;
//
//#include <iostream>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//
//export module World;
//
//import Player;
////import TileMap;
//
//
//export class World {
//private:
//	sf::RenderWindow window;
//	sf::Event event;
//	sf::View view;
//
//	Player* player;
//
//	void initWindow();
//	void initPlayer();
//
//public:
//	World();
//	virtual ~World();
//
//	//Functions
//	void updatePlayer();
//	void update();
//	void renderPlayer();
//	void render();
//	sf::RenderWindow& getWindow();
//};
//
//void World::initWindow()
//{
//	this->window.create(sf::VideoMode(800, 600), "POLSL_Adventures", sf::Style::Close | sf::Style::Titlebar);
//	this->window.setFramerateLimit(60);
//}
//
//void World::initPlayer()
//{
//	this->player = new Player();
//}
//
//World::World()
//{
//	this->initWindow();
//	this->initPlayer();
//}
//
//World::~World()
//{
//	delete this->player;
//}
//
//void World::updatePlayer()
//{
//	this->player->update();
//}
//
//
//void World::renderPlayer()
//{
//	this->player->render(this->window);
//}
//
//export void World::render()
//{
//	this->window.clear(sf::Color::Blue);
//
//	this->window.setView(view);
//
//	//Render game
//	this->renderPlayer();
//
//	this->window.display();
//}
//
//export sf::RenderWindow& World::getWindow()
//{
//	return this->window;
//}
//
//export void World::update()
//{
//	//Polling window event
//	while (this->window.pollEvent(this->event)) {
//		if (event.type == sf::Event::Closed){
//			window.close();
//		}
//		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
//			this->window.close();
//		}
//		if (this->event.type == sf::Event::KeyReleased &&
//				(
//					this->event.key.code == sf::Keyboard::A ||
//					this->event.key.code == sf::Keyboard::D ||
//					this->event.key.code == sf::Keyboard::W ||
//					this->event.key.code == sf::Keyboard::S
//				)
//			)
//			this->player->animationTimer();
//	}
//	this->updatePlayer();
//	view.setCenter(player->getPosition());
//	view.setSize(sf::Vector2f(800.f, 600.f));
//}