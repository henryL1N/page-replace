cmake_minimum_required(VERSION 3.10)
project("Main.cpp")

set(CMAKE_CXX_STANDARD 11)

add_executable(page "Main.cpp" Block.cpp Block.h Memory.cpp Memory.h PageReplacementAlgorithm.cpp PageReplacementAlgorithm.h Request.cpp Request.h PageReplacementAlgorithmTester.cpp PageReplacementAlgorithmTester.h Tools.cpp Tools.h Optimal.cpp Optimal.h FIFO.cpp FIFO.h LRU.cpp LRU.h)