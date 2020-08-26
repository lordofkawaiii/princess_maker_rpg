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
  PRIVATE src/Game.hpp
          src/Game.cpp
          src/main.cpp
          src/states/State.hpp
          src/states/State.cpp
          src/states/GameState.hpp
          src/states/GameState.cpp
          src/entities/Entity.hpp
          src/entities/Entity.cpp
          src/states/MainMenuState.hpp
          src/states/MainMenuState.cpp
          src/UI/Button.hpp
          src/UI/Button.cpp
          src/entities/Player.hpp
          src/entities/Player.cpp
          src/entities/components/MovementComponent.hpp
          src/entities/components/MovementComponent.cpp
          src/entities/components/AnimationComponent.hpp
          src/entities/components/AnimationComponent.cpp
          src/states/EditorState.hpp
          src/states/EditorState.cpp
          src/entities/components/HitboxComponent.hpp
          src/entities/components/HitboxComponent.cpp
          src/utilities/Tile.hpp
          src/utilities/Tile.cpp
          src/utilities/TileMap.hpp
          src/utilities/TileMap.cpp
          src/UI/PauseMenu.hpp
          src/UI/PauseMenu.cpp
          src/states/SettingState.hpp
          src/states/SettingState.cpp
          src/states/StateWButtons.hpp
          src/states/StateWButtons.cpp
          src/states/StateWPause.hpp
          src/states/StateWPause.cpp
          src/UI/DropDown.hpp
          src/UI/DropDown.cpp)

target_compile_features(princess_maker_rpg PRIVATE cxx_std_17)
target_precompile_headers(princess_maker_rpg PRIVATE src/PCH.hpp)

find_package(
  SFML 2.5
  COMPONENTS system window graphics network audio
  REQUIRED)
target_include_directories(princess_maker_rpg PRIVATE src)
target_link_libraries(
  princess_maker_rpg PRIVATE sfml-system sfml-window sfml-graphics sfml-network
                             sfml-audio)
