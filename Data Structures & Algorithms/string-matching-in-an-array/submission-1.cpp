class Solution {
   public:
    bool isSubString(string s1, string s2) {
        if (s1.length() > s2.length()) return isSubString(s2, s1);
        int l1 = s1.length();
        int l2 = s2.length();
        for (int i = 0; i + l1 <= l2; i++) {
            if (s2.substr(i, l1) == s1) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> result;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSubString(words[i], words[j]))
                    (words[i].length() < words[j].length()) ? result.insert(words[i])
                                                            : result.insert(words[j]);
            }
        }
        return vector<string>(result.begin(),result.end());
    }
};