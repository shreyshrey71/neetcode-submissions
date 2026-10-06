class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1, minK=INT_MAX;
        for(int p : piles)
            high=max(high, p);
        while(low<=high){
            int time=0, k = low + (high - low)/2;
            for(int p : piles)
                time+=(p%k==0)? p/k : p/k + 1;
            if(time>h)
                low=k+1;
            else{
                minK=min(minK, k);
                high=k-1;
            }
        }
        return minK;
    }
};
