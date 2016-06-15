/*
	Note: 
	I'm not sure that bool and float references
	are good.
	But performence += 0.0001.
*/

#pragma once
#include <SFML\Graphics.hpp>


class Button :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	/// Button constructor
	/// <param name="position"> button position (upper-left corner) </param>
	/// <param name="textureOne"> texture when is not selected </param>
	/// <param name="textureTwo"> texture when selected, "animated" to textureOne </param>
	/// <param name="animationDuration"> animation duration in seconds </param>
	Button(sf::Vector2f & position, sf::Texture & textureOne, sf::Texture & textureTwo, sf::Time animationDuration);
	~Button();

	/// Sprite One (texture one) collision rectangle
	/// <returns> texture one collision rectangle </returns>
	sf::FloatRect GetSpritePartOneRect();
	/// Sprite Two (texture two) collision rectangle
	/// <returns> texture two collision rectangle </returns>
	sf::FloatRect GetSpritePartTwoRect();
	/// Is button selected
	/// <returns> true when button is selected </returns>
	/// <returns> false when button is not selected </returns>
	bool IsSelected();
	/// Is button clicked
	/// <returns> true when button is clicked </returns>
	/// <returns> false when button is not clicked </returns>
	bool IsClicked();

	/// Sets Button selected
	/// <param name="val"> true or false </param>
	void SetIsSelected(bool & val);
	/// Sets Button clicked
	/// <param name="val"> true or false </param>
	void SetIsClicked(bool & val);
	/// Updates Application
	/// <param name="deltaTime"> delta time (frames per second) </param>
	void Update(const float & deltaTime);
	virtual void Action() = 0;

protected:
	/// Button animation when is selected
	/// <param name="deltaTime"> delta time (frames per second) </param>
	void animation(const float & deltaTime);

private:
	sf::Sprite m_spritePartOne;
	sf::Sprite m_spritePartTwo;
	sf::Texture * m_texturePartOne;
	sf::Texture * m_texturePartTwo;
	bool m_isSelected;
	bool m_isClicked;
	sf::Time m_animationDuration;
	sf::Clock m_animationClock;

};

