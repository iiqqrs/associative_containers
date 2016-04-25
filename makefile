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
SETS:
	g++ -std=c++11 main.cpp llist.cpp set_llist.cpp set_hmap.cpp darray.cpp hmap.cpp
MULTISETS:
	g++ -std=c++11 main.cpp multiset_llist.cpp llist.cpp multiset_darray.cpp darray.cpp multiset_hmap.cpp hmap.cpp
MAPS:
	g++ -std=c++11 main.cpp map_llist.cpp llist.cpp map_darray.cpp darray.cpp map_hmap.cpp hmap.cpp
MULTIMAPS:
	g++ -std=c++11 main.cpp multimap_darray.cpp darray.cpp llist.cpp multimap_llist.cpp multimap_hmap.cpp hmap.cpp
MAIN:
	g++ -std=c++11 main.cpp darray.cpp llist.cpp hmap.cpp multiset_darray.cpp multiset_llist.cpp multiset_hmap.cpp map_darray.cpp map_hmap.cpp map_llist.cpp