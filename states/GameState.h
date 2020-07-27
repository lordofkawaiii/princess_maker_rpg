#pragma once

#include "State.h"
#include "Player.h"

class GameState : public State
{
private:
    void initKeyBinds();
protected:
    Player* player;
    sf::RectangleShape background;
public:
    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
    ~GameState();
    
    void update(const float& dt);
    void updateKeyBinds(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void initTextures();
    void initPlayer();
};
