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

LinkedList* shiftLinkedList(LinkedList* head, int k) {
  LinkedList* current = head;
  LinkedList* current_k = head;
  int length = 0;
  while (current){
    length++;
    current = current->next;
  }
  int positive_k = (k%length+length)%length;
  if (!positive_k) return head;
  current = head;
  for (int i = 0; i<positive_k; i++){
    current_k = current_k->next;
  }
  while (current_k->next){
    current = current->next;
    current_k = current_k->next;
  }
  LinkedList* newStart = current->next;
  current_k->next = head;
  current->next = nullptr;
  
  return newStart;
}
