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
        ListNode *left = head, *right = head;
        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        if (right == nullptr) {
            ListNode* temp = left;
            left = left->next;
            delete (temp);
            return left;
        }
        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        ListNode* temp = left->next;
        left->next = temp->next;
        delete (temp);
        return head;
    }
};
