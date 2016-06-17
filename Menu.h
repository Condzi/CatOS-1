#pragma once
#include <vector>

#include "Application.h"
#include "Button.h"


class Menu :
	public Application
{
private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	/// Menu constructor
	/// <param name="eventPointer"> pointer to window events handler </param>
	/// <param name="textureSheet"> texture sheet for menu stuff (icons etc) </param>
	/// <param name="windowSize> window size (original window size) </param>
	Menu(sf::Event & eventPointer, sf::Texture & textureSheet, sf::Vector2f & windowSize);
	~Menu();

	int Call() final;
	void Update(const float & deltaTime) final;

protected:
	void checkEvents() final;

private:
	sf::Sprite m_spriteLogo;
	sf::Sprite m_spriteBackground;
	sf::Texture * m_textureSheet;
	std::vector<Button> m_buttons;

};

