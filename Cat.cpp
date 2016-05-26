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

void Cat::update(float fps)
{
	m_applications[m_currentApplication]->Update(fps);
}

Cat::Cat(int width, int height, sf::String title)
{
	m_window.create(sf::VideoMode(width, height), title, sf::Style::Close);
	m_currentApplication = 0;
}

Cat::~Cat()
{
}

void Cat::Init(sf::String texturesFolder)
{
	TextureManager * textureManager = new TextureManager(texturesFolder);
	m_applications.push_back(textureManager);
	
	Menu * menu = new Menu(m_event, sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2), *textureManager->GetTexture(int(1)));
	m_applications.push_back(menu);
}

void Cat::Run()
{
	sf::Clock fpsclock;
	sf::Time fps;
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			checkEvents();
		}

		update(fps.asSeconds());
		draw();

		fps = fpsclock.getElapsedTime();
		fpsclock.restart();
	}
}
