#include "State.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
             std::stack<State*>* states)
{
  this->window = window;
  this->wantsEnd = false;
  this->supportedKeys = supportedKeys;
  this->states = states;
  this->paused = false;
  this->keytime = 0.f;
  this->keytimeMax = 2.f;
}

State::~State() {}

void State::endState()
{
  this->wantsEnd = true;
}

bool State::getEnd()
{
  return this->wantsEnd;
}

void State::pauseState()
{
  this->paused = true;
}
void State::unpauseState()
{
  this->paused = false;
}

void State::updateMousePositions()
{
  this->mouseToScreen = sf::Mouse::getPosition();
  this->mouseToWindow = sf::Mouse::getPosition(*this->window);
  this->mouseToView = this->window->mapPixelToCoords(this->mouseToWindow);
}

void State::addTexture(std::string textureName, std::string path)
{
  sf::Texture temp;
  temp.loadFromFile(path);
  this->textures[textureName] = temp;
}

void State::setBackground()
{
  //
}

sf::Vector2f State::getMouseToView()
{
  return this->mouseToView;
}
sf::RenderWindow* State::getRenderWindow()
{
  return this->window;
}
void State::updateKeytime(float dt)
{
  if (this->keytime < this->keytimeMax)
  {
    this->keytime += 10.f * dt;
  }
}

bool State::getKeyready()
{
  if (this->keytime >= this->keytimeMax)
  {
    this->keytime = 0.f;
    return true;
  }
  else
  {
    return false;
  }
}

bool State::hasButtons()
{
  return false;
}

std::map<std::string, Button*> State::getButtons()
{
  return (this->buttons);
}