#pragma once

#include "State.h"
class GameState : public State
{
private:
    void initKeyBinds();
protected:
    Entity player;
public:
    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
    ~GameState();
    void update(const float& dt);
    void updateKeyBinds(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
