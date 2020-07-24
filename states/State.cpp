#include "State.h"

State::State(sf::RenderWindow* window){
    this->window = window;
    this->wantsEnd = false;
}

State::~State(){
    
}

void State::checkForEnd(){
    // find a condition to end the state
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->wantsEnd = true;
    } */
    
}

bool State::getEnd(){
    return this->wantsEnd;
}