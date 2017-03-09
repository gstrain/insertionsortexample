#include<iostream>
#include <random>
#include "LinkedList.h"

int main() {
  std::random_device rd; // device for seeding generator
  std::mt19937 rng(rd()); // seed random gen with device
  std::uniform_int_distribution<int> dist(0, 100); // create distribution

  LinkedList myList;

  for(int i=0; i < 10; i++) {
    myList.add(dist(rng));      // populate list with random values
  }

  myList.printForward();  // print unsorted
  // myList.sort();          // calls embedded insertion sort

  myList.swap(myList.at(0), myList.at(2));
  myList.swap(myList.at(2), myList.at(4));
  myList.swap(myList.at(4), myList.at(9));
  myList.swap(myList.at(0), myList.at(9));
  myList.swap(myList.at(0), myList.at(1));
  myList.swap(myList.at(1), myList.at(2));
  myList.swap(myList.at(8), myList.at(9));

  myList.printForward();  // print sorted
}
