#pragma once
#include "Application.h"


class TextureManager :
	public Application
{
private:
	bool loadFromFile(sf::String);

public:
	TextureManager(sf::String & texturesFolder);
	~TextureManager();

	int Run();
	
	virtual void Update() = 0;

protected:
	virtual void checkEvents() = 0;

private:
	std::vector<sf::Texture> m_textures;
	sf::String m_textureFolder;
};

