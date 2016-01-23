/*
 * Given a sorted (increasing order) array, write an algorithm to create a
 * binary tree with minimal height.
 */

struct Node {
  Node(int d, Node* l, Node* r) {
    data= d;
    left= l;
    right= r;
  }

  int data;
  Node* left;
  Node* right;
}

Node* create_bintree(int* a, int len) {

  Node* root = new Node(a[0], NULL, NULL);

  Queue<Node*> q;
  q.add(root);

  int i=1;
  while(i < len) {
    Node* a = new Node(a[i], NULL, NULL);

    Node* h = q.front();

    if(h->left == NULL)
      h->left = a;
    else if(h->right == NULL) {
      h->right = a;
      q.remove();
    }

    q.add(a);
    i++;
  }
}


Node* create_min_height_bst(int a[], int len, int start, int end) {
  if(end < start) {
    return NULL;
  }

  Node* n = new Node();
  int mid = (start + end)/2;
  n->left = create_min_height_bst(a, len, start, mid);
  n->right = create_min_height_bst(a, len, mid + 1, end);
  return n;
}

Node* create_min_height_bst(int a[], int len) {
  return create_min_height_bst(a, len, 0, len-1);
}
