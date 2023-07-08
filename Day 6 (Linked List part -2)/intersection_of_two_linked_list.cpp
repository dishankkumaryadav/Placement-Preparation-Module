/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA, *node2 = headB;
        int count1 = 0, count2 = 0;
        while(node1!= NULL){
            node1 = node1->next;
            count1++;
        }
        while(node2!=NULL){
            node2 = node2->next;
            count2++;
        }
        node1 = headA, node2 = headB;
        int diff = 0;
        if(count1 > count2){
            diff = count1 - count2;
            count1 = 0;
            while(count1 != diff){
                node1 = node1->next;
                count1++;
            }
        }
        else{
            diff = count2 - count1;
            count2 = 0;
            while(count2 != diff){
                node2 = node2->next;
                count2++;
            }
        }
        while(node1 != node2){
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};