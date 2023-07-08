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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
public:
    bool isPalindrome(ListNode* head) {
        // ListNode* slow = head, *fast = head;
        // while(fast->next->next != NULL && fast->next != NULL){
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // ListNode* temp = reverseList(slow->next);
        // while(temp != NULL){
        //     if(temp->val != head->val)
        //         return false;
        //     head = head->next;
        //     temp = temp->next;
        // }
        // return true;
        vector<int> arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i=0; i<arr.size()/2; i++){
            if(arr[i]!=arr[arr.size() - i - 1])
                return false;
        }
        return true;
    }
};