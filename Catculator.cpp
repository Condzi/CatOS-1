#include "Catculator.h"


Catculator::Catculator(sf::Event & eventPointer, sf::Font * font, sf::Texture * textureSheet) :Application(eventPointer)
{
	cutTextures(textureSheet);
	m_currentInput = new long double(0);
	m_font = font;
}

Catculator::~Catculator()
{
	delete m_currentInput;
	delete m_previousInput;
}

void Catculator::operationAdd()
{
	if (!isPreviousInput())
	{
		return;
	}
	
	long double temp;
	temp = *m_currentInput;

	*m_currentInput = *m_previousInput + *m_currentInput;
	*m_previousInput = temp;
}

void Catculator::operationSubtract()
{
	if (!isPreviousInput())
	{
		return;
	}
	
	long double temp;
	temp = *m_currentInput;

	*m_currentInput = *m_previousInput - *m_currentInput;
	*m_previousInput = temp;
}

void Catculator::operationMultiply()
{
	if (!isPreviousInput())
	{
		return;
	}	
	
	long double temp;
	temp = *m_currentInput;

	*m_currentInput = *m_previousInput * *m_currentInput;
	*m_previousInput = temp;
}

void Catculator::operationDivide()
{
	if (!isPreviousInput())
	{
		return;
	}

	long double temp;
	temp = *m_currentInput;

	*m_currentInput = *m_previousInput / *m_currentInput;
	*m_previousInput = temp;
}

void Catculator::operationClear()
{
	if (m_currentInput != nullptr)
	{
		delete m_currentInput;
		return;
	}

	if (!isPreviousInput())
	{
		delete m_previousInput;
	}
}

bool Catculator::isPreviousInput()
{
	return(m_previousInput == nullptr?true:false);
}
