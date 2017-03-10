#
# makefile for Project 1 Stack Calculator
# 2-21-2017
#

CC = g++
FLAGS = -std=c++11

all:main

main:  LinkedList.o InsertionSortTest.o
	${CC} ${FLAGS} LinkedList.o InsertionSortTest.o -o InsertionSort
LinkedList.o:
	${CC} ${FLAGS} -c LinkedList.cpp
InsertionSortTest.o:
	${CC} ${FLAGS} -c InsertionSortTest.cpp
clean:
	rm *.o
	rm ./InsertionSort
run: main
	time ./InsertionSort
	make clean
debug:
	${CC} ${FLAGS} -g -c LinkedList.cpp
	${CC} ${FLAGS} -g -c InsertionSortTest.cpp
	${CC} ${FLAGS} -g LinkedList.o InsertionSortTest.o -o InsertionSort
	gdb ./InsertionSort
