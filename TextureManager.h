#pragma once
#include "Application.h"


class TextureManager :
	public Application
{
private:
	bool loadFromFile(sf::String);
	void draw(sf::RenderTarget&, sf::RenderStates) const {};

public:
	TextureManager(sf::String & texturesFolder);
	~TextureManager();

	sf::Texture *GetTexture(int&);

	int Run();
	void Update(float&) {};

protected:
	void checkEvents() {};

private:
	std::vector<sf::Texture> m_textures;
	sf::String m_textureFolder;
};

