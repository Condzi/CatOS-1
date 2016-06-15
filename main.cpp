#include <iostream>

#include "Cat.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


int main()
{
	sf::Clock startupClock;
	Cat cat(725, 725, "CatOS 1 | 1");

	cat.Init("Data/");
	// in future: save it to .cat file for "statistics" or something
	std::cout << "Boot time: " << startupClock.restart().asSeconds() << "\n";
	cat.Run();

	return 0;
}
