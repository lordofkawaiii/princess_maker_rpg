#pragma once
#include "State.hpp"
#include "UI/Button.hpp"

class EditorState : public State
{
private:
  //functions
  void initKeyBinds();
  void initFont();

protected:
  sf::Texture                    bgTexture;
  sf::RectangleShape             background;
  sf::Font                       font;
  std::map<std::string, Button*> buttons;
  std::vector<std::string>       button_order;

public:
  EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
              std::stack<State*>* states);
  ~EditorState();
  void update(float dt);
  void updateKeyBinds(float dt);
  void render(sf::RenderTarget* target = nullptr);
  void addButton(float x, float y, float width, float height, std::string text,
                 sf::Font* font, unsigned int charSize, sf::Color idleText,
                 sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
                 sf::Color hoverColor, sf::Color activeColor);
  void setBackground();
  void updateButtons();
};
