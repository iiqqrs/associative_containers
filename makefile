##Makefile for the project
##You can create a new variable for each class and include what classes need to be compiled along with it

COMPILER = g++
CCFLAGS1 = -g
CCFLAGS2 = -Wall

HMAP: hmap.cpp
	g++ -std=c++11 main.cpp hmap.cpp llist.cpp
DARRAY: darray.cpp
	g++ -std=c++11 main.cpp darray.cpp llist.cpp
LLIST: llist.cpp
	g++ -std=c++11 main.cpp llist.cpp
STRUCTURES:
	g++ -std=c++11 main.cpp llist.cpp hmap.cpp darray.cpp
