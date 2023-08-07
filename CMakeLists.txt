cmake_minimum_required(VERSION 3.20)
project(Necerini_LabProgrammazione)
set(GOOGLETEST_VERSION 1.14.0)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Test)
set(SOURCE_FILES ShoppingList.cpp ShoppingList.h Observer.h User.cpp User.h Subject.h Item.cpp Item.h)

add_executable(Necerini_LabProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Necerini_LabProgrammazione core)
