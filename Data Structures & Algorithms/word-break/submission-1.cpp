class Solution {
   public:
    bool wordBreak(string s, unordered_map<string, bool>& memo) {
        if (memo.count(s)) return memo[s];
        int n = s.size();
        for (int i = 1; i < s.size(); i++) {
            string spre = s.substr(0, i);
            string spost = s.substr(i, n - i);
            memo[spre] = wordBreak(spre, memo);
            memo[spost] = wordBreak(spost, memo);
            if (memo[spre] && memo[spost]) {
                return memo[s] = true;
            }
        }
        
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        for (string word : wordDict) {
            memo[word] = true;
        }
        return wordBreak(s, memo);
    }
};
