#include<iostream>
#include "LinkedList.h"

int main() {
  LinkedList myList;
  myList.add(1);
  myList.add(2);
  myList.add(3);
  myList.add(4);
  myList.add(5);
  myList.add(6);
  myList.add(7);
  myList.add(8);
  myList.add(9);
  myList.add(0);

  myList.printForward();
  myList.swap(0, 3);
  myList.printForward();
}
