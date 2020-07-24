#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}
GameState::~GameState(){

}
void GameState::update(const float& dt){
    this->updateKeyBinds(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "a is pressed" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        std::cout << "b is pressed" << std::endl;
    }
    
}
void GameState::render(sf::RenderTarget* target){

}
void GameState::endState(){
    std::cout << "ending game state" << std::endl;
}
void GameState::updateKeyBinds(const float& dt){
    this->checkForEnd();

}