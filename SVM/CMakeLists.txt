cmake_minimum_required(VERSION 3.9)
project(SVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(SVM main.cpp src/SVM.cpp include/SVM.h src/value.cpp include/value.h src/register.cpp include/register.h)