#pragma once

class WorldMap: public sf::Drawable, public sf::Transformable
{
public:
	bool loadMap(const std::string& world_texture, sf::Vector2u texture_size, const int* tiles, const unsigned& width, const unsigned& height);

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

