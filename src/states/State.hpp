#pragma once

#include "UI/Button.hpp"
#include "UI/DropDown.hpp"
#include "entities/Entity.hpp"

class State
{
private:
protected:
  sf::RenderWindow*              window;
  std::map<std::string, Button*> buttons;

  bool                               wantsEnd;
  std::map<std::string, int>*        supportedKeys;
  std::map<std::string, int>         keybind;
  std::stack<State*>*                states;
  std::map<std::string, sf::Texture> textures;
  float                              keytime;
  float                              keytimeMax;

  bool paused;

  //info about mouse position
  sf::Vector2i mouseToScreen;
  sf::Vector2i mouseToWindow;
  sf::Vector2f mouseToView;

public:
  State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states);
  virtual ~State();

  void                         addTexture(std::string textureName, std::string path);
  bool                         getEnd();
  void                         endState();
  virtual void                 initKeyBinds() = 0;
  virtual void                 updateMousePositions();
  virtual void                 updateGeneralInput(float dt) = 0;
  virtual void                 update(float dt) = 0;
  virtual void                 setBackground();
  virtual void                 render(sf::RenderTarget* target = nullptr) = 0;
  virtual void                 updateKeytime(float dt);
  virtual bool                 hasButtons();
  virtual std::vector<Button*> getButtons();
  std::stack<State*>*          getStates();
  std::map<std::string, int>*  getSupportedKeys();

  void pauseState();
  void unpauseState();
  // accessors
  sf::Vector2f      getMouseToView();
  sf::RenderWindow* getRenderWindow();
  bool              getKeyready();
};
