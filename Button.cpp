#include "Button.h"


void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spritePartOne, states);
	target.draw(m_spritePartTwo, states);
}

Button::Button(float positionX, float positionY, sf::Texture & textureOne, sf::Texture & textureTwo, sf::Time animationDuration)
{
	m_spritePartOne.setPosition(positionX, positionY);
	m_spritePartTwo.setPosition(sf::Vector2f(-200, 0));

	m_texturePartOne = &textureOne;
	m_texturePartTwo = &textureTwo;
	m_spritePartOne.setTexture(*m_texturePartOne);
	m_spritePartTwo.setTexture(*m_texturePartTwo);

	m_animationDuration = animationDuration;
}

Button::~Button()
{
}

sf::FloatRect Button::GetSpritePartOneRect()
{
	return m_spritePartOne.getGlobalBounds();
}

sf::FloatRect Button::GetSpritePartTwoRect()
{
	return m_spritePartTwo.getGlobalBounds();
}

bool Button::IsSelected()
{
	return m_isSelected;
}

bool Button::IsClicked()
{
	return m_isClicked;
}

void Button::SetIsSelected(bool & val)
{
	m_isSelected = val;
}

void Button::SetIsClicked(bool & val)
{
	m_isClicked = val;
}

void Button::Update(const float & deltaTime)
{
	if (m_isSelected)
	{
		animation(deltaTime);
	}

	if (m_isClicked)
	{
		Action();
	}
}

void Button::animation(const float & deltaTime)
{
	// TODO: figure out how to do that animation
}
