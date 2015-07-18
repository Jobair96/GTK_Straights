cmake_minimum_required(VERSION 3.2)
project(Project_1)

# Find the GTK module using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-2.4) # look into FindPkgConfig.cmake, # it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )
link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

add_definitions(${GTKMM_CFLAGS_OTHER})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Project_1 ${SOURCE_FILES} Card.h Card.cpp Computer.h Computer.cpp Controller.h Controller.cpp Deck.h Deck.cpp Human.h Human.cpp Model.cpp Model.h Model.cpp Player.h Player.cpp View.h View.cpp TableCards.cpp TableCards.h Subject.cpp Subject.h Observer.h DeckGUI.cpp DeckGUI.h)
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
