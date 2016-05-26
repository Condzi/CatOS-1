#include "Menu.h"



void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spriteLogo);
	
	for (short i = 0; i < m_buttons.size(); i++)
	{
		target.draw(m_buttons[i]);
	}
}

Menu::Menu(sf::Event & eventPointer, sf::Vector2f & position, sf::Texture textureSheet) :Application(eventPointer)
{
	m_textureSheet = textureSheet;
	m_spriteLogo.setTextureRect(sf::IntRect(0, 0, 800, 800));
	m_spriteLogo.setOrigin(sf::Vector2f(m_spriteLogo.getGlobalBounds().width / 2, m_spriteLogo.getGlobalBounds().height / 2));
	m_spriteLogo.setPosition(position);

	//TODO: Loading buttons textures
}

Menu::~Menu() 
{
}

int Menu::Run()
{
	//return option (application) to run
	return 0;
}

void Menu::Update(float & fps)
{
	for (short i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].Update(fps);
	}
}

void Menu::checkEvents()
{
	//here check mouse position (if is on button, then selected)
}
