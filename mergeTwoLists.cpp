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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* curr1 = head1;
        ListNode* next1 = head1 -> next;
        ListNode* curr2 = head2;
        
        if(curr1 -> next == NULL){
            curr1 -> next = curr2;
            return head1;
        }
        while(next1 != NULL && curr2 != NULL){
            if(curr2 -> val >= curr1 -> val && curr2 -> val < next1 -> val){
                ListNode* temp = curr2 -> next;
                curr1 -> next = curr2;
                curr2 -> next = next1;
                curr2 = temp;
                curr1 = curr1 -> next;
            }
            else{
                curr1 = curr1 -> next;
                next1 = next1 -> next;
                
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return head1;
                }
            }
        }
        return head1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1 -> val <= list2 -> val) return merge(list1, list2);
        else return merge(list2, list1);
    }
};
