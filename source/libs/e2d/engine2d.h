#ifndef INC_2D_ENGINE_ENGINE2D_H
#define INC_2D_ENGINE_ENGINE2D_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <stack>
#include <iostream>
#include <fstream>
#include "state.h"

namespace e2d {
    // rendering and logic updates will be moved to states in later stages
    class Engine2d {
    public:
        Engine2d();
        virtual ~Engine2d();

        void run();

    private:
        // engine related things which can't be changed by a user
        void engineUpdateDt();
        void engineUpdateSfmlEvents();
        void engineUpdate();
        void engineRender();
        void engineEnd();


        // init functions
        void initWindow();
        void initKeymap();
        void initStates();

    protected:
        std::map<std::string, sf::Keyboard::Key> supportedKey;
        std::stack<State*> states;

        sf::RenderWindow *window;
        sf::Event sfEvent;
        sf::Clock dtClock;
        float dt;
    };
}



#endif //INC_2D_ENGINE_ENGINE2D_H
