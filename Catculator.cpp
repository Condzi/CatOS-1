#include "Catculator.h"


Catculator::Catculator(sf::Event & eventPointer, sf::Font * font, sf::Texture * textureSheet) :Application(eventPointer)
{
	cutTextures(textureSheet);
	m_currentInput = new long double(0);
	m_font = font;
	m_lastActionButton = none;

	m_inputArea.setPosition(25.f, 25.f);
}

Catculator::~Catculator()
{
	delete m_currentInput;
	delete m_previousInput;
}

int Catculator::Call()
{
	return 0;
}

void Catculator::Update(const float & deltaTime)
{
}

void Catculator::checkEvents()
{
	m_lastActionButton = buttonPlus;
}

void Catculator::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Text input(std::to_string(*m_currentInput), *m_font, m_inputArea.getSize().y - m_inputArea.getSize().y / 10.f);
	sf::Text lastOperation(static_cast<char>(m_lastActionButton), *m_font, input.getCharacterSize() / 10);

	input.setPosition(m_inputArea.getPosition());
	lastOperation.setPosition(m_inputArea.getPosition().x + m_inputArea.getSize().x - lastOperation.getGlobalBounds().width,
		m_inputArea.getPosition().y + m_inputArea.getSize().y);

	for (const auto kv : m_sprites) 
	{
		target.draw(kv.second, states);
	}

	target.draw(m_inputArea, states);
	target.draw(input, states);
	target.draw(lastOperation, states);
}

void Catculator::cutTextures(sf::Texture * textureSheet)
{
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
	if (m_currentInput)
	{
		*m_currentInput = 0;
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
