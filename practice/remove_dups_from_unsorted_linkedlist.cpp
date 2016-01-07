
struct Node {
  int data;
  Node* next;
};

int remove_dups_linkedlist(Node* head) {

  Node* current = head;

  int dups = 0;
  while(current != NULL) {
    int data = current->data;

    Node* prev = current;
    Node* child = current->next;

    while(child != NULL) {
      if(child->data == data) {
        prev->next = child->next;
        child = child->next;
      }
    }

    current = current->next;
  }
}
