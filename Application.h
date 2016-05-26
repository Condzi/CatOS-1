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
	Application();
	~Application();

	virtual void Run() = 0; 
	virtual void Update(float) = 0;

protected:
	virtual void checkEvents(sf::Event&) = 0;
};

