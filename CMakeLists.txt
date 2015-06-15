cmake_minimum_required(VERSION 3.2)
project(MyPokemon)

include_directories(include/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#    editor/src/main.cpp
#    editor/src/editor.cpp
    src/game/Item/Item.cpp
    src/game/Pokemon/Pokemon.cpp
    src/game/Pokemon/PokemonModel.cpp
    src/game/Skill/Skill.cpp
    src/game/Stat/Stat.cpp
    src/game/Stat/StatModel.cpp
    src/game/Type.cpp
    src/game/xp.cpp
    src/main.cpp)

Link_directories(/usr/include/boost/archive/)
Link_directories(/usr/local/share/boost/)

add_executable(MyPokemon ${SOURCE_FILES})