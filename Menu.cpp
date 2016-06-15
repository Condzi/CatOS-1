#include "Menu.h"

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spriteBackground);
	target.draw(m_spriteLogo);
	
	for (short i = 0; i < m_buttons.size(); ++i)
	{
		target.draw(m_buttons[i]);
	}
}

Menu::Menu(sf::Event & eventPointer, sf::Texture & textureSheet, sf::Vector2f & windowSize) :Application(eventPointer)
{
	m_textureSheet = &textureSheet;
	m_textureSheet->setSmooth(true);
	
	m_spriteLogo.setTexture(textureSheet);
	m_spriteLogo.setTextureRect(sf::IntRect(0, 1081, 410, 370));
	m_spriteLogo.setOrigin(m_spriteLogo.getGlobalBounds().width / 2, m_spriteLogo.getGlobalBounds().height / 2);
	m_spriteLogo.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
	m_spriteLogo.setScale(sf::Vector2f(windowSize.x / 2000, windowSize.y / 2000));
	
	m_spriteBackground.setTexture(*m_textureSheet);
	m_spriteBackground.setTextureRect(sf::IntRect(300, 1, windowSize.x, windowSize.y));
	//TODO: Loading everything
}

Menu::~Menu() 
{
}

int Menu::Call()
{
	for (short i = 0; i < m_buttons.size(); ++i)
	{
		if (m_buttons[i].IsClicked())
		{
			//+2 cause 0 - textureManager, 1 - menu
			return i + 2;
		}
	}
	return -1;
}

void Menu::Update(const float & fps)
{
	for (short i = 0; i < m_buttons.size(); ++i)
	{
		m_buttons[i].Update(fps);
	}
}

void Menu::checkEvents()
{
	// here check mouse position (if is on button, then selected)
	// also is button clicked (if is on button and LMB clicked)
}
