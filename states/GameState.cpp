#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}
GameState::~GameState(){

}
void GameState::update(const float& dt){
    std::cout << "game state update" << std::endl;
}
void GameState::render(sf::RenderTarget* target){

}
void GameState::endState(){

}