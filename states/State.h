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
    std::stack<State*>* states;

    //info about mouse position
    sf::Vector2i mouseToScreen;
    sf::Vector2i mouseToWindow;
    sf::Vector2f mouseToView;
    
    
public:
    State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
    ~State();


    bool getEnd();
    void endState();
    virtual void initKeyBinds() = 0;
    virtual void updateMousePositions();
    virtual void updateKeyBinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
