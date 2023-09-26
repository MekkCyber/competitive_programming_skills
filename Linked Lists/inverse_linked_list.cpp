/*
    Inverse the linked list in place
*/

using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList* reverseLinkedList(LinkedList* head) {
  LinkedList* parent = head;
  LinkedList* curr = parent->next;
  parent->next = nullptr;
  while (curr){
    LinkedList* temp = curr->next;
    curr->next = parent;
    parent = curr;
    curr = temp;
  }
  return parent;
}