cmake_minimum_required(VERSION 3.10)
project("Main.cpp")

set(CMAKE_CXX_STANDARD 11)

add_executable(page "Main.cpp" Block.cpp Block.h Blocks.cpp Blocks.h PageRequest.cpp PageRequest.h Memory.cpp Memory.h PageReplacementAlgorithm.cpp PageReplacementAlgorithm.h RequestSequence.cpp RequestSequence.h)