#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
  : sprite(sprite), texture(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{
  for (std::map<std::string, Animation*>::iterator it = this->animationSheet.begin();
       it != this->animationSheet.end(); ++it)
    delete it->second;
}

void AnimationComponent::startAnimation(std::string animationName) {}
void AnimationComponent::resetAnimation(std::string animationName) {}
void AnimationComponent::endAnimation(std::string animationName) {}
void AnimationComponent::addAnimation(std::string animationName, float timer, int x,
                                      int y, int x2, int y2, int width, int height)
{
  Animation* temp =
    new Animation(this->sprite, this->texture, timer, x, y, x2, y2, width, height);
  this->animationSheet[animationName] = temp;
}
void AnimationComponent::play(std::string animationName, const float& dt)
{
  this->animationSheet[animationName]->play(dt);
}