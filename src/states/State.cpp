#include "State.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
             std::stack<State*>* states)
{
  this->window = window;
  this->wantsEnd = false;
  this->supportedKeys = supportedKeys;
  this->states = states;
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