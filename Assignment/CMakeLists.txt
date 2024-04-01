# CMakeList.txt : CMake project for Assignment, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Assignment "main.cpp" "Choice.h" "Choice.cpp" "ItemManager.h" "ItemManager.cpp" "Util.h" "Util.cpp" "Game.h" "Game.cpp" "StoreItem.h" "StoreItem.cpp" "GameTitle.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Assignment PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
