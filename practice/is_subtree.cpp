/*
 * You have two very large binary trees: T1, with millions of nodes, and T2,
 * with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
 */
 struct TreeNode {
   int data;
   TreeNode* left;
   TreeNode* right;
 };

 bool contains_tree(TreeNode* t1, TreeNode* t2) {
   //NULL Tree is always a subtree
   if(t2 == NULL)
     return true;

   return subtree(t1, t2);
}

//traverse r1 so we match the roots with r2
bool subtree(TreeNode* r1, TreeNode* r2) {
  //couldn't match the roots
  if(r1 == NULL)
    return false;

  if(r1->data == r2->data)
    return match_tree(r1, r2);

  return subtree(r1->left, r2) || subtree(r1->right, r2);
}


//compare r1 and r2 node by node
bool match_tree(TreeNode* r1, TreeNode* r2) {
  //both exhausted and no match
  if(r1 == NULL && r2 == NULL)
    return false;

  if(r2 == NULL || r1 == NULL)
    return false;

  if(r1->data != r2->data)
    return false;


  return match_tree(r1->left, r2->left) && match_tree(r1->right, r2->right);
}
