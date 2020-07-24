#pragma once

#include "Entity.h"

class State
{
private:
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool wantsEnd;
    std::map<std::string,int>* supportedKeys;
    std::map<std::string,int> keybind;
public:
    State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys);
    ~State();


    bool getEnd();
    virtual void endState() = 0;
    void checkForEnd();
    virtual void initKeyBinds() = 0;

    virtual void updateKeyBinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
