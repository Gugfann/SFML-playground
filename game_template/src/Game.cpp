//
// Created by smatgaflen on 12/24/18.
//

#include "../include/Game.hpp"

//Game::Game(): m_window("Chapter 2", sf::Vector2u(800,600)){
//// Setting up class members.
//    m_mushroomTexture.loadFromFile("../Mushroom.png");
//    m_mushroom.setTexture(m_mushroomTexture);
//    m_increment = sf::Vector2i(400,400); // 400px a second.
//}

Game::Game():
        m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800,600))
{}

void Game::Update(){
    float timestep = 1.0f / m_snake.GetSpeed();
    float dt = (m_elapsed - m_timestamp).asSeconds();
    if(dt >= timestep){
        m_snake.Tick();
        m_world.Update(m_snake);
        m_timestamp = m_elapsed;
        if(m_snake.HasLost()){
            m_snake.Reset();
        }
    }

    m_window.Update(); // Update window events.
//    MoveMushroom();
}

void Game::HandleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::MoveMushroom(){
    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textSize = m_mushroomTexture.getSize();
    if((m_mushroom.getPosition().x  > l_windSize.x - l_textSize.x&&m_increment.x> 0) ||
       (m_mushroom.getPosition().x < 0 &&m_increment.x< 0)){
        m_increment.x = -m_increment.x;
    }
    if((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y&&m_increment.y> 0) ||
       (m_mushroom.getPosition().y < 0 &&m_increment.y< 0)){
        m_increment.y = -m_increment.y;
    }

//    float fElapsed = m_elapsed.asSeconds();

//    m_mushroom.setPosition(
//            m_mushroom.getPosition().x + (m_increment.x * fElapsed),
//            m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render(){
//    m_window.BeginDraw(); // Clear.
//
//    m_window.Draw(m_mushroom);
//    m_window.EndDraw(); // Display.
    m_window.BeginDraw();
// Render here.
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

sf::Time Game::GetElapsed(){ return m_clock.getElapsedTime(); }

void Game::RestartClock(){ m_elapsed += m_clock.restart(); }

Window* Game::GetWindow(){
    return &m_window;
}

Game::~Game(){}