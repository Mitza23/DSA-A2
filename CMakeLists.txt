cmake_minimum_required(VERSION 3.16.3)
project(A2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h DLLNode.h DLL.h)
