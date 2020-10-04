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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* cur = nullptr;
        int carry = 0, tmp = 0;
        while(l1 != nullptr && l2 != nullptr){
            tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            if(result == nullptr){
                result = new ListNode(tmp % 10);
                cur = result;
            }else{
                cur->next = new ListNode(tmp % 10);
                cur = cur->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr){
            tmp = l1->val + carry;
            carry = tmp / 10;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            tmp = l2->val + carry;
            carry = tmp / 10;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            l2 = l2->next;
        }
        
        if(carry > 0){
            cur->next = new ListNode(carry);
        }
        
        return result;
    }
};