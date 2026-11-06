class Solution {
   public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;
        if (n < 2) return (n == 0) ? 0 : 1;
        for (int i = 3; i <= n; i++) {
            int t3 = t2 + t1 + t0;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t2;
    }
};