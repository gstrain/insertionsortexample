#
# makefile for Project 1 Stack Calculator
# 2-21-2017
#

CC = g++
FLAGS = -std=c++11

all:main

main:  LinkedList.o main.o
	${CC} ${FLAGS} LinkedList.o main.o -o InsertionSort
LinkedList.o:
	${CC} ${FLAGS} -c LinkedList.cpp
main.o:
	${CC} ${FLAGS} -c main.cpp
clean:
	rm *.o
run: main
	./InsertionSort
	rm *.o
	rm ./InsertionSort
