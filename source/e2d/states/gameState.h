//
// Created by sswe on 16/08/2022.
//

#ifndef INC_2D_ENGINE_GAMESTATE_H
#define INC_2D_ENGINE_GAMESTATE_H

#include "state.h"

namespace e2d::states {
    class GameState : public e2d::State {
    private:


    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        // functions
        void endState();
        void updateKeybinds(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
    };
}


#endif //INC_2D_ENGINE_GAMESTATE_H
