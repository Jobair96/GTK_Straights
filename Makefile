CXX = g++
CXXFLAGS = -std=c++0x
OBJECTS = main.o Card.o Command.o Computer.o Controller.o Deck.o Human.o Model.o Player.o TableCards.o View.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
