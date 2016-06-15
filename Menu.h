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

	/// Starts Application
	/// <returns> Application's exit code </returns>
	int Call();
	/// Updates Application
	/// <param name="deltaTime"> delta time (frames per second) </param>
	void Update(const float & deltaTime);

protected:
	/// Event handler
	void checkEvents();

private:
	std::vector<Button> m_buttons;
	sf::Sprite m_spriteLogo;
	sf::Sprite m_spriteBackground;
	sf::Texture * m_textureSheet;
};

