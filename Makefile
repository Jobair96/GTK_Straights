CXX = g++
CXXFLAGS = -std=c++0x -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = main.o Card.o Computer.o Controller.o Deck.o Human.o Model.o Player.o TableCards.o View.o DeckGUI.o Subject.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS}-o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
