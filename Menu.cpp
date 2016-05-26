#include "Menu.h"

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spriteLogo);
	
	for (short i = 0; i < m_buttons.size(); i++)
	{
		target.draw(m_buttons[i]);
	}
}

Menu::Menu(sf::Event & eventPointer, sf::Vector2f & position, sf::Texture & textureSheet) :Application(eventPointer)
{
	//this should be different
	m_textureSheet = &textureSheet;
	m_spriteLogo.setTexture(*m_textureSheet);
	//TODO: Loading everything
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
