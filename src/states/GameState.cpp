#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
                     std::stack<State*>* states)
  : State(window, supportedKeys, states)
{
  this->pauseMenu = new PauseMenu(this);
  this->initKeyBinds();
  this->initTextures();
  this->initPlayer();
  this->setBackground();
}
GameState::~GameState()
{
  delete this->player;
}
void GameState::initPlayer()
{
  this->player = new Player(100.f, 100.f, &this->textures["all_sheet"]);
}
void GameState::update(float dt)
{
  this->updateMousePositions();
  this->updateKeytime(dt);
  this->updateGeneralInput(dt);

  if (!this->paused)
  {
    this->updatePlayerInput(dt);
    this->player->update(dt);
  }
  else
  {
    this->pauseMenu->update();
  }
}
void GameState::render(sf::RenderTarget* target)
{
  this->window->draw(this->background);
  this->player->render(target);
  if (this->paused)
  {
    this->pauseMenu->render(target);
  }
}
void GameState::updateGeneralInput(float dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("CLOSE"))) and
      this->getKeyready())
  {
    if (this->paused)
    {
      this->unpauseState();
    }
    else
    {
      this->pauseState();
    }
  }
}
void GameState::updatePlayerInput(float dt)
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
}
void GameState::initKeyBinds()
{
  std::ifstream ifstr("config/keys_game.ini");
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
  this->addTexture("all_sheet", "ressources/TopDownCharacter/Character/all_sheets.png");
}

void GameState::setBackground()
{
  this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
                                        static_cast<float>(this->window->getSize().y)));
  this->background.setFillColor(sf::Color::White);
}