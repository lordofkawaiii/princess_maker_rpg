#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states) : State(window,supportedKeys,states) {
    this->initKeyBinds();
    this->initFont();
    
    this->addButton(10.f,10.f,100.f,100.f,
    std::string("new game"),&this->font,
    sf::Color(0, 0, 0, 200),sf::Color(100, 100, 100, 200),sf::Color(250, 250, 250, 200));
    
    this->addButton(200.f,200.f,100.f,100.f,
    std::string("settings"),&this->font,
    sf::Color(0, 0, 0, 200),sf::Color(100, 100, 100, 200),sf::Color(250, 250, 250, 200));
    this->setBackground();
    
    this->addButton(200.f,200.f,100.f,100.f,
    std::string("exit"),&this->font,
    sf::Color(0, 0, 0, 200),sf::Color(100, 100, 100, 200),sf::Color(250, 250, 250, 200));
    this->setBackground();

    this->updateButtons();
}
MainMenuState::~MainMenuState(){
    for (std::map<std::string,Button*>::iterator it=this->buttons.begin(); it!=this->buttons.end(); ++it)
        delete it->second;
    
}

void MainMenuState::updateButtons(){
    float width = this->window->getSize().x;
    float height = this->window->getSize().y;
    float k = 1;
    for (std::vector<std::string>::iterator it=this->button_order.begin(); it!=this->button_order.end(); ++it)
    {
        Button* target = this->buttons[*it];
        target->setPosition((this->window->getSize().x/2.f) - (target->getSize().x /2.f),(height/(this->buttons.size()+1))*k);
        k = k+1;
        // target->setSize(width/3.0,height/this->buttons.size());
    }
    
}
void MainMenuState::update(const float& dt){
    this->updateMousePositions();
    this->updateKeyBinds(dt);
    for (std::map<std::string,Button*>::iterator it=this->buttons.begin(); it!=this->buttons.end(); ++it)
    {
        it->second->update(this->mouseToView);
    }

    // this->updateButtons();


    // handle buttons
    //quit the game
    if (this->buttons["new game"]->isPressed())
    {
        this->states->push(new GameState(this->window,this->supportedKeys,this->states));
    }

    if (this->buttons["exit"]->isPressed())
    {
        this->endState();
    }
    
}
void MainMenuState::render(sf::RenderTarget* target){
    
    this->window->draw(this->background);

    for (std::map<std::string,Button*>::iterator it=this->buttons.begin(); it!=this->buttons.end(); ++it)
    {
        it->second->render(this->window);
    }
}
void MainMenuState::updateKeyBinds(const float& dt){
    // this->checkForEnd();
    
}
void MainMenuState::initKeyBinds(){
    std::ifstream ifstr("../config/keys_game.ini");
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

void MainMenuState::initFont(){
    if (!(this->font.loadFromFile("../Fonts/propaganda.ttf"))){
        throw("could not load font");
    }
}

void MainMenuState::setBackground()
{
    this->background.setSize(sf::Vector2f((float) this->window->getSize().x, (float) this->window->getSize().y));
    if (!this->bgTexture.loadFromFile("../ressources/images/fascist_flag.png"))
        throw "could not load the texture";
    this->background.setTexture(&this->bgTexture);
}

void MainMenuState::addButton(float x,float y, float width, float height,
            std::string text,sf::Font* font,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor){
    this->buttons[text] = new Button(x,y,width,height,text,font,idleColor,hoverColor,activeColor);
    this->button_order.insert(this->button_order.end(),text);
}
