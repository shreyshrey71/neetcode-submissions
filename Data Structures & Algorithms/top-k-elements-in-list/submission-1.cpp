class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int count[2001] = {0};
        priority_queue<pair<int, int>> max_heap;
        vector<int> result;
        for(int i=0; i<nums.size();i++){
            count[1000-nums[i]]++;
        }
        for(int i=0; i<sizeof(count)/sizeof(count[0]); i++){
            max_heap.push({count[i],i});
        }
        for(int i=0;i<k;i++){
            result.push_back(1000 - max_heap.top().second);
            max_heap.pop();
        }
        return result;
    }
};
