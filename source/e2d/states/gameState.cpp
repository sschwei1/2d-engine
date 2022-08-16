//
// Created by sswe on 16/08/2022.
//

#include "gameState.h"

namespace e2d::states {

    GameState::GameState(sf::RenderWindow* window) : e2d::State(window) {

    }

    GameState::~GameState() {

    }

    void GameState::endState() {
        std::cout << "end gameState\n";
    }

    void GameState::updateKeybinds(const float &dt) {
        this->checkForQuit();
    }

    void GameState::update(const float& dt) {
        this->updateKeybinds(dt);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            std::cout << "A is pressed!\n";
    }

    void GameState::render(sf::RenderTarget* target) {

    }
}