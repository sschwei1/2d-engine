//
// Created by sswe on 15/08/2022.
//

#ifndef INC_2D_ENGINE_STATE_H
#define INC_2D_ENGINE_STATE_H


#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


namespace e2d {
    class State {
    private:
        sf::RenderWindow* window;
        std::vector<sf::Texture> textures;
        bool quit;

    public:
        State(sf::RenderWindow* window);
        virtual ~State();

        const bool& getQuit() const;

        virtual void checkForQuit();

        virtual void endState() = 0;
        virtual void updateKeybinds(const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target) = 0;
    };
}


#endif //INC_2D_ENGINE_STATE_H
