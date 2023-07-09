/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* temp = head, *ptr = head;
        int len = length(head);
        if(k>len){
            k = k%len;
        }
        while(k--){
            while(temp->next != NULL){
                ptr = temp;
                temp = temp->next;
            }
            temp->next = head;
            ptr->next = NULL;
            head = temp;
        }
        return head;
    }
};