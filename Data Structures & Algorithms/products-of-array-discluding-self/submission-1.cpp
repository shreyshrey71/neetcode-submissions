class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productLeftSide(nums.size(), 1), productRightSide(nums.size(), 1);
        
        for(int i=1; i<nums.size(); i++){
            productLeftSide[i] = productLeftSide[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2; i >=0; i--){
            productRightSide[i] = productRightSide[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            productLeftSide[i]*=productRightSide[i];
        }
        return productLeftSide;
    }
};
