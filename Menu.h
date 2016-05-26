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
	Menu(sf::Event & eventPointer, sf::Vector2f & position, sf::Texture & textureSheet);
	~Menu();

	int Run();
	void Update(float&);

protected:
	void checkEvents();

private:
	std::vector<Button> m_buttons;
	sf::Sprite m_spriteLogo;
	sf::Texture * m_textureSheet;
};

