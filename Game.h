#pragma once

#include "GameState.h"
#include "MainMenuState.h"
class Game
{
private:
    //variables
    sf::RenderWindow* renderWindow;
    sf::Event event;

    //delta time
    sf::Clock dtClock;
    float dt;

    std::map<std::string,int> supportedKeys;

    //states to handle menus
    std::stack<State*> states;

    //initializer
    void initWindow();
    void initState();
    void initKeys();
public:
    Game();
    ~Game();
    void updateDt();
    void updateSFMLevents();
    void update();
    void render();
    void run();
    void endApp();
};
