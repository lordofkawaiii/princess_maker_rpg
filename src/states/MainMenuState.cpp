#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow*           window,
                             std::map<std::string, int>* supportedKeys,
                             std::stack<State*>*         states)
  : StateWButtons(window, supportedKeys, states)
{
  this->initKeyBinds();
  this->initFont();

  this->addButton(10.f, 10.f, this->window->getSize().x / 4,
                  this->window->getSize().y / 8, std::string("new game"), &this->font, 20,
                  sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
                  sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
                  sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));

  this->addButton(200.f, 200.f, this->window->getSize().x / 4,
                  this->window->getSize().y / 8, std::string("settings"), &this->font, 20,
                  sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
                  sf::Color(100, 100, 100, 200), sf ::Color(0, 0, 0, 200),
                  sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));

  this->addButton(200.f, 200.f, this->window->getSize().x / 4,
                  this->window->getSize().y / 8, std::string("editor"), &this->font, 20,
                  sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
                  sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
                  sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));

  this->addButton(200.f, 200.f, this->window->getSize().x / 4,
                  this->window->getSize().y / 8, std::string("exit"), &this->font, 20,
                  sf::Color(250, 250, 250, 250), sf::Color(175, 175, 175, 250),
                  sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
                  sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));
  this->setBackground();

  this->updateButtons();
}
MainMenuState::~MainMenuState()
{
  for (auto& [_, b] : buttons)
    delete b;
}

void MainMenuState::update(float dt)
{
  this->updateMousePositions();
  this->updateKeytime(dt);
  this->updateGeneralInput(dt);
  for (auto& [_, b] : buttons)
  {
    b->update(this->mouseToView);
  }

  // this->updateButtons();

  // handle buttons
  //quit the game
  if (this->getKeyready())
  {
    if (this->buttons["new game"]->isPressed())
    {
      this->states->push(new GameState(this->window, this->supportedKeys, this->states));
      this->buttons["new game"]->resetSate();
    }

    if (this->buttons["editor"]->isPressed())
    {
      this->states->push(
        new EditorState(this->window, this->supportedKeys, this->states));
      this->buttons["editor"]->resetSate();
    }

    if (this->buttons["settings"]->isPressed())
    {
      this->states->push(
        new SettingState(this->window, this->supportedKeys, this->states));
      this->buttons["settings"]->resetSate();
    }

    if (this->buttons["exit"]->isPressed())
    {
      this->endState();
    }
  }
}
void MainMenuState::render(sf::RenderTarget* target)
{

  this->window->draw(this->background);

  for (auto& [_, button] : buttons)
  {
    button->render(target);
  }
}
void MainMenuState::updateGeneralInput(float dt)
{
  // this->checkForEnd();
}
void MainMenuState::initKeyBinds()
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

void MainMenuState::setBackground()
{
  this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
                                        static_cast<float>(this->window->getSize().y)));
  if (!this->bgTexture.loadFromFile("ressources/images/fascist_flag.png"))
  {
    throw "could not load the texture";
  }
  this->background.setTexture(&this->bgTexture);
}
