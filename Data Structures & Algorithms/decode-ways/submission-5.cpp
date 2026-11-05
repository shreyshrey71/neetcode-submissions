class Solution {
   public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), 0);
        if (s[0] == '0') return 0;
        dp[0] = 1;
        if (s.length() == 1) return dp[0];
        if ((s[0] == '1' && s[1] == '0') || (s[0] == '2' && s[1] == '0'))
            dp[1] = 1;
        else if(s[1]=='0')
            return 0;
        else if (s[0] == '1' || (s[0] == '2' && s[1] > '0' && s[1] < '7'))
            dp[1] = 2;
        else
            dp[1] = 1;

        for (int i = 2; i < s.length(); i++) {
            if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))
                return 0;
            else if (s[i] == '0')
                dp[i] = dp[i - 2];
            else if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '7'))
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[s.length() - 1];
    }
};
