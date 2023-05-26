module;

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#pragma warning(disable : 4996)

export module Menu;

#define MAX_NUMBER_OF_ITEMS 3

export class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

Menu::Menu(float width, float height)
{
	std::filesystem::path tmp{ std::filesystem::current_path() / "Font.ttf" };
	std::string fnt{ tmp.string() };
	if (!font.loadFromFile(fnt))
	{
		return;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("LEVEL 1");
	menu[0].setPosition(sf::Vector2f(width / 1.5, height -300));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("LEVEL 2");
	menu[1].setPosition(sf::Vector2f(width / 1.5, height -200));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 1.5, height -100));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}