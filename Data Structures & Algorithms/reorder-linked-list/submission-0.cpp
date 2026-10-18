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
        if (head == nullptr || head->next == nullptr) return;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *curr = slow->next;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        slow->next=nullptr;
        curr = head;
        if (fast != nullptr) prev = fast;
        while (curr != nullptr && prev!=nullptr) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = prev;
            curr = prev->next;
            prev = temp;
        }
    }
};
