#pragma once
#include "Menu.h"
#include "TextureManager.h"


class Cat
{
private:
	void draw();
	void checkEvents();
	void update(float);

public:
	Cat(int width, int heigth, sf::String title);
	~Cat();

	void Init(sf::String texturesFolder);
	void Run();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	std::vector<Application*> m_applications;
	//0 - txtureManager, 1 - menu, 2 - calculator, 3-paint, 4-notepad
	short m_currentApplication;
};

