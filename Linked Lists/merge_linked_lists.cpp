/*
  Write a function that takes in the heads of two Singly Linked Lists that are
  in sorted order, respectively. The function should merge the lists in place
  (i.e., it shouldn't create a brand new list) and return the head of the merged
  list; the merged list should be in sorted order.
*/

#include <vector>

using namespace std;
class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};


LinkedList* mergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {
  LinkedList* currentOne = headOne;
  LinkedList* parentOne = nullptr;
  LinkedList* currentTwo = headTwo;
  LinkedList* parentTwo = nullptr;
  while (currentOne || currentTwo){
    int oneValue = currentOne ? currentOne->value : INT_MAX;
    int twoValue = currentTwo ? currentTwo->value : INT_MAX;
    if (oneValue<=twoValue){
      parentOne = currentOne;
      if (parentTwo){
        parentTwo->next = currentOne;
        parentTwo = nullptr;
      }
      currentOne = currentOne->next;
    } else {
      parentTwo = currentTwo;
      if (parentOne){
        parentOne->next = currentTwo;
        parentOne = nullptr;
      }
      currentTwo = currentTwo->next;
    }
  }
  return headOne->value > headTwo->value ? headTwo : headOne;
}

/*
    the idea presented in their solution of using only one Prev variable is interesting too, the idea is that after every iteration 
    when we are in the second list, in the end the prev is updated to point to the current node in the first list, this way in we dont have to 
    examine the case when we switch pointers from the second list to the first list like i did in my code 
*/ 

#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList* mergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {
  LinkedList* currentOne = headOne;
  LinkedList* parentOne = nullptr;
  LinkedList* currentTwo = headTwo;
  LinkedList* parentTwo = nullptr;
  while (currentOne || currentTwo){
    int oneValue = currentOne ? currentOne->value : INT_MAX;
    int twoValue = currentTwo ? currentTwo->value : INT_MAX;
    if (oneValue<=twoValue){
      parentOne = currentOne;
      /*if (parentTwo){
        parentTwo->next = currentOne;
        parentTwo = nullptr;
      }*/
      currentOne = currentOne->next;
    } else {
      //parentTwo = currentTwo;
      if (parentOne){
        parentOne->next = currentTwo;
        //parentOne = nullptr;
      }
      parentOne = currentTwo;// added
      currentTwo = currentTwo->next;
      parentOne->next = currentOne;//added : go back to first list
    }
  }
  return headOne->value > headTwo->value ? headTwo : headOne;
}
