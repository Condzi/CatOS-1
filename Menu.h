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
	Menu(sf::Event & eventPointer, sf::Texture & textureSheet, const sf::Vector2f & windowSize);
	~Menu();

	int Run();
	void Update(float&);

protected:
	void checkEvents();

private:
	std::vector<Button> m_buttons;
	sf::Sprite m_spriteLogo;
	sf::Sprite m_spriteBackground;
	sf::Texture * m_textureSheet;
};

