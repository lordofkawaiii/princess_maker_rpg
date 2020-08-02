#pragma once

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

class HitboxComponent
{
private:
  sf::Sprite&        sprite;
  sf::RectangleShape hitbox;
  float              offset_x;
  float              offset_y;

public:
  HitboxComponent(sf::Sprite& sprite, float x, float y);

  bool colision(const sf::FloatRect& rect);

  void update();
  void render(sf::RenderTarget* target);
};