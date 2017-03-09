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
 * Swaps the Nodes at the 2 indecies provided. Takes O(n) time.
 */
void LinkedList::swap(int index1, int index2) {
  Node* firstNode = at(index1);
  Node* secondNode = at(index2);

  Node* tempNext = firstNode->next;     // assign first's values
  Node* tempPrev = firstNode->prev;     // to temp values.

  if (firstNode->next != NULL) firstNode->next->prev = secondNode;   // link values around
  if (firstNode->prev != NULL) firstNode->prev->next = secondNode;   // first to second

  if (secondNode->next != NULL) secondNode->next->prev = firstNode;   // link values around
  if (secondNode->next != NULL) secondNode->prev->next = firstNode;   // second to first

  firstNode->next = secondNode->next;     // put first in the
  firstNode->prev = secondNode->prev;     // place of second

  secondNode->prev = tempPrev;       // put second in the
  secondNode->next = tempNext;       // place of first

  // std::cout << first->next->data << ", " << first->prev->data << "\n";
  // std::cout << firstNode->data << ": " << firstNode->prev->data << ", " << firstNode->next->data << "\n";
  // std::cout << second->next->data <<  ", " << second->prev->data <<"\n";
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
