#include <SFML/Graphics.hpp>
#include "libs/e2d/engine2d.h"

int main() {
    auto engine = new e2d::Engine2d();

    engine->run();

    return 0;
}