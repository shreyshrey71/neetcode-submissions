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
        ListNode* head = new ListNode();
        ListNode* l3 = head;
        int carry = 0;
        while (l1 || l2 || carry != 0) {
            int sum = (l1) ? l1->val : 0;
            sum += (l2) ? l2->val : 0;
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            l3->next = new ListNode(sum);
            l3 = l3->next;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        l3 = head->next;
        delete (head);
        return l3;
    }
};
