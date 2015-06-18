cmake_minimum_required(VERSION 3.2)
project(MyPokemon)

include_directories(include/)
include_directories(/usr/local/lib/boost_1_58_0/include/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
 	src/game/Combat/Combat.cpp
   	src/game/Item/Item.cpp
   	src/game/Pokemon/Pokemon.cpp
   	src/game/Pokemon/PokemonModel.cpp
   	src/game/Stat/Stat.cpp
   	src/game/Stat/StatModel.cpp
   	src/game/Skill/Skill.cpp
   	src/game/Trainer/AbsractTrainer.cpp
   	src/game/Trainer/Player.cpp
   	src/game/Trainer/Trainer.cpp
   	src/game/Trainer/WildTrainer.cpp
   	src/game/Type.cpp
   	src/game/xp.cpp)

Link_directories(/usr/local/lib/boost_1_58_0/lib/)
link_libraries(boost_serialization)

add_executable(MyPokemon ${SOURCE_FILES})

target_link_libraries(MyPokemon boost_serialization)