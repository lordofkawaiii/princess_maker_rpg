#include "PauseMenu.hpp"

PauseMenu::PauseMenu(State* state)
{
  this->origin = state;
  this->bckground.setSize(sf::Vector2f(
    static_cast<float>(this->origin->getRenderWindow()->getView().getSize().x),
    static_cast<float>(this->origin->getRenderWindow()->getView().getSize().y)));
  this->bckground.setFillColor(sf::Color(20, 20, 20, 100));
  this->container.setSize(sf::Vector2f(
    static_cast<float>(this->origin->getRenderWindow()->getView().getSize().x) / 4.f,
    static_cast<float>(this->origin->getRenderWindow()->getView().getSize().y)));
  this->container.setFillColor(sf::Color(20, 20, 20, 200));
  this->container.setPosition(this->origin->getRenderWindow()->getView().getSize().x /
                                  2.f -
                                this->container.getSize().x / 2.f,
                              0.f);
  this->initFont();

  this->pauseText.setFont(font);
  this->pauseText.setColor(sf::Color(255, 255, 255, 200));
  this->pauseText.setCharacterSize(20);
  this->pauseText.setString("PAUSED");
  this->pauseText.setPosition(this->origin->getRenderWindow()->getView().getSize().x /
                                  2.f -
                                this->pauseText.getGlobalBounds().width / 2.f,
                              this->pauseText.getGlobalBounds().height);
  //   this->pauseText.setPosition(100, 100);
  this->addButton(
    200.f, 200.f, this->origin->getRenderWindow()->getView().getSize().x / 4,
    this->origin->getRenderWindow()->getView().getSize().y / 8, std::string("settings"),
    &this->font, 20, sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
    sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200), sf::Color(100, 100, 100, 200),
    sf::Color(250, 250, 250, 200));

  this->addButton(200.f, 200.f, this->container.getGlobalBounds().width,
                  this->origin->getRenderWindow()->getView().getSize().y / 8,
                  std::string("exit"), &this->font, 20, sf::Color(250, 250, 250, 250),
                  sf::Color(175, 175, 175, 250), sf::Color(100, 100, 100, 200),
                  sf::Color(0, 0, 0, 200), sf::Color(100, 100, 100, 200),
                  sf::Color(250, 250, 250, 200));
  this->updateButtons();
}
void PauseMenu::initFont()
{
  if (!(this->font.loadFromFile("ressources/Fonts/propaganda.ttf")))
  {
    throw("could not load font");
  }
}
PauseMenu::~PauseMenu() {}

void PauseMenu::update()
{
  for (auto& [_, b] : buttons)
  {
    b->update(this->origin->getMouseToView());
  }
  if (this->buttons["exit"]->isPressed())
  {
    this->origin->endState();
  }
  // if (this->buttons["settings"]->isPressed())
  // {
  //   this->origin->getStates()->push(new SettingState(this->origin->getRenderWindow(),
  //                                                    this->origin->getSupportedKeys(),
  //                                                    this->origin->getStates()));
  //   this->buttons["settings"]->resetSate();
  // }
}

void PauseMenu::render(sf::RenderTarget* target)
{
  target->draw(this->bckground);
  target->draw(this->container);
  target->draw(this->pauseText);
  for (auto& [_, button] : buttons)
  {
    button->render(target);
  }
}
void PauseMenu::addButton(float x, float y, float width, float height, std::string text,
                          sf::Font* font, unsigned int charSize, sf::Color idleText,
                          sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
                          sf::Color hoverColor, sf::Color activeColor)
{
  this->buttons[text] =
    new Button(x, y, width, height, text, font, charSize, idleText, hoverText, activeText,
               idleColor, hoverColor, activeColor);
  this->button_order.insert(this->button_order.end(), text);
}

void PauseMenu::updateButtons()
{
  float height = this->origin->getRenderWindow()->getView().getSize().y;
  float k = 1;
  for (auto name : button_order)
  {
    buttons[name]->setPosition(
      (this->origin->getRenderWindow()->getView().getSize().x / 2.f) -
        (buttons[name]->getSize().x / 2.f),
      (height / (this->buttons.size() + 1)) * k);
    // buttons[name]->setSize(this->container.getGlobalBounds().width,
    //                        height / this->buttons.size());
    k = k + 1;
  }
}
std::map<std::string, Button*> PauseMenu::getButtons()
{
  return this->buttons;
}