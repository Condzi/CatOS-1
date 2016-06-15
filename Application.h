/*
	NOTE: 
	void draw(...) const; - write in kids
*/

#pragma once
#include <SFML\Graphics.hpp>


class Application :
	public sf::Drawable
{
public:
	/// Application constructor
	/// <param name="eventPointer"> pointer to window events handler </param>
	Application(sf::Event & eventPointer);
	/// Application constructor
	/// <param name="eventPointer"> null pointer (if you don't need event handling) </param>
	Application(std::nullptr_t eventPointer);
	~Application();

	/// Calls application one time per Cat::Run() loop circuit to check is everything ok
	/// <returns> Application's exit code </returns>
	virtual int Call() = 0; 
	/// Updates Application (for animations etc)
	/// <param name="deltaTime"> delta time (frames per second) </param>
	virtual void Update(const float & deltaTime) = 0;

protected:
	/// Event handler
	virtual void checkEvents() = 0;

protected:
	sf::Event * m_event;

};

