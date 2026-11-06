class Solution {
   public:
    int hammingWeight(uint32_t n) {
        if (n < 2) return n;
        return n % 2 + hammingWeight(n / 2);
    }
};
