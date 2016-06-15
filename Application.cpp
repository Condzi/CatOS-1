#include "Application.h"


Application::Application(sf::Event & eventPointer)
{
	m_event = &eventPointer;
}

Application::Application(std::nullptr_t eventPointer)
{
	m_event = eventPointer;
}


Application::~Application()
{

}
