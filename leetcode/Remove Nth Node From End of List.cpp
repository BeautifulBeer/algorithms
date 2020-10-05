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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0, target, idx;
        ListNode* cur = head;
        while(cur != nullptr){
            cur = cur->next;
            total++;
        }
        target = total - n - 1;
        idx = 0;
        cur = head;
        while(idx < target && cur != nullptr){
            cur = cur->next;
            idx++;
        }
        if(target == -1){
            head = head->next;
        }else{
            cur->next = cur->next->next;
        }
        return head;
    }
};