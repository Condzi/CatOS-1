#include "Application.h"



Application::Application(sf::Event & eventPointer)
{
	m_event = &eventPointer;
}

Application::Application(std::nullptr_t ptr)
{
	m_event = ptr;
}


Application::~Application()
{
}
