cmake_minimum_required(VERSION 3.25)
project(gr_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(gr_test main.cpp Employee.h Employee.cpp Keeper.h Keeper.cpp Menu.h Menu.cpp Student.h Student.cpp Teacher.h Teacher.cpp)

# include_directories(bgi)