#pragma once

#include "State.h"
class GameState : public State
{
protected:
    Entity player;
public:
    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys);
    ~GameState();
    void update(const float& dt);
    void updateKeyBinds(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void endState();
    void initKeyBinds();
};
