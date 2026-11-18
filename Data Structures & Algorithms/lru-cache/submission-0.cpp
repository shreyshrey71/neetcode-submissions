class LRUCache {
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

   public:
    unordered_map<int, ListNode*> cache;
    int capacity;
    ListNode *first, *last;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        first = new ListNode(0, 0);
        last = new ListNode(0, 0);
        first->next = last;
        last->prev = first;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        ListNode *curr = cache[key], *prev = curr->prev, *next = curr->next;
        prev->next = next;
        next->prev = prev;
        curr->next = first->next;
        curr->next->prev = curr;
        curr->prev = first;
        first->next = curr;
        return curr->val;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            first->next->val = value;
        } else {
            ListNode* curr = new ListNode(key, value);
            curr->next = first->next;
            first->next->prev = curr;
            curr->prev = first;
            first->next = curr;
            cache[key] = curr;
            if (cache.size() > capacity) {
                ListNode* inv = last->prev;
                last->prev = inv->prev;
                inv->prev->next = last;
                cache.erase(inv->key);
                delete (inv);
            }
        }
    }
};
