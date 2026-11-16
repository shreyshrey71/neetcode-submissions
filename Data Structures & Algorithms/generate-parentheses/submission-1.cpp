class Solution {
   public:
    void backtrack(int n, int open, int close, string s, unordered_set<string>& v) {
        if (close > open) return;
        if (open == n && close == n) {
            v.insert(s);
            return;
        } else if (open == n) {
            for (int i = close; i < n; i++) s += ")";
            v.insert(s);
            return;
        } else if (open == close) {
            backtrack(n, open + 1, close, s + "(", v);
        }
        backtrack(n, open + 1, close, s + "(", v);
        backtrack(n, open, close + 1, s + ")", v);
    }
    vector<string> generateParenthesis(int n) {
        unordered_set<string> v;
        backtrack(n, 0, 0, "", v);
        return vector<string>(v.begin(), v.end());
    }
};
