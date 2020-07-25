#include "GameState.h"

GameState::GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys) : State(window,supportedKeys) {
    this->initKeyBinds();
}
GameState::~GameState(){

}
void GameState::update(const float& dt){
    this->updateMousePositions();
    this->updateKeyBinds(dt);
    this->player.update(dt);
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
        std::cout << this->keybind.at("MOVE_LEFT") << std::endl;
        this->player.move(dt,-1,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_DOWN"))))
    {
        std::cout << this->keybind.at("MOVE_DOWN") << std::endl;
        this->player.move(dt,0,1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_UP"))))
    {
        std::cout << this->keybind.at("MOVE_UP") << std::endl;
        this->player.move(dt,0,-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_RIGHT"))))
    {
        std::cout << this->keybind.at("MOVE_RIGHT") << std::endl;
        this->player.move(dt,1,0);
    }
    
}
void GameState::initKeyBinds(){
    std::ifstream ifstr("../config/keys_game.ini");
    if (ifstr.is_open())
    {
        std::string key = "";
        std::string value = "";
        while (ifstr >> key >> value)
        {
            //std::cout << key << " " << value << std::endl;
            this->keybind[key] = this->supportedKeys->at(value);
        }
    }
    ifstr.close();
}