class Solution {
   public:
    void backtrack(unordered_map<int, string>& numPadMap, vector<string>& res, string& digits,
                   string& path, int index) {
        if (index >= digits.size()) {
            res.push_back(path);
            return;
        }
        if(!numPadMap.count(digits[index]-'0'))
            return;
        for(auto ch : numPadMap[digits[index]-'0']){
            path+=ch;
            backtrack(numPadMap, res, digits, path, index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return vector<string>();
        unordered_map<int, string> numPadMap = {{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                                                {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res;
        string path = "";
        backtrack(numPadMap, res, digits, path, 0);
        return res;
    }
};
