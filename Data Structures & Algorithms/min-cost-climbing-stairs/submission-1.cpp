class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int two = 0;
        int one = cost[n - 1];
        for (int i = n - 1; i > 0; i--) {
            int temp = cost[i - 1];
            temp += min(one, two);
            two = one;
            one = temp;
        }
        return min(one, two);
    }
};
