#pragma once
#include <SFML\Graphics.hpp>

/*
	Note: 
	I'm not sure that bool and float references
	are good.
	But performence += 0.0001.
*/

class Button :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	Button(sf::Vector2f & position, sf::Texture & textureOne, sf::Texture & textureTwo);
	~Button();

	sf::FloatRect GetSpritePartOneRect();
	sf::FloatRect GetSpritePartTwoRect();
	bool IsSelected();
	bool IsClicked();

	void SetIsSelected(bool&);
	void SetIsClicked(bool&);

	void Update(float&);
	virtual void Action() = 0;

protected:
	void animation(float&);

private:
	sf::Sprite m_spritePartOne;
	sf::Sprite m_spritePartTwo;
	sf::Texture m_texturePartOne;
	sf::Texture m_texturePartTwo;
	bool m_isSelected;
	bool m_isClicked;
	sf::Time m_animationDuration;
	sf::Clock m_animationClock;

};

