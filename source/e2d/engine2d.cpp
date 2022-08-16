#include "engine2d.h"

// static function

// initializer functions
void e2d::Engine2d::initWindow() {
    std::ifstream ifs("./config/window.ini");

    std::string title = "E2D";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void e2d::Engine2d::initStates() {
    this->states.push(new e2d::states::GameState(this->window));
}

// constructors/destructors
e2d::Engine2d::Engine2d() {
    this->initWindow();
    this->initStates();
}

e2d::Engine2d::~Engine2d() {
    delete this->window;

    while(!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}


void e2d::Engine2d::updateDt() {
    this ->dt = this->dtClock.restart().asSeconds();
}

void e2d::Engine2d::updateSfmlEvents() {
    while(this->window->pollEvent(this->sfEvent)) {
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void e2d::Engine2d::update() {
    this->updateSfmlEvents();

    if(!this->states.empty())
        this->states.top()->update(this->dt);
}

void e2d::Engine2d::render() {
    this->window->clear(sf::Color::Green);

    // render items
    if(!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void e2d::Engine2d::run() {
    while(this->window->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

