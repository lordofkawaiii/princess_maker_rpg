#include "Game.hpp"

//initializer

void Game::initSettings()
{

  this->graphicsSettings.loadFromFile("config/config.ini");
}

void Game::initWindow()
{

  if (this->graphicsSettings.fullscreen)
  {
    this->renderWindow = new sf::RenderWindow(
      this->graphicsSettings.resolution, this->graphicsSettings.title,
      sf::Style::Fullscreen, this->graphicsSettings.context);
  }
  else
  {
    this->renderWindow = new sf::RenderWindow(
      this->graphicsSettings.resolution, this->graphicsSettings.title, sf::Style::Default,
      this->graphicsSettings.context);
  }

  this->renderWindow->setFramerateLimit(this->graphicsSettings.frameRateLimit);
  this->renderWindow->setVerticalSyncEnabled(this->graphicsSettings.vSync);
}

Game::Game()
{
  this->initSettings();
  this->initWindow();
  this->initKeys();
  this->initState();
}

Game::~Game()
{
  delete this->renderWindow;

  while (!this->states.empty())
  {
    delete this->states.top();
    this->states.pop();
  }
}

void Game::updateSFMLevents()
{
  while (this->renderWindow->pollEvent(this->event))
  {
    if (this->event.type == sf::Event::Closed)
      this->renderWindow->close();
    // if (this->event.type == sf::Event::MouseButtonReleased)
    // {
    //   std::vector<Button*> buttons = this->states.top()->getButtons();
    //   sf::Vector2f         mousePos = this->states.top()->getMouseToView();
    //   for (const auto& button : buttons)
    //   {
    //     if (button->isCursorIn(mousePos))
    //     {
    //       button->setClicked();
    //     }
    //   }
    // }
  }
}

void Game::update()
{
  this->updateSFMLevents();

  // update the top state
  if (!this->states.empty())
  {
    this->states.top()->update(this->dt);

    if (this->states.top()->getEnd())
    {
      this->states.top()->endState();
      // quit the state
      delete this->states.top();
      this->states.pop();
    }
  }
  else
  {
    this->renderWindow->close();
  }
}

void Game::endApp()
{
  this->renderWindow->close();
}

void Game::render()
{
  this->renderWindow->clear();

  // render the top state
  if (!this->states.empty())
  {
    this->states.top()->render(this->renderWindow);
  }

  this->renderWindow->display();
}

void Game::updateDt()
{
  this->dt = this->dtClock.restart().asSeconds();
}

void Game::run()
{

  while (this->renderWindow->isOpen())
  {
    this->updateDt();
    this->update();
    this->render();
  }
}

void Game::initState()
{
  //for (size_t i = 0; i < 10; i++)
  //{
  this->states.push(new MainMenuState(this->renderWindow, this->graphicsSettings,
                                      &this->supportedKeys, &this->states));
  // this->states.push(new GameState(this->renderWindow,&this->supportedKeys));

  //}
}

void Game::initKeys()
{
  std::ifstream ifstr("config/keys.ini");
  if (ifstr.is_open())
  {
    std::string key = "";
    int         value = 0;
    while (ifstr >> key >> value)
    {
      //std::cout << key << " " << value << std::endl;
      this->supportedKeys[key] = value;
    }
  }
  ifstr.close();
}
