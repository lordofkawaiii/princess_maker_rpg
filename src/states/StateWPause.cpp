#include "StateWPause.hpp"

StateWPause::StateWPause(sf::RenderWindow*           window,
                         std::map<std::string, int>* supportedKeys,
                         std::stack<State*>*         states)
  : State(window, supportedKeys, states)
{
  this->pauseMenu = new PauseMenu(this);
}

StateWPause::~StateWPause() {}

bool StateWPause::hasButtons()
{
  return this->paused;
}

std::map<std::string, Button*> StateWPause::getButtons()
{
  if (this->paused)
  {
    return (this->pauseMenu->getButtons());
  }
  else
  {
    return this->getButtons();
    std::cout << "state is not paused" << std::endl;
  }
}