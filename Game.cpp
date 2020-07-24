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
    this->initKeys();
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

        if (this->states.top()->getEnd())
        {
            this->states.top()->endState();
            // quit the state
            delete this->states.top();
            this->states.pop();
            std::cout << "quitting state" << std::endl;
        }
        
    }
}

void Game::endApp(){
    this->renderWindow->close();
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
    for (size_t i = 0; i < 10; i++)
    {
        this->states.push(new GameState(this->renderWindow,&this->supportedKeys));
    }
}

void Game::initKeys(){
    this->supportedKeys.emplace("Q",sf::Keyboard::Q);
    this->supportedKeys.emplace("D",sf::Keyboard::D);
    this->supportedKeys.emplace("Z",sf::Keyboard::Z);
    this->supportedKeys.emplace("S",sf::Keyboard::S);

    this->supportedKeys.emplace("Escape",sf::Keyboard::Escape);
}
