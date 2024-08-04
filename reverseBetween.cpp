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
    void fillList(ListNode* head, int left, int right, vector<int> &list){
        int cnt = 1;
        while(head){
            if(cnt>=left && cnt<=right){
                list.push_back(head->val);
            }
            cnt++;
            head = head->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> list;
        fillList(head, left, right, list);
        
        int cnt = 1;
        int size = list.size()-1;
        ListNode* temp = head;
        while(head){
            if(cnt>=left && cnt<=right && size>=0){
                head->val = list[size--];
            }
            cnt++;
            head = head->next;
        }
        return temp;
    }
};
