#include "Game.h"

//initializer

void Game::initWindow() {
    std::ifstream ifs("../config/config.ini");
    
    std::string title = "none";
    sf::VideoMode bounds(800,600);
    unsigned framerateLimit = 120;
    bool vsync = false;
    
    if (ifs.is_open())
    {
        std::getline(ifs,title);
        ifs >> bounds.width >> bounds.height;
        ifs >> framerateLimit;
        ifs >> vsync;
    }

    ifs.close();

    this->renderWindow = new sf::RenderWindow(bounds, title);
    this->renderWindow->setFramerateLimit(framerateLimit);
    this->renderWindow->setVerticalSyncEnabled(vsync);
 }

Game::Game(){
    this->initWindow();
    this->initState();
}

Game::~Game() {
    delete this->renderWindow;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    
}

void Game::updateSFMLevents() {
    while (this->renderWindow->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->renderWindow->close();
    }
}

void Game::update() {
    this->updateSFMLevents();

    // update the top state
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
    }
}

void Game::render() {
    this->renderWindow->clear();

    // render the top state
    if (!this->states.empty())
    {
        this->states.top()->render(this->renderWindow);
    }
    


    this->renderWindow->display();
}

void Game::updateDt(){
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::run() {

    while (this->renderWindow->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::initState(){
    this->states.push(new GameState(this->renderWindow));
}
