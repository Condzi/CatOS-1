#include "TextureManager.h"



TextureManager::TextureManager(sf::String & texturesFolder) :Application(nullptr)
{
	m_textureFolder = texturesFolder;
}

bool TextureManager::loadFromFile(sf::String path)
{
	//possible issue with white textures, eh	
	sf::Texture texture;
	
	if (texture.loadFromFile(path))
	{
		m_textures.push_back(texture);

		return true;
	}
	
	return false;
}

TextureManager::~TextureManager()
{
}

sf::Texture * TextureManager::GetTexture(int & id)
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
	bool succes;
	
	textureName = "CatOS1Logo.png";
	succes = loadFromFile(textureName);

	textureName = "ButtonSheet.png";
	succes = loadFromFile(textureName);

	if (succes)
	{
		return 0;
	}
	//else
	return 1;
}
