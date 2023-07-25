cmake_minimum_required(VERSION 3.20)
project(Necerini_LabProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_executable(Necerini_LabProgrammazione main.cpp Item.h Item.cpp Observer.cpp Observer.h Subject.cpp Subject.h ShoppingList.cpp ShoppingList.h User.cpp User.h)
