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

std::vector<Button*> StateWPause::getButtons()
{
  if (this->paused)
  {
    std::vector<Button*> res;
    for (const auto& [_, button] : this->pauseMenu->getButtons())
    {
      res.push_back(button);
    }
    std::cout << "state is  paused" << std::endl;
    return res;
  }
  else
  {
    std::cout << "state is not paused" << std::endl;
    return this->getButtons();
  }
}