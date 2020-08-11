#include "StateWButtons.hpp"

StateWButtons::StateWButtons(sf::RenderWindow*           window,
                             std::map<std::string, int>* supportedKeys,
                             std::stack<State*>*         states)
  : State(window, supportedKeys, states)
{
}

StateWButtons::~StateWButtons() {}

void StateWButtons::addButton(float x, float y, float width, float height,
                              std::string text, sf::Font* font, unsigned int charSize,
                              sf::Color idleText, sf::Color hoverText,
                              sf::Color activeText, sf::Color idleColor,
                              sf::Color hoverColor, sf::Color activeColor)
{
  this->buttons[text] =
    new Button(x, y, width, height, text, font, charSize, idleText, hoverText, activeText,
               idleColor, hoverColor, activeColor);
  this->button_order.insert(this->button_order.end(), text);
}

void StateWButtons::initFont()
{
  if (!(this->font.loadFromFile("ressources/Fonts/propaganda.ttf")))
  {
    throw("could not load font");
  }
}

void StateWButtons::updateButtons()
{
  float height = this->window->getSize().y;
  float k = 1;
  for (auto name : button_order)
  {
    Button* target = buttons[name];
    target->setPosition((this->window->getSize().x / 2.f) - (target->getSize().x / 2.f),
                        (height / (this->buttons.size() + 1)) * k);
    k = k + 1;
    // target->setSize(width/3.0,height/this->buttons.size());
  }
}

bool StateWButtons::hasButtons()
{
  return true;
}

std::map<std::string, Button*>& StateWButtons::getButtons()
{
  return (this->buttons);
}