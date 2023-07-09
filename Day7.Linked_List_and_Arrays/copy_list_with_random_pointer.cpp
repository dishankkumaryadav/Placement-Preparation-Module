/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        Node* itr = head, *front = head;
        // Step 1: Make copies:-
        while(itr != NULL){
            front = itr->next;
            Node* copy = new Node(itr->val); 
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        // Step 2: join random pointers:-
        itr = head;
        while(itr != NULL){
            if(itr->random != NULL){
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        // Step 3: differentiate original and deep copy list:-
        itr = head;
        Node* copy_head = new Node(0);
        copy_head->next = itr->next;
        while(itr != NULL){
            front = itr->next;
            itr->next = front->next;
            itr = front->next;
            if(itr != NULL)
                front->next = itr->next;
        }
        return copy_head->next;
    }
};