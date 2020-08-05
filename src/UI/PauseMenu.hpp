#pragma once

#include "Button.hpp"
#include "states/State.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>

class PauseMenu
{
private:
  sf::RectangleShape                             bckground;
  sf::RectangleShape                             container;
  std::map<std::string, std::unique_ptr<Button>> buttons;
  std::vector<std::string>                       button_order;
  sf::Font                                       font;
  sf::Text                                       pauseText;
  State*                                         origin;

public:
  PauseMenu(State* state);
  ~PauseMenu();
  void update();
  void initFont();
  void addButton(float x, float y, float width, float height, std::string text,
                 sf::Font* font, unsigned int charSize, sf::Color idleText,
                 sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
                 sf::Color hoverColor, sf::Color activeColor);
  void updateButtons();
  void initPlayer();
  void render(sf::RenderTarget* target);
};
