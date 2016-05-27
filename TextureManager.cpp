#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager(sf::String & texturesFolder) :Application(nullptr)
{
	m_textureFolder = texturesFolder;
}

bool TextureManager::loadFromFile(sf::String path)
{
	//possible issue with white textures, eh	
	sf::Texture * texture = new sf::Texture;
	
	if (texture->loadFromFile(path))
	{
		m_textures.push_back(*texture);

		return true;
	}

	return false;
}

TextureManager::~TextureManager()
{
}

sf::Texture * TextureManager::GetTexture(int id)
{
	if (id < 0 || id > m_textures.size())
	{
		return nullptr;
	}

	return &m_textures[id];
}

int TextureManager::Run()
{
	sf::String textureName;
	bool isSucces;
	
	textureName = "SpriteSheet.png";
	isSucces = loadFromFile(m_textureFolder + textureName);

	//textureName = "ButtonSheet.png";
	//isSucces = loadFromFile(textureName);

	if (isSucces)
	{
		return 0;
	}
	//else
	return 1;
}
