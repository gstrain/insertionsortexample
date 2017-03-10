#include<iostream>
#include <random>
#include "LinkedList.h"

int main() {
  std::random_device rd; // device for seeding generator
  std::mt19937 rng(rd()); // seed random gen with device
  std::uniform_int_distribution<int> dist(0, 100000); // create distribution

  LinkedList myList;

  for(int i=0; i < 100000; i++)
    myList.add(dist(rng));      // populate list with random values
  
  myList.printForward();  // print unsorted
  myList.sort();          // calls embedded insertion sort
  myList.printForward();  // print sorted
}
