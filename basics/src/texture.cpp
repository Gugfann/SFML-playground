#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing swirly thing.");
    sf::Texture swirl_texture;
    swirl_texture.loadFromFile("../Goal.png");
    sf::Sprite swirl(swirl_texture);
    sf::Vector2u size = swirl_texture.getSize();
    swirl.setPosition(320,240);
    swirl.setOrigin(size.x / 2, size.y / 2);
    sf::Vector2f increment(0.04f, 0.08f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if ((swirl.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) ||
            (swirl.getPosition().x - (size.x / 2) < 0 && increment.x < 0)) {
// Reverse the direction on X axis.
            increment.x = -increment.x;
        }
        if ((swirl.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) ||
            (swirl.getPosition().y - (size.y / 2) < 0 && increment.y < 0)) {// Reverse the direction on Y axis.
            increment.y = -increment.y;
        }
        swirl.setPosition(swirl.getPosition() + increment);
        window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
        window.draw(swirl); // Drawing our sprite.
        window.display();
    }

    return 0;
}