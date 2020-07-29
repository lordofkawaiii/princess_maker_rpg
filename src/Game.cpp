#include "Game.hpp"

//initializer

void Game::initWindow()
{
  std::ifstream ifs("../config/config.ini");

  this->vm = sf::VideoMode::getFullscreenModes();

  std::string   title = "none";
  sf::VideoMode bounds = sf::VideoMode::getDesktopMode();
  unsigned      framerateLimit = 120;
  bool          vsync = false;
  bool          fullscreen = false;
  unsigned      antialiasingLvl = 0;

  if (ifs.is_open())
  {
    std::getline(ifs, title);
    ifs >> bounds.width >> bounds.height;
    ifs >> framerateLimit;
    ifs >> vsync;
    ifs >> fullscreen;
    ifs >> antialiasingLvl;
  }

  ifs.close();

  this->contextSettings.antialiasingLevel = antialiasingLvl;
  if (fullscreen)
  {
    this->renderWindow =
      new sf::RenderWindow(bounds, title, sf::Style::Fullscreen, this->contextSettings);
  }
  else
  {
    this->renderWindow =
      new sf::RenderWindow(bounds, title, sf::Style::Default, this->contextSettings);
  }

  this->renderWindow->setFramerateLimit(framerateLimit);
  this->renderWindow->setVerticalSyncEnabled(vsync);
}

Game::Game()
{
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
      std::cout << "quitting state" << std::endl;
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
  this->states.push(
    new MainMenuState(this->renderWindow, &this->supportedKeys, &this->states));
  // this->states.push(new GameState(this->renderWindow,&this->supportedKeys));

  //}
}

void Game::initKeys()
{
  std::ifstream ifstr("../config/keys.ini");
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
