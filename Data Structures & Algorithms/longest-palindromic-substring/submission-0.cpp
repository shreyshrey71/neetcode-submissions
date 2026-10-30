class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size(), maxR = 0, maxL = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 2 > maxR - maxL) {
                maxL = l + 1;
                maxR = r - 1;
            }
            if (i == n - 1 || s[i] != s[i + 1]) continue;
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 2 > maxR - maxL) {
                maxL = l + 1;
                maxR = r - 1;
            }
        }
        return s.substr(maxL, maxR - maxL + 1);
    }
};
