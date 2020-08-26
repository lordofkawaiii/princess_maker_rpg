#pragma once

#include "PCH.hpp"

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