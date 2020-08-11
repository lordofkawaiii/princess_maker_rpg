
#include "EditorState.hpp"

EditorState::EditorState(sf::RenderWindow*           window,
                         std::map<std::string, int>* supportedKeys,
                         std::stack<State*>*         states)
  : StateWButtons(window, supportedKeys, states)
{
  this->initKeyBinds();
  this->initFont();

  this->updateButtons();
}
EditorState::~EditorState()
{
  for (auto& [_, b] : buttons)
    delete b;
}

void EditorState::update(float dt)
{
  this->updateMousePositions();
  this->updateGeneralInput(dt);
  for (auto& [_, b] : buttons)
  {
    b->update(this->mouseToView);
  }
}
void EditorState::render(sf::RenderTarget* target)
{

  this->window->draw(this->background);

  for (auto& [_, button] : buttons)
  {
    button->render(target);
  }
}
void EditorState::updateGeneralInput(float dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybind.at("CLOSE"))))
  {
    this->endState();
  }
}
void EditorState::initKeyBinds()
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

void EditorState::setBackground()
{
  this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
                                        static_cast<float>(this->window->getSize().y)));
  if (!this->bgTexture.loadFromFile("ressources/images/fascist_flag.png"))
  {
    throw "could not load the texture";
  }
  this->background.setTexture(&this->bgTexture);
}
