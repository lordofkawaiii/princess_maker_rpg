#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys) : State(window,supportedKeys) {
    this->initKeyBinds();
    this->initFont();
}
MainMenuState::~MainMenuState(){

}
void MainMenuState::update(const float& dt){
    this->updateMousePositions();
    this->updateKeyBinds(dt);
    std::cout << this->mouseToView.x << " " << this->mouseToView.y << std::endl;
}
void MainMenuState::render(sf::RenderTarget* target){
}
void MainMenuState::endState(){
    std::cout << "ending MainMenuState state" << std::endl;
}
void MainMenuState::updateKeyBinds(const float& dt){
    this->checkForEnd();
    
}
void MainMenuState::initKeyBinds(){
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

void MainMenuState::initFont(){
    if (!this->font = sf::Font::loadFromFile("../Fonts/propaganda.ttf")){
        throw("could not load font")
    }
}
