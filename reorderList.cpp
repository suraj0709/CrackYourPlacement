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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // find middle of the linked list
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // Reverse the half middle of the list
        ListNode* preMiddle = p1;
        ListNode* preCurrent = p1->next;
        while (preCurrent->next != NULL) {
            ListNode* current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        // Start reordering
        p1 = head;
        p2 = preMiddle->next;
        while (p1 != preMiddle) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }
};
