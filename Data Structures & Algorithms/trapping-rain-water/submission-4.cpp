class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int l = 0, r = height.size() - 1, volume = 0, maxL = height[0], maxR = height[height.size()-1];
        while (l < r) {
            if (maxL <= maxR) {
                l++;
                if (height[l] > maxL)
                    maxL = height[l];
                else
                    volume += (maxL - height[l]);
            } else {
                r--;
                if (height[r] > maxR)
                    maxR = height[r];
                else
                    volume += (maxR - height[r]);
            }
        }
        return volume;
    }
};
