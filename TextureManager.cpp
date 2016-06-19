#include <iostream>

#include "TextureManager.h"


TextureManager::TextureManager(const std::string & texturesFolder) :Application(nullptr)
{
	m_textureFolder = texturesFolder;
}

bool TextureManager::loadFromFile(const std::string & filePath)
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
	return;
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
	const short texturesCount = 2;
	std::string texturesPath[texturesCount] =
	{
		"SpriteSheet.png",
		"CatculatorSheet.png"
	};	
	
	for (short i = 0; i < texturesCount; ++i)
	{
		if (!loadFromFile(m_textureFolder + texturesPath[i]))
		{
			return 1;
		}
	}

	return 0;
}

void TextureManager::Update(const float & deltaTime)
{
	// nothing to do here...
	return;
}

void TextureManager::checkEvents()
{
	// nothing to do here...
	return;
}
