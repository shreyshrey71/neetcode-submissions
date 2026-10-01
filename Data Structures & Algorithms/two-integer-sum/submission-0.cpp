class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> untargetedValues;
        for(int i=0; i< nums.size(); i++) {
            if(untargetedValues.contains(target-nums[i]))
                return {untargetedValues[target-nums[i]], i};
            else
                untargetedValues[nums[i]]= i;
        }
    }
};
