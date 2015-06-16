QT+=	core gui widgets

SOURCES+=	../src/game/Pokemon/PokemonModel.cpp			\
		../src/game/Type.cpp					\
                ../src/game/Stat/StatModel.cpp				\

INCLUDEPATH+=	../include						\
		/usr/local/lib/boost_1_58_0/include			\

LIBS+=		-lQt5Widgets						\
                -L/usr/local/lib/boost_1_58_0/lib -lboost_serialization

QMAKE_CXX=	clang++

QMAKE_CXXFLAGS+=      -std=c++11