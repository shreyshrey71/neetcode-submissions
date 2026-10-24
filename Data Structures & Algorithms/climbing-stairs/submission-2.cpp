class Solution {
   public:
    int climbStairs(int n) {
        int x = 1, y = 1;
        for (int i = 2; i <= n; i++) {
            y = x + y;
            x = y - x;
        }
        return y;
    }
};
