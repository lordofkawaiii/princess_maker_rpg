#pragma once
#include "PCH.hpp"

enum BUTTON_STATE
{
  IDLE = 0,
  PRESSED = 1,
  HOVER = 2
};

class Button
{
private:
  unsigned short id;
  unsigned short buttonState;
  bool           pressed;
  bool           hover;

  sf::RectangleShape rect;
  sf::Font*          font;
  sf::Text           text;

  // colors
  sf::Color idleColor;
  sf::Color hoverColor;
  sf::Color activeColor;
  sf::Color outlineIdleColor;
  sf::Color outlineHoverColor;
  sf::Color outlineActiveColor;
  sf::Color idleText;
  sf::Color hoverText;
  sf::Color activeText;

public:
  Button(float x, float y, float width, float height, std::string text, sf::Font* font,
         unsigned characterSize, sf::Color idleText, sf::Color hoverText,
         sf::Color activeText, sf::Color idleColor, sf::Color hoverColor,
         sf::Color activeColor, sf::Color outlineIdleColor = sf::Color::Transparent,
         sf::Color outlineHoverColor = sf::Color::Transparent,
         sf::Color outlineActiveColor = sf::Color::Transparent, unsigned short id = 0);
  ~Button();

  void           update(const sf::Vector2f mousePosition);
  void           render(sf::RenderTarget* target);
  bool           isPressed();
  void           setPosition(const float windowWidth, const float windowHeight);
  void           setPosition(sf::Vector2f positions);
  sf::Vector2f   getSize();
  void           setSize(const float width, const float height);
  bool           isCursorIn(const sf::Vector2f mousePosition);
  void           setClicked();
  void           resetSate();
  void           setText(std::string newString);
  std::string    getText();
  sf::Vector2f   getPosition();
  void           updateTextSize();
  short unsigned getId();
  void           setId(unsigned short id);
};
