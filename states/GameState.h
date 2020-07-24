#pragma once

#include "State.h"
class GameState : public State
{
private:
    /* data */
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void endState();
};
