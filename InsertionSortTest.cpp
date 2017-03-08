#include<iostream>
#include "LinkedList.h"

int main() {
  LinkedList myList;
  myList.add(1);
  myList.add(2);
  myList.add(3);
  myList.add(4);
  myList.add(5);

  myList.printForward();
  myList.swap(1, 2);
  myList.printForward();
}
