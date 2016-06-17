#pragma once
#include "Application.h"


class TextureManager :
	public Application
{
private:
	/// Loads from file
	/// <param name="filePath"> path to file </param>
	/// <returns> true if loaded </returns>
	/// <returns> false if not loaded </returns>
	bool loadFromFile(const std::string & filePath);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	/// TextureManager constructor
	/// <param name="texturesFolder"> textures folder with '/' at end </param>
	TextureManager(const std::string & texturesFolder);
	~TextureManager();
	
	/// Texture pointer getter
	/// <param name=id> texture id </param>
	/// <returns> texture </returns>
	/// <returns> nullptr if cannot get texture </returns>
	sf::Texture * GetTexture(const int & id);
	
	/// Starts Application
	/// <returns> Application's exit code </returns>
	int Call() final;
	/// Updates Application
	/// <param name="deltaTime"> delta time (frames per second) </param>
	void Update(const float & deltaTime) final;

protected:
	/// Event handler
	void checkEvents() final;

private:
	std::vector<sf::Texture*> m_textures;
	std::string m_textureFolder;

};

