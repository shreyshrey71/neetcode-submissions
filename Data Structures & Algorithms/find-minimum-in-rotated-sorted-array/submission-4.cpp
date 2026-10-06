class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m=0;
        int res=nums[m];
        while (l <= r) {
            m = l + (r - l) / 2;
            res=min(res, nums[m]);
            if(nums[l]<nums[r]){
                res=min(res, nums[l]); 
                break;
                }
            else {
                if(nums[m]>=nums[l])
                    l=m+1;
                else
                    r=m-1;
            }
        }
            // cout<<l<<" "<<r<<" "<<m<<" "<<nums[m]<<endl;
        return res;
    }
};
