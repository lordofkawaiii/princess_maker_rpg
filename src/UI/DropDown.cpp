#include "DropDown.hpp"

DropDown::DropDown(float x, float y, float width, float height, sf::Font* font,
                   std::string list[], unsigned nbrOfElements, unsigned defaultIndex)
  : font(font)
{
  for (size_t i = 0; i < nbrOfElements; i++)
  {
    this->list.push_back(new Button(
      x, y + (i + 1) * height, width, height, list[i], font, 12,
      sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
      sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
      sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200),
      sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent, i));
  }
  this->activeElement = new Button(
    x, y, width, height, list[defaultIndex], font, 12, sf::Color(250, 250, 250, 250),
    sf::Color(175, 175, 175, 250), sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
    sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200),
    sf::Color(250, 0, 0, 200), sf::Color(250, 0, 0, 150), sf::Color(250, 0, 0, 50));
  activeElement->setPosition(x, y);
  extended = false;
  keytimeMax = 1.f;
  keytime = 0.f;
}

DropDown::~DropDown() {}

void DropDown::update(const sf::Vector2f mousePosition, float dt)
{
  this->updateKeytime(dt);
  this->activeElement->update(mousePosition);
  if (extended)
  {
    for (auto& button : this->list)
    {
      button->update(mousePosition);
    }
  }
}
void DropDown::render(sf::RenderTarget* target)
{
  this->activeElement->render(target);
  if (activeElement->isPressed() && this->getKeytime())
  {
    extended = !extended;
  }

  if (extended)
  {
    for (auto& button : this->list)
    {
      button->render(target);
      if (button->isPressed() && this->getKeytime())
      {
        extended = false;
        activeElement->setText(button->getText());
        activeElement->setId(button->getId());
      }
    }
  }
}
std::vector<Button*> DropDown::getButtons()
{
  return this->list;
}
void DropDown::addButton(Button* button)
{
  this->list.emplace_back(button);
  if (list.size() > 1)
  {
    Button* previous = list.at(list.size() - 2);
    list.at(list.size() - 1)
      ->setPosition(previous->getPosition().x,
                    previous->getPosition().y + previous->getSize().y);
  }
}

bool DropDown::getKeytime()
{
  if (keytime >= keytimeMax)
  {
    keytime = 0.f;
    return true;
  }
  else
  {
    return false;
  }
}
void DropDown::updateKeytime(float dt)
{
  if (keytime < keytimeMax)
  {
    keytime += 1.f * dt;
  }
}
void DropDown::setPosition(sf::Vector2f position)
{
  this->activeElement->setPosition(position);
  for (size_t i = 0; i < this->list.size(); i++)
  {
    this->list.at(i)->setPosition(position.x, position.y + i * list.at(i)->getSize().y);
  }
}
void DropDown::setPosition(float x, float y)
{
  this->activeElement->setPosition(x, y);
  for (size_t i = 0; i < this->list.size(); i++)
  {
    this->list.at(i)->setPosition(x, y + (i + 1) * list.at(i)->getSize().y);
  }
}
sf::Vector2f DropDown::getSize()
{
  return this->activeElement->getSize();
}

short unsigned DropDown::getActiveElementId()
{
  return this->activeElement->getId();
}