cmake_minimum_required(VERSION 3.10)
project(bomberman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g3 -fpermissive")


include_directories(irrlicht/include)

LINK_DIRECTORIES(irrlicht/lib/Linux /usr/X11R6/lib64 /usr/include/sfml)

add_executable(bomberman
               Parametre.cpp
               main.cpp
               Input.cpp
               Init_game.cpp
               Graphical.cpp
               Graphical_menu.cpp
               Graphical_game.cpp
               Assets2DHandler.cpp
               Assets3DHandler.cpp
               Menu_bouton.cpp
               Player_select.cpp
               Jukebox.cpp
               ##Chara_in_game.cpp
               )

target_link_libraries (bomberman Irrlicht GL Xxf86vm Xext X11 sfml-audio)