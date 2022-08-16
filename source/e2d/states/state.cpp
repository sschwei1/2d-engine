//
// Created by sswe on 15/08/2022.
//

#include "state.h"

namespace e2d {

    State::State(sf::RenderWindow *window) {
        this->window = window;
        this->quit = false;
    }

    State::~State() {

    }

    const bool& State::getQuit() const {
        return this->quit;
    }

    void State::checkForQuit() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->quit = true;
        }
    }
}