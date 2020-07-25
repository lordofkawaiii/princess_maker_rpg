#pragma once

#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
private:
    void initKeyBinds();
    //functions
    void initFont();
protected:
    sf::Font font;
public:
    MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys);
    ~MainMenuState();
    void update(const float& dt);
    void updateKeyBinds(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void endState();
};

