//
// Created by smatgaflen on 12/25/18.
//

#include <SFML/Graphics.hpp>
#include "Snake.hpp"

#ifndef GAME_TEMPLATE_WORLD_HPP
#define GAME_TEMPLATE_WORLD_HPP


class World{
public:
    World(sf::Vector2u l_windSize);
    ~World();
    int GetBlockSize();
    void RespawnApple();
    void Update(Snake& l_player);
    void Render(sf::RenderWindow& l_window);
private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;
    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};


#endif //GAME_TEMPLATE_WORLD_HPP
