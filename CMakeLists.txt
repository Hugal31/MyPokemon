cmake_minimum_required(VERSION 3.2)
project(MyPokemon)

include_directories(include/)
include_directories(/usr/local/lib/boost_1_58_0/include/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

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

set(HEADER_FILES
    include/no_warnings.hpp
    include/game/AbstractTrainer.hpp
    include/game/AI.hpp
    include/game/Combat.hpp
    include/game/id.hpp
    include/game/Item.hpp
    include/game/Player.hpp
    include/game/Pokemon.hpp
    include/game/PokemonModel.hpp
    include/game/Skill.hpp
    include/game/Stat.hpp
    include/game/StatModel.hpp
    include/game/Trainer.hpp
    include/game/Type.hpp
    include/game/WildTrainer.hpp
    include/game/xp.hpp)

link_directories(/usr/local/lib/boost_1_58_0/lib/)
link_libraries(boost_serialization)

add_executable(MyPokemon ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(MyPokemon boost_serialization)