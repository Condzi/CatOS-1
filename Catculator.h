#pragma once
#include <vector>

#include "Application.h"


class Catculator :
	public Application
{
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	/// Cuts texture sheet for buttons etc
	/// <param name="textureSheet"> texture sheet pointer </param>
	void cutTextures(sf::Texture * textureSheet);
	
	void operationAdd();
	void operationSubtract();
	void operationMultiply();
	void operationDivide();
	void operationClear();

	bool isPreviousInput();

public:
	/// Catculator constructor
	/// <param name="eventPointer"> pointer to window events handler </param>
	/// <paran name="fontPointer"> pointer to font </param>
	/// <param name="textureSheet"> reference to texture sheet from textureManager </param>
	Catculator(sf::Event & eventPointer, sf::Font * font, sf::Texture * textureSheet);
	~Catculator();
	
	int Call() final;
	void Update(const float & deltaTime) final;

protected:
	/// Event handler
	void checkEvents() final;

private:
	enum buttonType
	{
		none,
		buttonOne,
		buttonTwo,
		buttonThree,
		buttonFour,
		buttonFive,
		buttonSix,
		buttonSeven,
		buttonEight,
		buttonNinie,
		buttonZero,
		buttonPlus,		// +
		buttonMinus,	// -
		buttonTimes,	// *
		buttonDivide,	// :
	//	buttonEqual,	// = We don't need that :D (In this version)
		buttonClearAll	// C One time - clears current input, second one cleans previous
	};

	std::map<buttonType, sf::Texture*> m_textures;
	std::map<buttonType, sf::Sprite> m_sprites;
	sf::Font * m_font;
	sf::RectangleShape m_inputArea;
	long double * m_currentInput;
	long double * m_previousInput;

};

