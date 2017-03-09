/*
 * LinkedList.cpp
 * Defines an implementation for the Linked List ADT. Contains methods for
 * inserting/deleting/looking up elements and printing the list.
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#include "LinkedList.h"

/*
 * Default constructor
 * Constant Time
 */
LinkedList::LinkedList() {
  this->head = NULL;
  this->tail = NULL;
  size = 0;
}

/*
 * Copy constructor
 * Worst case O(n)
 */
LinkedList::LinkedList(LinkedList& other) {
  head = NULL;
  tail = NULL;
  size = 0;
  // int size = other.getSize();
  Node* curr = other.getHead();
  while(curr != NULL) {
    this->add(curr->data);
    curr = curr->next;
  }
}

/*
 * Destructor
 * O(n)
 */
LinkedList::~LinkedList() {
  Node* curr = head;
  while(head != NULL) {
    head = head->next;
    delete curr;
    curr = head;
  }
  head = NULL;
  tail = NULL;
}

/*

 * Returns a reference to the head Node
 * Constant time
 */
LinkedList::Node* LinkedList::getHead() const {
  return head;
}

/*
 * Returns a reference to the tail Node
 * Constant time

 */
LinkedList::Node* LinkedList::getTail() const {
  return tail;
}

/*
 * Returns the list's size
 * Constant time
 */
int LinkedList::getSize() const {
  return size;
}

/*
 * Returns a reference to the Node at the specified index

 * NULL is returned for an invalid index
 * Worst case O(n/2)
 */
LinkedList::Node* LinkedList::at(int index) const {
  if(index < 0 || index >= size) {
    return NULL;
  }

  Node* curr = NULL;
  if(index < size/2) {
    curr = head;
    for(int i=0; i < index; i++) {
      curr = curr->next;
    }
  }
  else {
    curr = tail;
    for(int i=size-1; i > index; i--) {
      curr = curr->prev;
    }
  }

  return curr;
}

/*
 * Adds a value to the end of the linked list
 * Constant time
 */
void LinkedList::add(int toAdd) {
  if(head == NULL) {
    Node* newNode = new Node();
    newNode->data = toAdd;
    head = newNode;
    tail = newNode;
    size++;
  }
  else {
    Node* curr = tail;
    Node* newNode = new Node();
    newNode->data = toAdd;
    curr->next = newNode;
    newNode->prev = curr;
    size++;
    tail = newNode;
  }
}

/*
 * Deletes the node at the specified index from the list, returns true if valid index (successful)

 * Constant time for the head and tail, O(n-index) worst case for any index inbetween
 */
bool LinkedList::remove(int index) {
  Node* curr = head;
  if(index < 0 || index >= size) {
    return false; // index out of range
  }
  else if(index == 0) {
    if(size != 1) {
      curr->next->prev = NULL;  // disconnect next node's prev
      head = curr->next;        // move head up one
      curr->next = NULL;        // disconnect head from next node
      delete curr;
      curr = NULL;      // remove dangling pointer
    }
    else {
      head = NULL;
      tail = NULL;
      delete curr;
      curr = NULL;
    }
  }
  else if(index == size-1) {
    curr = tail;     // change curr to tail
    curr->prev->next = NULL;  // disconnect previous node from tail
    tail = curr->prev;        // move tail one back
    curr->prev = NULL;        // isolate last Node
    delete curr;
    curr = NULL; // remove dangling pointer
  }
  else {
    for(int i=0; i < index; i++) {
      curr = curr->next;
    }                   //curr should hold the Node at the index to delete
    curr->prev->next = curr->next;  //attach previous to the next Node
    curr->next->prev = curr->prev;  //attach next node's previous to the previous node
    delete curr;
    curr = NULL; // remove dangling pointer
  }

  size--;
  return true;
}

 /*
 * Sorts the list using insertion sort algorithm
 */
 void LinkedList::sort() {
   Node* curr = head->next; // start at position 2
   int key, toCompare;
   for(int index = 1; index < size; index++) {
     key = curr->data;
     toCompare = curr->prev->data;
     for(int j = index-1; j > 0 && toCompare > key; j--) {
       swap(curr->prev, curr);
     }
     curr = curr->next;
   }
 }

 /*
 * Swaps the Nodes at the 2 indecies provided. Takes O(n) time.
 * firstNode must be in a previous position to secondNode
 */
