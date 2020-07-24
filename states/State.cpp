#include "State.h"

State::State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys){
    this->window = window;
    this->wantsEnd = false;
    this->supportedKeys = supportedKeys;
}

State::~State(){
    
}

void State::checkForEnd(){
    // find a condition to end the state
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("CLOSE"))))
    {
        this->wantsEnd = true;
    }
    
}

bool State::getEnd(){
    return this->wantsEnd;
}