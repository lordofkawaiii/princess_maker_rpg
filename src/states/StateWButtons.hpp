#pragma once
#include "State.hpp"
#include "UI/Button.hpp"

class StateWButtons : public State
{
protected:
  sf::Font font;

  std::vector<std::string> button_order;

public:
  StateWButtons(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
                std::stack<State*>* states);
  ~StateWButtons();
  void initFont();
  void updateButtons();
  void addButton(float x, float y, float width, float height, std::string text,
                 sf::Font* font, unsigned int charSize, sf::Color idleText,
                 sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
                 sf::Color hoverColor, sf::Color activeColor);
  bool hasButtons();
  std::map<std::string, Button*> getButtons();
};
