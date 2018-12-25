//
// Created by smatgaflen on 12/24/18.
//

#include "Window.hpp"
#include "Snake.hpp"
#include "World.hpp"

#ifndef GAME_TEMPLATE_GAME_HPP
#define GAME_TEMPLATE_GAME_HPP


class Game{
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    sf::Time GetElapsed();
    void RestartClock();
    Window* GetWindow();
private:
    void MoveMushroom();
    Window m_window;

    World m_world;
    Snake m_snake;

    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2i m_increment;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    sf::Time m_timestamp;
};


#endif //GAME_TEMPLATE_GAME_HPP
