//
// Created by sswe on 15/08/2022.
//

#ifndef INC_2D_ENGINE_STATE_H
#define INC_2D_ENGINE_STATE_H


#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


namespace e2d {
    class State {
    private:
        std::vector<sf::Texture> textures;


    public:
        State();
        virtual ~State();

        virtual void update() = 0;
        virtual void render() = 0;
    };
}


#endif //INC_2D_ENGINE_STATE_H
