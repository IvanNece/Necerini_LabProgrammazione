cmake_minimum_required(VERSION 3.20)


add_subdirectory(./lib/googletest-main/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES ObserverTest.cpp runAllTests.cpp UserFixture.cpp ShoppingListFixture.cpp ItemTest.cpp)
add_executable(runListsTest ${TEST_SOURCE_FILES})
target_link_libraries(runListsTest gtest gtest_main core)