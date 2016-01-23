


//permute a linked list

//1->2->3->4->5->6
Node* swap_list(Node* root) {

  //
  Node* nlh = NULL;
  Node* tmp = root;
  while(tmp != NULL) {
    Node* cn = tmp->next;
    tmp->next = nlh;
    nlh = tmp;
    tmp = cn;

    printf("Current list head is: %d", nlh->data);
  }

  return nlh;
}


//1, 2, 3, 4, 5 ,6



Node* permute_list(Node* root) {

  //count list
  int n = 0;
  Node* tmp = root;
  while(tmp != NULL) {
    tmp = tmp->next;
    n++;
  }

  //get to a pointer to a certain index
  Node* sech = NULL;
  tmp = root;
  int h = n/2;
  while(tmp != NULL && h > 0) {
    tmp = tmp->next;
    h--;
  }


  sech = tmp;
  sech = swap_list(sech);

  tmp = root;

  Node* cur2 = sech;
  for(int i=0; i < n/2; i++) {
    Node* cur1 = tmp;
    Node* cn = cur1->next;
    cur1->next = cur2;
    cur1->next->next = cn;

    cur2 = cur2 ->next;
  }

  return root;
}

/*
list:  1, 2 , 3
tmp: 3
nlh: 3 -> 2 ->1 -> NULL

tmp = NULL
cn: NULL
*/
