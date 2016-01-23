/*
 * Given a directed graph, design an algorithm to find out whether there is a
 * route between two nodes.
 */

typedef enum VISIT_STATE {unvisited, visited, visiting};

 struct Node {
   list<Node*> children;
   int data;
   VISIT_STATE state;
 }



 bool is_route(Graph* g, Node* start, Node* end) {
   stack<Node*> stk;

   start->state = visiting;
   stk.push(start);

   while(!stack.isempty()) {
     Node* u = stk.pop();

     if(u) {
       foreach(n in u->children) {
         if(n == end)
           return true;
         else if(n->state != visited) {
           n->state = visiting;
           stk.push(n);
         }
       }

       u->state = visited;
     }

   }

   return false;
 }
