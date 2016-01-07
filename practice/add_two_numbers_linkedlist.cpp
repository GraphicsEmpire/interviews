/*
 * You have two numbers represented by a linked list, where each node contains
 * a single digit. The digits are stored in reverse order, such that the 1’s
 * digit is at the head of the list. Write a function that adds the two numbers
 * and returns the sum as a linked list.
 * EXAMPLE Input: (3 -> 1 -> 5), (5 -> 9 -> 2) Output: 8 -> 0 -> 8
 */

 Node* add(Node* a, Node* b) {

   Node* r = new Node(0);
   Node* r_head = r;
   int carry = 0;
   int da = 0;
   int db = 0;
   while(a || b) {
     da = 0;
     db = 0;
     if(a) {
       da = a->data;
       a = a->next;
     }

     if(b) {
       db = b->data;
       b = b->next;
     }

     r->data = (da + db + carry) % 10;
     carry = (da + db + carry) / 10;

     if(a || b) {
       Node* nr = new Node(0);
       r->next = nr;
     }
     else
      r->next = NULL;
   }


   return r_head;
 }
