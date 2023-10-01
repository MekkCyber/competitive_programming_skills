/*
    Write a function that takes in the head of a Singly Linked List, swaps every
    pair of adjacent nodes in place (i.e., doesn't create a brand new list), and
    returns its new head.
    If the input Linked List has an odd number of nodes, its final node should
    remain the same.
    Ex : head = 0 ; 1 ; 2 ; 3 ; 4 ; 5 // the head node with value 0
    output : 0 ; 3 ; 2 ; 5 ; 4 // the new head node with value 1

*/

using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* nodeSwap(LinkedList* head) {
  LinkedList* currentNode = head;
  while (currentNode && currentNode->next){
    LinkedList* nextNode = currentNode->next;
    swap(currentNode->value,nextNode->value);
    currentNode = nextNode->next;
  }
  return head;
}


// An other approach with pointers 

using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* nodeSwap(LinkedList* head) {
  LinkedList* temp = new LinkedList(0);
  temp->next = head;
  LinkedList* prevNode = temp;
  while (prevNode->next && prevNode->next->next){
    LinkedList* first = prevNode->next;
    LinkedList* second = prevNode->next->next;
    // prevNode -> first -> second -> x
    first->next = second->next;
    second->next = first;
    prevNode->next = second;
    // prevNode -> second -> first -> x
    prevNode = first;
  }
  return temp->next;
}
