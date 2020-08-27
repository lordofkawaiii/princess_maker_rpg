#include "SettingState.hpp"
SettingState::SettingState(sf::RenderWindow* window, Settings settings,
                           std::map<std::string, int>* supportedKeys,
                           std::stack<State*>*         states)
  : StateWButtons(window, supportedKeys, states), settings(settings)
{
  this->initFont();
  init();
}

void SettingState::init()
{
  modes = sf::VideoMode::getFullscreenModes();
  std::vector<std::string> modeStr;
  for (auto&& i : modes)
  {
    modeStr.emplace_back(std::to_string(i.width) + "x" + std::to_string(i.height));
  }
  size_t k = 0;
  for (; k < modeStr.size() &&
         modeStr.at(k) != std::to_string(this->window->getSize().x) + "x" +
                            std::to_string(this->window->getSize().y);)
  {
    // std::cout << std::to_string(this->window->getSize().x) + "x" +
    //                std::to_string(this->window->getSize().y)
    //           << std::endl;
    // std::cout << modeStr.at(k) << std::endl;
    // std::cout << sf::VideoMode::getDesktopMode().width << "x"
    //           << sf::VideoMode::getDesktopMode().height << std::endl;
    // std::cout << "-----------------------------" << std::endl;
    k++;
  }
  this->addButton(
    this->window->getView().getSize().x / 10 - (this->window->getSize().x / 4.f) / 2,
    this->window->getView().getSize().y - this->window->getView().getSize().y / 10 -
      (this->window->getView().getSize().y / 8) / 2,
    this->window->getSize().x / 4.f, this->window->getView().getSize().y / 8,
    std::string("apply"), &this->font, 20, sf::Color(250, 250, 250, 250),
    sf::Color(175, 175, 175, 250), sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
    sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));
  this->addButton(
    this->window->getView().getSize().x - this->window->getView().getSize().x / 10 -
      (this->window->getSize().x / 4.f) / 2,
    this->window->getView().getSize().y - this->window->getView().getSize().y / 10 -
      (this->window->getView().getSize().y / 8) / 2,
    this->window->getSize().x / 4.f, this->window->getView().getSize().y / 8,
    std::string("exit"), &this->font, 20, sf::Color(250, 250, 250, 250),
    sf::Color(175, 175, 175, 250), sf::Color(100, 100, 100, 200), sf::Color(0, 0, 0, 200),
    sf::Color(100, 100, 100, 200), sf::Color(250, 250, 250, 200));

  this->dropDownLists["resolution"] = new DropDown(
    100.f, 100.f, 200.f, 50.f, &(this->font), modeStr.data(), modeStr.size(), k);
  this->dropDownLists["Vsync"] =
    new DropDown(100.f, 100.f, 200.f, 50.f, &(this->font), modeStr.data(), 0);
  this->dropDownLists["antialiasing"] =
    new DropDown(100.f, 100.f, 200.f, 50.f, &(this->font), modeStr.data(), 0);
  this->dropDownLists["fullscreen"] =
    new DropDown(100.f, 100.f, 200.f, 50.f, &(this->font), modeStr.data(), 0);
  initText();
}

SettingState::~SettingState() {}

void SettingState::initKeyBinds()
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
void SettingState::updateGeneralInput(float dt)
{
  // this->checkForEnd();
}
void SettingState::render(sf::RenderTarget* target)
{

  // this->window->draw(this->background);

  for (auto& [_, button] : buttons)
  {
    button->render(target);
  }
  for (auto& [_, drop] : dropDownLists)
  {
    drop->render(target);
  }
  for (auto&& i : this->optionTexts)
  {
    target->draw(i);
  }
}
void SettingState::update(float dt)
{
  this->updateMousePositions();
  this->updateKeytime(dt);
  this->updateGeneralInput(dt);
  for (auto& [_, drop] : dropDownLists)
  {
    drop->update(this->mouseToView, dt);
  }
  for (auto& [_, b] : buttons)
  {
    b->update(this->mouseToView);
  }
  if (this->getKeyready())
  {
    if (this->buttons["exit"]->isPressed())
    {
      this->endState();
    }
    if (this->buttons["apply"]->isPressed())
    {
      this->settings.resolution =
        this->modes[this->dropDownLists["resolution"]->getActiveElementId()];
      this->window->create(this->settings.resolution, this->settings.title,
                           sf::Style::Default);
      this->settings.saveToFile("config/config.ini");
      // std::stack<State*> temp;
      // int                k = this->states->size();
      // for (size_t i = 0; i < k; i++)
      // {
      //   State* tempSate = states->top();
      //   tempSate->resizeAll();
      //   temp.emplace(tempSate);
      //   states->pop();
      // }
      // for (size_t i = 0; i < k; i++)
      // {
      //   states->emplace(temp.top());
      //   temp.pop();
      // }
    }
  }
}

void SettingState::initText()
{
  std::string list[4] = {"resolution", "Vsync", "antialiasing", "fullscreen"};
  float       k = 0;
  for (auto&& option : list)
  {
    sf::Text optionText;
    optionText.setFont(font);
    optionText.setPosition(0.f, 0.f + k * (this->dropDownLists[option]->getSize().y));
    optionText.setCharacterSize(12.f);
    optionText.setFillColor(sf::Color(250, 250, 250, 255));
    optionText.setString(option);
    optionTexts.emplace_back(optionText);
    k++;
    this->dropDownLists[option]->setPosition(this->window->getSize().x / 2,
                                             optionText.getPosition().y);
  }
}
void SettingState::resizeAll()
{
  this->buttons.clear();
  this->button_order.clear();
  this->dropDownLists.clear();
  init();
}