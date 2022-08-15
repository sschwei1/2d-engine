#ifndef INC_2D_ENGINE_ENGINE2D_H
#define INC_2D_ENGINE_ENGINE2D_H

#include "state.h"

namespace e2d {
    // rendering and logic updates will be moved to states in later stages
    class Engine2d {
    private:
        // variables
        sf::RenderWindow *window;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        // initialization
        void initWindow();


    public:
        // constructors/destructors
        Engine2d();
        virtual ~Engine2d();

        // functions
        void updateDt();
        void updateSfmlEvents();
        void update();
        void render();
        void run();
    };
}



#endif //INC_2D_ENGINE_ENGINE2D_H
