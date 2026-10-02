class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> result;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                result.push_back(l+1); result.push_back(r+1);
                return result;
            }
            if(numbers[l] + numbers[r]<target)
                l++;
            else
                r--;
        }
        return result;
    }
};
