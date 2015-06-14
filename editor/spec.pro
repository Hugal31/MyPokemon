QT+=	core gui

INCLUDEPATH+=	../include						\
		/usr/local/lib/boost_1_58_0/include			\
                /usr/include/qt5/QtWidgets/				\

LIBS+=		-lQt5Widgets						\
		-Llib/promptomatic -lpromptomatic			\
		-L/usr/local/lib/boost_1_58_0/lib -lboost_serialization

QMAKE_CXX=	clang++ -std=c++11
