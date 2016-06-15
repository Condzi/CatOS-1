#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager(const sf::String & texturesFolder) :Application(nullptr)
{
	m_textureFolder = texturesFolder;
}

bool TextureManager::loadFromFile(const sf::String & filePath)
{
	sf::Texture * texture = new sf::Texture;
	
	if (texture->loadFromFile(filePath))
	{
		m_textures.push_back(texture);

		return true;
	}

	delete texture;
	return false;
}

void TextureManager::draw(sf::RenderTarget &, sf::RenderStates) const
{
	// probably some boot texture here / information in console or simply nothing
}

TextureManager::~TextureManager()
{
	for (short i = 0; i < m_textures.size(); ++i)
	{
		delete m_textures[i];
	}
}

sf::Texture * TextureManager::GetTexture(const int & id)
{
	if (id < 0 || id > m_textures.size())
	{
		return nullptr;
	}

	return m_textures[id];
}

int TextureManager::Call()
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

	return 1;
}

void TextureManager::Update(const float & deltaTime)
{
	// nothing to do here...
}

void TextureManager::checkEvents()
{
	// nothing to do here...
}
