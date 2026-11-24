class Solution {
   public:
    void backtrack(unordered_map<int, string>& numPadMap, vector<string>& res, string& digits,
                   string& path, int index) {
        if (index >= digits.size()) {
            res.push_back(path);
            return;
        }
        if (!numPadMap.count(digits[index] - '0')) return;
        for (auto ch : numPadMap[digits[index] - '0']) {
            path += ch;
            backtrack(numPadMap, res, digits, path, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<int, string> numPadMap = {{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                                                {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res = {""};
        // backtrack(numPadMap, res, digits, path, 0);
        for (char digit : digits) {
            if (!numPadMap.count(digit - '0')) return vector<string>();
            vector<string> tmp;
            for (auto& s : res) {
                for (char ch : numPadMap[digit-'0']) {
                    tmp.push_back(s+ch);
                }
            }
            res = tmp;
        }
        return res;
    }
};
