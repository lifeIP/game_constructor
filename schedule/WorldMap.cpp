#include "lib.h"

bool WorldMap::loadMap(const std::string& world_texture, sf::Vector2u texture_size, const int* tiles, const unsigned& width, const unsigned& height)
{

    // load the tileset texture
    if (!m_tileset.loadFromFile(world_texture))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / texture_size.x);
            int tv = tileNumber / (m_tileset.getSize().x / texture_size.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * texture_size.x, j * texture_size.y);
            quad[1].position = sf::Vector2f((i + 1) * texture_size.x, j * texture_size.y);
            quad[2].position = sf::Vector2f((i + 1) * texture_size.x, (j + 1) * texture_size.y);
            quad[3].position = sf::Vector2f(i * texture_size.x, (j + 1) * texture_size.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * texture_size.x, tv * texture_size.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * texture_size.x, tv * texture_size.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * texture_size.x, (tv + 1) * texture_size.y);
            quad[3].texCoords = sf::Vector2f(tu * texture_size.x, (tv + 1) * texture_size.y);
        }

    return true;
}

void WorldMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //apply the transform
    states.transform *= getTransform();

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}
