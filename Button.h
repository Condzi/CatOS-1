#pragma once
#include <SFML\Graphics.hpp>


class Button :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	Button(sf::Vector2f & position, sf::Texture texture);
	~Button();

	sf::FloatRect GetSpritePartOneRect();
	sf::FloatRect GetSpritePartTwoRect();
	bool IsSelected();
	bool IsClicked();

	void SetIsSelected(bool);
	void SetIsClicked(bool);

	void Update(float);
	virtual void Action() = 0;

protected:
	void animation();

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

