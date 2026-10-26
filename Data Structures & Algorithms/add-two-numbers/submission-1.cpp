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
        ListNode *dummyHead = new ListNode(-1);
        ListNode *temp = dummyHead, *t1 = l1, *t2 = l2;
        int carry = 0, sum, l1Val, l2Val;
        while(t1 || t2) {
            l1Val = t1 ? t1->val : 0;
            l2Val = t2 ? t2->val : 0;
            sum = (l1Val + l2Val + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            t1 = t1 ? t1->next : t1;
            t2 = t2 ? t2->next : t2;
        }    
        if(carry) {
            temp->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
