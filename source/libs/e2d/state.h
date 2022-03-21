#ifndef INC_2D_ENGINE_STATE_H
#define INC_2D_ENGINE_STATE_H

#include <SFML/Graphics.hpp>
#include <stack>

namespace e2d {
    class State {
    public:
        State(sf::RenderWindow *window, std::stack<State*>* states, std::map<std::string, sf::Keyboard::Key> *supportedKeys, State *prevState);
        virtual ~State();

    protected:
        // props passed down from engine
        sf::RenderTarget *window;
        std::stack<State*> *states;
        std::map<std::string, sf::Keyboard::Key> *supportedKeys;
        State *prevState;

        //
        bool quit;
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::map<std::string, sf::Keyboard::Key> keyBinds;
        std::vector<sf::Texture> textures;

        virtual void initKeyBinds() = 0;
    };
}


#endif //INC_2D_ENGINE_STATE_H
