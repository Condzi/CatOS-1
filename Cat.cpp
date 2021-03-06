#include <iostream>

#include "Cat.h"


void Cat::draw()
{
	m_window.clear();

	m_window.draw(*m_applications[m_currentApplication]);

	m_window.display();
}

void Cat::checkEvents()
{
	if (m_event.type == sf::Event::Closed)
	{
		m_window.close();
	}
}

void Cat::update(const float & deltaTime)
{
	m_applications[m_currentApplication]->Update(deltaTime);
}

Cat::Cat(int width, int height, const std::string & title)
{
	m_window.create(sf::VideoMode(width, height), title, sf::Style::Close);
	m_window.setFramerateLimit(120);
}

Cat::~Cat()
{
}

void Cat::Init(const std::string & texturesFolder)
{
	TextureManager * textureManager;
	Menu * menu;
	textureManager = new TextureManager(texturesFolder);
	
	m_applications.push_back(textureManager);
	
	// texture manager boot
	m_currentApplication = 0;
	if (m_applications[m_currentApplication]->Call())
	{
		exit(1);
	}

	menu = new Menu(m_event, *textureManager->GetTexture(0), sf::Vector2f(m_window.getSize()));
	m_applications.push_back(menu);

	// menu
	m_currentApplication = 1;
}

void Cat::Run()
{
	sf::Clock fpsclock;
	short newCurrentApplication;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			checkEvents();
		}

		//menu returns application ID - other applications returns menu ID
		newCurrentApplication = m_applications[m_currentApplication]->Call();

		if (newCurrentApplication >= 2 && newCurrentApplication <= 6)
		{
			m_currentApplication = newCurrentApplication;
		}

		update(fpsclock.getElapsedTime().asSeconds());
		draw();

		fpsclock.restart();
	}
}
