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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* lk = head;
        for (int i = 0; i < k; i++) {
            if (!lk) return head;
            lk = lk->next;
        }
        ListNode *curr = head, *prev = nullptr;
        while (curr != lk) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* revNext = reverseKGroup(lk, k);
        head->next = revNext;
        return prev;
    }
};
