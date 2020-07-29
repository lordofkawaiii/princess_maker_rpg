cmake_minimum_required(VERSION 3.15)

project(
  princess_maker_rpg
  VERSION 0.1.0
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES CXX)

add_compile_options(
  -Wall
  -Wextra
  -Wswitch-enum
  -pedantic
  -pedantic-errors
  -Werror=write-strings
  -Wconversion
  -Wold-style-cast
  -Wsign-conversion
  -Werror=return-type)

add_executable(princess_maker_rpg)
target_sources(
  princess_maker_rpg
  PRIVATE src/Game.h
          src/Game.cpp
          src/main.cpp
          src/states/State.h
          src/states/State.cpp
          src/states/GameState.h
          src/states/GameState.cpp
          src/entities/Entity.h
          src/entities/Entity.cpp
          src/states/MainMenuState.h
          src/states/MainMenuState.cpp
          src/UI/Button.h
          src/UI/Button.cpp
          src/entities/Player.h
          src/entities/Player.cpp
          src/entities/components/MovementComponent.h
          src/entities/components/MovementComponent.cpp
          src/entities/components/AnimationComponent.h
          src/entities/components/AnimationComponent.cpp)

target_compile_features(princess_maker_rpg PRIVATE cxx_std_17)

find_package(
  SFML 2.5
  COMPONENTS system window graphics network audio
  REQUIRED)
target_include_directories(princess_maker_rpg PRIVATE src)
target_link_libraries(
  princess_maker_rpg PRIVATE sfml-system sfml-window sfml-graphics sfml-network
                             sfml-audio)
