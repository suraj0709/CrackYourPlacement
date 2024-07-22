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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        while(head != NULL&& head->val == val)
            head = head->next;

        ListNode* curr = head;
        while(curr != NULL){
            if((curr->next != NULL) && curr->next->val == val){
                ListNode* temp = curr->next->next;
                ListNode* NodeToDelete = curr->next;
                curr->next = temp;
                delete(NodeToDelete);
            }
            else
                curr = curr->next;
        }
        return head;
    }
};
