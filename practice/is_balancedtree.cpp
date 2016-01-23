/*
 * Check if a tree is balanced
 */

struct Node {
  Node* left;
  Node* right;
  int data;
}

bool is_leaf(Node* n) {
  return (n->left == NULL && n->right == NULL);
}

int min_depth(Node* n) {
  if(n == NULL)
    return 0;

  return 1 + min(min_depth(n->left), min_depth(n->right));
}

int max_depth(Node* n) {
  if(n == NULL)
    return 0;

  return 1 + max(max_depth(n->left), max_depth(n->right));
}


bool is_balanced(Node* root) {
  return((max_depth(root) - min_depth(root)) <= 1);
}
