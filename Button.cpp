#include "Button.h"



void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spritePartOne, states);
	target.draw(m_spritePartTwo, states);
}

Button::Button(sf::Vector2f & position, sf::Texture texture)
{
	m_spritePartOne.setPosition(position);
	m_spritePartOne.setTexture()
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

void Button::SetIsSelected(bool value)
{
	m_isSelected = value;
}

void Button::SetIsClicked(bool value)
{
	m_isClicked = value;
}

void Button::Update(float fps)
{
	if (m_isSelected)
	{
		animation();
	}

	if (m_isClicked)
	{
		Action();
	}
}
