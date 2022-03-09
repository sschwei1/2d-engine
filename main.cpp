#include <SFML/Graphics.hpp>

int main() {
    sf::VideoMode window_bounds(800, 600);
    std::string window_title = "Hello World!";
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = true;

    auto window = new sf::RenderWindow(window_bounds, window_title);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(vertical_sync_enabled);

    sf::RectangleShape background(sf::Vector2f(window_bounds.height, window_bounds.width));
    background.setFillColor(sf::Color::Green);

    sf::Event sfEvent;

    while(window->isOpen()) {
        // handle sfml events
        while (window->pollEvent(sfEvent)){
            if(sfEvent.type == sf::Event::Closed){
                window->close();
            }
        }

        // update logic

        // render
        window->clear(sf::Color::Green);
        window->display();
    }

    // memory cleanup
    delete window;

    return 0;
}