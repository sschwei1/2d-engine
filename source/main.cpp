#include <SFML/Graphics.hpp>
#include <fstream>

int main() {
    // default settings
    std::string window_title = "Hello World!";
    sf::VideoMode window_bounds(200, 200);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = true;

    // read config
    std::ifstream ifs("config/window.ini");
    if(ifs.is_open()){
        std::getline(ifs, window_title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    ifs.close();

    // initialise window
    auto window = new sf::RenderWindow(window_bounds, window_title);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(vertical_sync_enabled);

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