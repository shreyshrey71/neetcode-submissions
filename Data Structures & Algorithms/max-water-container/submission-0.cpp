class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1, maxVolume=-1;
        while(l<r){
            maxVolume = max(maxVolume, min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }
        return maxVolume;
    }
};
