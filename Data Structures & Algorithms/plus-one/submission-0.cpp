class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n - 1] != 9) {
            digits[n - 1] += 1;
            return digits;
        }
        int carry = 1;
        digits[n - 1] = 0;
        for (int i = n - 2; i >= 0 && carry != 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
