/*
 * Given a circular linked list, implement an algorithm which returns node at
 * the begin- ning of the loop.
 */

 Node* detect_loop(Node* head) {

   if(head == NULL)
      return NULL;
        
   HashMap<Node*, int> visited;
   Node* current = head;

   int count = 0;
   while(current != NULL) {
     if(visited.has(current)) {
       return current;
     }

     visited.insert(make_pair(current, count));
     count++;
     current = current->next;
   }

   return NULL;
 }
