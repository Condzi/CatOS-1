#pragma once
#include "Menu.h"
#include "TextureManager.h"


class Cat
{
private:
	/// Draws everything on screen
	void draw();
	/// Event loop for Apps
	void checkEvents();
	/// Updates everything
	void update(const float & deltaTime);

public:
	/// CatOS constructor
	/// <param name="width"> screen width </param>
	/// <param name="height"> screen height </param>
	/// <param name="title"> window title </param>
	Cat(int width, int heigth, sf::String title);
	~Cat();

	/// CatOS initialization process (in real systems is boot, i think)
	/// <param name="texturesFolder"> textures folder for system with "/" at end </param>
	void Init(const sf::String & texturesFolder);
	/// Starts 'system'
	void Run();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	std::vector<Application*> m_applications;
	//0 -	textureManager (boot), 
	//1 -	menu (system GUI),  
	//2 -	calculator,
	//3	-	paint, 
	//4	-	notepad
	short m_currentApplication;
};

