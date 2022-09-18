cmake_minimum_required(VERSION 3.14)

project(tic-tac-toe-ai)

set(CMAKE_CXX_STANDARD 20)

add_executable(ttt src/main.cc src/board.cc src/search.cc)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

foreach(TEST board search)
  add_executable(${TEST}_tests tests/${TEST}.cc src/search.cc src/board.cc)
  target_link_libraries(${TEST}_tests GTest::gtest_main)
  gtest_discover_tests(${TEST}_tests)
endforeach()
