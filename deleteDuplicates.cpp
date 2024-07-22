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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* head1 = head;
        ListNode* curr = head -> next;

        while(curr != NULL){
            while(curr != NULL && curr -> val == head1 -> val)
                curr = curr -> next;
            if(curr != NULL){
                head1 -> next = curr;
                head1 = curr;
                curr = curr -> next;
            }
            else
                head1 -> next = curr;
            
        }
        return head;
    }
};
