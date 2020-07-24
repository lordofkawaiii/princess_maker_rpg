#include "GameState.h"

GameState::GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys) : State(window,supportedKeys) {
    this->initKeyBinds();
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
    this->player.render(this->window);
}
void GameState::endState(){
    std::cout << "ending game state" << std::endl;
}
void GameState::updateKeyBinds(const float& dt){
    this->checkForEnd();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_LEFT"))))
    {
        this->player.move(dt,-1,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_DOWN"))))
    {
        this->player.move(dt,0,1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_UP"))))
    {
        this->player.move(dt,0,-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_RIGHT"))))
    {
        this->player.move(dt,1,0);
    }
    
}
void GameState::initKeyBinds(){
    this->keybind.emplace("MOVE_LEFT",this->supportedKeys->at("Q"));
    this->keybind.emplace("MOVE_RIGHT",this->supportedKeys->at("D"));
    this->keybind.emplace("MOVE_UP",this->supportedKeys->at("Z"));
    this->keybind.emplace("MOVE_DOWN",this->supportedKeys->at("S"));
}