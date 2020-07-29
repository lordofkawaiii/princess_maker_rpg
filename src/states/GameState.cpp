#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
                     std::stack<State*>* states)
  : State(window, supportedKeys, states)
{
  // this->initKeyBinds();
  this->initTextures();
  this->initPlayer();
}
GameState::~GameState()
{
  delete this->player;
}
void GameState::initPlayer()
{
  this->player = new Player(100.f, 100.f, &this->textures["idle_char"]);
}
void GameState::update(float dt)
{
  this->updateMousePositions();
  this->updateKeyBinds(dt);
  this->player->update(dt);
}
void GameState::render(sf::RenderTarget* target)
{
  this->player->render(target);
  this->window->draw(this->background);
}
void GameState::updateKeyBinds(float dt)
{
  // this->checkForEnd();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_LEFT"))))
  {
    this->player->move(dt, -1, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_DOWN"))))
  {
    this->player->move(dt, 0, 1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_UP"))))
  {
    this->player->move(dt, 0, -1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("MOVE_RIGHT"))))
  {
    this->player->move(dt, 1, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("CLOSE"))))
  {
    this->endState();
  }
}
void GameState::initKeyBinds()
{
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

void GameState::initTextures()
{
  this->addTexture("idle_char",
                   "../ressources/TopDownCharacter/Character/Character_Idle.png");
}