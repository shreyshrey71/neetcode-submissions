class Solution {
   public:
    bool wordBreak(string s, unordered_set<string>& dict, unordered_set<string>& memo) {
        if (dict.contains(s)) return true;
        if (memo.contains(s)) return false;
        int n = s.size();
        for (int i = 1; i < s.size(); i++) {
            string spre = s.substr(0, i);
            string spost = s.substr(i, n - i);
            bool pre = wordBreak(spre, dict, memo);
            bool post = wordBreak(spost, dict, memo);
            if (pre && post) {
                dict.insert(spre);
                dict.insert(spost);
                return true;
            } else if (pre) {
                dict.insert(spre);
                memo.insert(spost);
            } else if (post) {
                dict.insert(spost);
                memo.insert(spre);
            } else {
                memo.insert(spre);
                memo.insert(spost);
            }
        }
        memo.insert(s);
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        unordered_set<string> memo;
        for (string word : wordDict) {
            us.insert(word);
        }
        return wordBreak(s, us, memo);
    }
};
