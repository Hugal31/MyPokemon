QT+=	core gui widgets

SOURCES+=	../src/game/Pokemon/PokemonModel.cpp			\
                ../src/game/Pokemon/Pokemon.cpp                         \
		../src/game/Type.cpp					\
                ../src/game/Stat/Stat.cpp                               \
                ../src/game/Stat/StatModel.cpp				\
                ../src/game/Skill/Skill.cpp                             \

INCLUDEPATH+=	../include						\
		/usr/local/lib/boost_1_58_0/include			\

LIBS+=		-lQt5Widgets						\
                -L/usr/local/lib/boost_1_58_0/lib -lboost_serialization

QMAKE_CXX=	clang++

QMAKE_CXXFLAGS+=      -std=c++11 -DEDITOR
