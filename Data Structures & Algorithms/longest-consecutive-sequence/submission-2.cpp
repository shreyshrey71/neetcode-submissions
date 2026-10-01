class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int lcs=0;
        for(int i=0; i<nums.size(); i++){
            if(!s.contains(nums[i]))
                s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(s.contains(nums[i]-1))
                continue;
            int cs=1;
            for(;s.contains(nums[i]+cs);cs++);
            lcs=max(cs, lcs);
        }
        return lcs;
    }
};
