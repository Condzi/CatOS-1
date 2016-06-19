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
		none = 'n',
		buttonOne = '1',
		buttonTwo = '2',
		buttonThree = '3',
		buttonFour = '4',
		buttonFive = '5',
		buttonSix = '6',
		buttonSeven = '7',
		buttonEight = '8',
		buttonNinie = '9',
		buttonZero = '0',
		//"Action" buttons
		buttonPlus = '+',
		buttonMinus = '-',
		buttonTimes = '*',
		buttonDivide = ':',
	//	buttonEqual,			// = We don't need that :D (In this version)
		buttonClearAll = 'C'	// clears current input, second one cleans previous
	};

	std::map<buttonType, sf::Texture*> m_textures;
	std::map<buttonType, sf::Sprite> m_sprites;
	sf::Font * m_font;
	sf::RectangleShape m_inputArea;
	buttonType m_lastActionButton;
	long double * m_currentInput;
	long double * m_previousInput;
	
};

