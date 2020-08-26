#pragma once

#include "PCH.hpp"

class AnimationComponent
{
private:
  class Animation
  {
  public:
    // variables
    sf::Sprite&  sprite;
    sf::Texture& texture;
    float        animationTimer;
    float        timer;
    int          width;
    int          height;
    sf::IntRect  startRect;
    sf::IntRect  currentRect;
    sf::IntRect  endRect;

    Animation(sf::Sprite& sprite, sf::Texture& texture, float timer, int x, int y, int x2,
              int y2, int width, int height)
      : sprite(sprite), texture(texture)
    {
      this->timer = 0;
      this->width = width;
      this->height = height;
      this->animationTimer = timer;
      this->startRect = sf::IntRect(x * width, y * height, width, height);
      this->currentRect = this->startRect;
      this->endRect = sf::IntRect(x2 * width, y2 * height, width, height);
      this->sprite.setTexture(this->texture, true);
      this->sprite.setTextureRect(this->startRect);
    }

    // functions
    void play(float dt)
    {
      this->timer += 100.f * dt;
      if (this->timer >= this->animationTimer)
      {
        this->timer = 0.f;
        if (this->currentRect != this->endRect)
        {
          this->currentRect.left += this->width;
        }
        else
        {
          this->reset();
        }
      }
      this->sprite.setTextureRect(this->currentRect);
    }
    void stop();
    void reset()
    {
      this->timer = 0.f;
      this->currentRect = this->startRect;
    }
  };
  std::map<std::string, std::unique_ptr<Animation>> animationSheet;
  sf::Sprite&                                       sprite;
  sf::Texture&                                      texture;

public:
  AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);

  ~AnimationComponent();
  void update(float dt);
  void startAnimation(const std::string& animationName);
  void resetAnimation(const std::string& animationName);
  void endAnimation(const std::string& animationName);
  void addAnimation(const std::string& animationName, float timer, int x, int y, int x2,
                    int y2, int width, int height);
  void play(const std::string& animationName, float dt);
};
