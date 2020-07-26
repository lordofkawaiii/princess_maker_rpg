#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"

class MainMenuState : public State
{
private:
    //functions
    void initKeyBinds();
    void initFont();
protected:
    sf::Texture bgTexture;
    sf::RectangleShape background;
    sf::Font font;
    std::map<std::string,Button*> buttons;
    std::vector<std::string> button_order;
public:
    MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
    ~MainMenuState();
    void update(const float& dt);
    void updateKeyBinds(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void addButton(float x,float y, float width, float height,
            std::string text,sf::Font* font,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    void setBackground();
    void updateButtons();
};

