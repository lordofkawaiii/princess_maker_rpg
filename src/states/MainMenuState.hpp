#pragma once

#include "EditorState.hpp"
#include "GameState.hpp"
#include "SettingState.hpp"
#include "StateWButtons.hpp"
#include "UI/Button.hpp"
#include "utilities/Settings.hpp"

class MainMenuState : public StateWButtons
{
private:
  //functions
  void initKeyBinds();

protected:
  sf::Texture        bgTexture;
  sf::RectangleShape background;
  Settings&          settings;

public:
  MainMenuState(sf::RenderWindow* window, Settings& settings,
                std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
  ~MainMenuState();
  void update(float dt);
  void updateGeneralInput(float dt);
  void render(sf::RenderTarget* target = nullptr);
  void setBackground();
  void resizeAll();
};
