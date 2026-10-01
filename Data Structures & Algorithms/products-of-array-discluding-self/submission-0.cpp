class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productExceptSelf;
        int product = 1;
        vector<int> loc0;
        if(nums[0]==0)
            loc0.push_back(0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=0)
                product*=nums[i];
            else {
                loc0.push_back(i);
            }
        }
        if(loc0.size()>1){
            productExceptSelf.insert(productExceptSelf.end(), nums.size(), 0);
            return productExceptSelf;
        } else if(loc0.size()==1) {
            if(nums[0]==0){
                productExceptSelf.push_back(product);
                productExceptSelf.insert(productExceptSelf.end(), nums.size()-1, 0);
            } else {
                productExceptSelf.push_back(nums[0]*product);
                productExceptSelf.insert(productExceptSelf.begin(), loc0[0], 0);
                productExceptSelf.insert(productExceptSelf.end(), nums.size()-1-loc0[0], 0);
            }
            return productExceptSelf;
        }
        productExceptSelf.push_back(product);
        for(int i=1; i<nums.size(); i++) {
            product/=nums[i];
            product*=nums[i-1];
            productExceptSelf.push_back(product);
        }
        return productExceptSelf;
    }
};
