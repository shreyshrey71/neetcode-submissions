class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return myPow(1 / x, -1 * n);
        double p = myPow(x, n / 2);
        return (n % 2 == 0) ? p * p : x * p * p;
    }
};
