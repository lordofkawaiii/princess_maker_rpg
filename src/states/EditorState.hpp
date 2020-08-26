#pragma once
#include "StateWButtons.hpp"

class EditorState : public StateWButtons
{
private:
  //functions
  void initKeyBinds();

protected:
  sf::Texture        bgTexture;
  sf::RectangleShape background;

public:
  EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
              std::stack<State*>* states);
  ~EditorState();
  void update(float dt);
  void updateGeneralInput(float dt);
  void render(sf::RenderTarget* target = nullptr);
  void setBackground();
  void resizeAll();
};
