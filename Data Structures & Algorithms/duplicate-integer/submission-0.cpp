class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> uniqueSet;
        for(int i=0; i< nums.size(); i++){
            if(uniqueSet.contains(nums[i]))
                return true;
            else
                uniqueSet.insert(nums[i]);
        }
        return false;
    }
};