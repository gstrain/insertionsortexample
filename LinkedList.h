/*
 * LinkedList.h
 * See LinkedList.cpp for method comments on the specific implemenation
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

class LinkedList {

 private:
  struct Node {
    int data;
    Node* next;
    Node* prev;
  };

  Node* head;
  Node* tail;
  int size;

public:
	LinkedList();
  LinkedList(LinkedList& other);
  ~LinkedList();

  LinkedList::Node* getHead() const;
  LinkedList::Node* getTail() const;
  int getSize() const;
  LinkedList::Node* at(int index) const;
  void add(int toAdd);
  bool remove(int index);
  void swap(int index1, int index2);
  void printForward() const;
  void printBackward() const;

};

#endif
