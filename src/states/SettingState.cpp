#include "SettingState.hpp"
SettingState::SettingState(sf::RenderWindow*           window,
                           std::map<std::string, int>* supportedKeys,
                           std::stack<State*>*         states)
  : StateWButtons(window, supportedKeys, states)
{
  this->initFont();
  this->addButton(
    200.f, 200.f, this->window->getSize().x / 4, this->window->getView().getSize().y / 8,
    std::string("exit"), &this->font, 20, sf::Color(250, 250, 250, 250),
    sf::Color(175, 175, 175, 250), sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
    sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));
}

SettingState::~SettingState() {}

void SettingState::initKeyBinds()
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
void SettingState::updateGeneralInput(float dt)
{
  // this->checkForEnd();
}
void SettingState::render(sf::RenderTarget* target)
{

  // this->window->draw(this->background);

  for (auto& [_, button] : buttons)
  {
    button->render(target);
  }
}
void SettingState::update(float dt)
{
  this->updateMousePositions();
  this->updateKeytime(dt);
  this->updateGeneralInput(dt);
  for (auto& [_, b] : buttons)
  {
    b->update(this->mouseToView);
  }
  if (this->getKeyready())
  {
    if (this->buttons["exit"]->isPressed())
    {
      this->endState();
    }
  }
}