void LinkedList::swap(LinkedList::Node* firstNode, LinkedList::Node* secondNode) {
  if(index2 < index1) { // swap indecies if first is bigger
    int temp = index1;
    index1 = index2;
    index2 = temp;
  }
  // Node* firstNode = at(index1);
  // Node* secondNode = at(index2);

  // nodes are separated
  if(firstNode->next == secondNode) {
    // not at the head or tail of list
    if(firstNode->prev && secondNode->next) {
      Node* tempNext = firstNode->next;     // assign first's values
      Node* tempPrev = firstNode->prev;     // to temp values.

      firstNode->next->prev = secondNode;   // link values around
      firstNode->prev->next = secondNode;   // first to second

      secondNode->next->prev = firstNode;   // link values around
      secondNode->prev->next = firstNode;   // second to first

      firstNode->next = secondNode->next;              // put first in the
      firstNode->prev = secondNode->prev;             // place of second

      secondNode->prev = tempPrev;                    // put second in the
      secondNode->next = tempNext;                   // place of first
    }
    // tail case
    else if (firstNode->prev) {
      Node* tempNext = firstNode->next;
      Node* tempPrev = firstNode->prev;

      secondNode->prev->next = firstNode;   // adjust tail to first node
      firstNode->prev = secondNode->prev;
      firstNode->next = NULL;
      tail = firstNode;

      secondNode->next = tempNext;    // adjust second node
      secondNode->prev = tempPrev;
      tempPrev->next = secondNode;
      tempNext->prev = secondNode;
    }
    // head case
    else if (secondNode->next) {
      Node* tempNext = secondNode->next;
      Node* tempPrev = secondNode->prev;

      secondNode->prev = NULL;            // adjust head to first node
      secondNode->next = firstNode->next;
      firstNode->next->prev = secondNode;
      head = secondNode;

      firstNode->prev = tempPrev;       // adjust first node
      firstNode->next = tempNext;
      tempPrev->next = firstNode;
      tempNext->prev = firstNode;
    }
    // swap opposite ends when size > 2
    else {
      Node* after = firstNode->next;
      Node* before = secondNode->prev;

      before->next = firstNode;
      after->prev = secondNode;
      firstNode->next = NULL;
      firstNode->prev = before;
      secondNode->prev = NULL;
      secondNode->next = after;

      head = secondNode;
      tail = firstNode;
    }
  }
  // nodes are next to each other
  else {
    // not at the head or tail of list
    if(firstNode->prev && secondNode->next) {
      Node* before = firstNode->prev;
      Node* after = secondNode->next;
      before->next = secondNode;
      after->prev = firstNode;

      secondNode->next = firstNode;
      firstNode->prev = secondNode;
      firstNode->next = after;
      secondNode->prev = before;
    }
    // tail case
    else if(firstNode->prev) {
      Node* before = firstNode->prev;
      before->next = secondNode;
      secondNode->prev = before;
      secondNode->next = firstNode;

      firstNode->next = NULL;
      firstNode->prev = secondNode;
      tail = firstNode;
    }
    // head case
    else if(secondNode->next){
      Node* after = secondNode->next;
      after->prev = firstNode;
      firstNode->next = after;
      firstNode->prev = secondNode;

      secondNode->prev = NULL;
      secondNode->next = firstNode;
      head = secondNode;
    }
    // list is size 2
    else {
      head = secondNode;
      tail = firstNode;
      firstNode->prev = secondNode;
      firstNode->next = NULL;
      secondNode->prev = NULL;
      secondNode->next = firstNode;
    }
  }
}

void LinkedList::printForward() const {
  Node* curr = head;
  while(curr != NULL) {
    std::cout << curr->data << ", ";
    curr = curr->next;
  }
  std::cout << "\n";
}

void LinkedList::printBackward() const {
  Node* curr = tail;
  while(curr != NULL) {
    std::cout << curr->data << ", ";
    curr = curr->prev;
  }
  std::cout << "\n";
}
