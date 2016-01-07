//Implement an algorithm to find the nth to last element of a singly linked list.

struct Node {
  int data;
  Node* next;
};

Node* find_nth_to_last(Node* head, int n) {
  if(head == NULL || n < 1)
    return NULL;

  Node* p1 = head;
  Node* p2 = head;

  //n is the minimum number of nodes in the list

  //distance p2, n nodes from p1
  for(int i=0; i < n; i++) {
    if(p2->next == NULL)
      return NULL;
    p2 = p2->next;
  }

  while(p2->next != NULL) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}

/*
 * returns pointer to the LL element at (size - n) element.
*/
Node* find_nth_to_last(Node* head, int n) {

  if(n < 0 || head == NULL)
    return NULL;

  Node* current = head;
  int count = 0;
  while (current != NULL) {
    /* code */
    count++;
    current = current->next;
  }

  //n should not exceed count
  if(n > count - 1)
    return NULL;

  current = head;
  int stop = count - 1 - n;
  while(current != NULL) {
    if(stop == 0)
      return current;
    stop--;
    current = current->next;
  }

  return NULL;
}
