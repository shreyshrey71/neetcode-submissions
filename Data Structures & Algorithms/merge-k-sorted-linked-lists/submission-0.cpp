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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (ListNode* l : lists) {
            if (l) pq.push(l);
        }
        while (!pq.empty()) {
            ListNode* l = pq.top();
            pq.pop();
            if (l->next) pq.push(l->next);
            curr->next = l;
            curr = curr->next;
        }
        curr = head->next;
        delete (head);
        return curr;
    }
};
