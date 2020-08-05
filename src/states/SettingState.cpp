#include "SettingState.hpp"
SettingState::SettingState(sf::RenderWindow*           window,
                           std::map<std::string, int>* supportedKeys,
                           std::stack<State*>*         states)
  : State(window, supportedKeys, states)
{
}

SettingState::~SettingState() {}