
#include "EditorState.hpp"

EditorState::EditorState(sf::RenderWindow*           window,
                         std::map<std::string, int>* supportedKeys,
                         std::stack<State*>*         states)
  : State(window, supportedKeys, states)
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

void EditorState::updateButtons()
{
  float height = this->window->getSize().y;
  float k = 1;
  for (auto name : button_order)
  {
    Button* target = buttons[name];
    target->setPosition((this->window->getSize().x / 2.f) - (target->getSize().x / 2.f),
                        (height / (this->buttons.size() + 1)) * k);
    k = k + 1;
  }
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

void EditorState::initFont()
{
  if (!(this->font.loadFromFile("ressources/Fonts/propaganda.ttf")))
  {
    throw("could not load font");
  }
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

void EditorState::addButton(float x, float y, float width, float height, std::string text,
                            sf::Font* font, unsigned int charSize, sf::Color idleText,
                            sf::Color hoverText, sf::Color activeText,
                            sf::Color idleColor, sf::Color hoverColor,
                            sf::Color activeColor)
{
  this->buttons[text] =
    new Button(x, y, width, height, text, font, charSize, idleText, hoverText, activeText,
               idleColor, hoverColor, activeColor);
  this->button_order.insert(this->button_order.end(), text);
}
