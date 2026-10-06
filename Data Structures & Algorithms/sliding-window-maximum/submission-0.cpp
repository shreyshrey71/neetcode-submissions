class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> mh;
        vector<int> result;
        int l=0, r=0;
        while(r<nums.size()){
            if(r<k){
                mh.push({nums[r], r});
                r++;
            } else {
                while(mh.top().second<l)
                    mh.pop();
                result.push_back(mh.top().first);
                mh.push({nums[r], r});
                l++;
                r++;
            }
        }
                while(mh.top().second<l)
                    mh.pop();
                result.push_back(mh.top().first);
        return result;
    }
};
