#include "engine2d.h"

e2d::Engine2d::Engine2d() {
    this->initKeymap();
    this->initStates();
    this->initWindow();

    this->dt = 0;
}

e2d::Engine2d::~Engine2d() {
    delete this->window;

    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}

void e2d::Engine2d::run() {
    while (this->window->isOpen()){
        this->engineUpdateDt();
        this->engineUpdateSfmlEvents();
        this->engineUpdate();
        this->engineRender();
    }
}

void e2d::Engine2d::engineUpdateDt() {
    this->dt = this->dtClock.restart().asSeconds();
}

void e2d::Engine2d::engineUpdateSfmlEvents() {
    while (this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed){
            this->window->close();
        }
    }
}

void e2d::Engine2d::engineUpdate() {
    if(!this->states.empty()){

    }
}

void e2d::Engine2d::engineRender() {
    this->window->clear(sf::Color::Green);

    if(!this->states.empty()) {
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void e2d::Engine2d::engineEnd() {

}

void e2d::Engine2d::initWindow() {
    // default settings
    std::string window_title = "2D-Engine by sschwei1!";
    sf::VideoMode window_bounds(800, 600);
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

    this->window = new sf::RenderWindow(window_bounds, window_title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void e2d::Engine2d::initKeymap() {
    // skipped for now
}

void e2d::Engine2d::initStates() {
    // skipped for now
}
