#include "Settings.hpp"
Settings::Settings(/* args */)
{
  this->resolution = sf::VideoMode::getDesktopMode();
  this->fullscreen = false;
  this->vSync = false;
  this->frameRateLimit = 120;
  this->context.antialiasingLevel = 0;
  this->videoModes = sf::VideoMode::getFullscreenModes();
}
Settings::~Settings() {}
void Settings::saveToFile(std::string path)
{
  std::ofstream ofs(path);

  if (ofs.is_open())
  {
    ofs << this->title;
    ofs << this->resolution.width << this->resolution.height;
    ofs << this->frameRateLimit;
    ofs << this->vSync;
    ofs << this->fullscreen;
    ofs << this->context.antialiasingLevel;
  }

  ofs.close();
}
void Settings::loadFromFile(std::string path)
{
  std::ifstream ifs(path);

  if (ifs.is_open())
  {
    std::getline(ifs, this->title);
    ifs >> this->resolution.width >> this->resolution.height;
    ifs >> this->frameRateLimit;
    ifs >> this->vSync;
    ifs >> this->fullscreen;
    ifs >> this->context.antialiasingLevel;
  }
  else
  {
    saveToFile(path);
  }

  ifs.close();
}