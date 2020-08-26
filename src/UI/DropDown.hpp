#pragma once
#include "Button.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>

class DropDown
{
private:
  float                keytime;
  float                keytimeMax;
  sf::Font*            font;
  Button*              activeElement;
  std::vector<Button*> list;
  bool                 extended;

public:
  DropDown(float x, float y, float height, float width, sf::Font* font,
           std::string list[], unsigned nbrOfElements, unsigned defaultIndex = 0);
  ~DropDown();
  void                 update(const sf::Vector2f mousePosition, float dt);
  void                 render(sf::RenderTarget* target);
  std::vector<Button*> getButtons();
  void                 addButton(Button* button);
  bool                 getKeytime();
  void                 updateKeytime(float dt);
  void                 setPosition(sf::Vector2f position);
  void                 setPosition(float x, float y);
  sf::Vector2f         getSize();
  short unsigned       getActiveElementId();
};