cmake_minimum_required(VERSION 3.15)

project(princess_maker_rpg
  VERSION 0.1.0
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES CXX)

add_executable(princess_maker_rpg)
target_sources(princess_maker_rpg 
      PRIVATE 
        Game.cpp Game.h 
        main.cpp 
        states/State.h states/State.cpp 
        states/GameState.h states/GameState.cpp
      )

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_include_directories(princess_maker_rpg 
      PRIVATE 
        states
        entities
)
target_link_libraries(princess_maker_rpg PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)