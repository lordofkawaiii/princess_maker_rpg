#include "HitboxComponent.hpp"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float x, float y) : sprite(sprite)
{
  this->hitbox = sf::RectangleShape();
  this->hitbox.setPosition(this->sprite.getPosition().x + x - 1,
                           this->sprite.getPosition().y + y);
  this->hitbox.setSize(sf::Vector2f(this->sprite.getGlobalBounds().width - (2.f * x),
                                    this->sprite.getGlobalBounds().height - (2.f * y)));
  this->offset_x = x;
  this->offset_y = y;
  this->hitbox.setFillColor(sf::Color::Transparent);
  // this->hitbox.setOutlineThickness(1.0);
  // this->hitbox.setOutlineColor(sf::Color::Blue);
  // this->hitbox.setFillColor(sf::Color::Blue);
}

void HitboxComponent::update()
{
  this->hitbox.setPosition(sf::Vector2f(this->sprite.getPosition().x + this->offset_x - 1,
                                        this->sprite.getPosition().y + this->offset_y));
}
void HitboxComponent::render(sf::RenderTarget* target)
{
  target->draw(this->hitbox);
  // std::cout << this->hitbox.getSize().x << " " << this->hitbox.getSize().x << std::endl;
}

bool HitboxComponent::colision(const sf::FloatRect& rect)
{
  return this->hitbox.getGlobalBounds().intersects(rect);
}
