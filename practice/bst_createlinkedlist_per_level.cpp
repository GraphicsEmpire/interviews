/*
 * Given a binary search tree, design an algorithm which creates a linked list
 * of all the nodes at each depth (eg, if you have a tree with depth D, you’ll
 * have D linked lists).
 */
#include <vector>

struct BSTNode {
  int data;
  BSTNode* left;
  BSTNode* right;
}

vector<vector<pair<int, BSTNode*>> > bst_create_list_of_samelevel_nodes(BSTNode* root) {
  vector<vector<pair<int, BSTNode*>> > result;

  int level = 0;
  vector<pair<int, BSTNode*>> level_nodes;
  level_nodes.push(level, root);

  while(true) {
      vector<pair<int, BSTNode*>> current_level_nodes = result.get(level);
      vector<pair<int, BSTNode*>> next_level_nodes;

      for(int i=0; i < current_level_nodes.size(); i++) {
        BSTNode* n = current_level_nodes[i].second;

        if(n->left)
          next_level_nodes.push(make_pair(level + 1, n->left));

        if(n->right)
          next_level_nodes.push(make_pair(level + 1, n->right));
      }

      if(next_level_nodes.size() > 0) {
        result.add(next_level_nodes);
        level++;
      }
      else
        break;
  }

  return result;
}
