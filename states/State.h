#pragma once

#include "Entity.h"

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool wantsEnd;
public:
    State(sf::RenderWindow* window);
    ~State();


    bool getEnd();
    virtual void endState() = 0;
    void checkForEnd();

    virtual void updateKeyBinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
