//
// Created by smatgaflen on 12/24/18.
//

#include <SFML/Graphics.hpp>

#ifndef GAME_TEMPLATE_WINDOW_HPP
#define GAME_TEMPLATE_WINDOW_HPP


class Window {
public:
    Window();

    Window(const std::string &l_title, const sf::Vector2u &l_size);

    ~Window();

    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();

    bool IsDone();

    bool IsFullscreen();

    sf::Vector2u GetWindowSize();

    sf::RenderWindow* GetRenderWindow();

    void ToggleFullscreen();

    void Draw(sf::Drawable &l_drawable);

    void Setup(const std::string &l_title, const sf::Vector2u &l_size);
private:

    void Destroy();

    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};


#endif //GAME_TEMPLATE_WINDOW_HPP
