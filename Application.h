#pragma once
#include <SFML\Graphics.hpp>

/*
	NOTE: 
	void draw(...) const; - write in kids
*/

class Application :
	public sf::Drawable
{
public:
	Application(sf::Event & eventPointer);
	~Application();

	virtual int Run() = 0; 
	virtual void Update(float&) = 0;

protected:
	virtual void checkEvents() = 0;

protected:
	sf::Event * m_event;
};

