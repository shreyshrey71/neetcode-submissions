class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> freqMapT, freqMapWindow;
        int minL = 0, minR = s.size();
        for (char ch : t) freqMapT[ch]++;
        for (int l = 0, r = 0; r < s.size(); r++) {
            freqMapWindow[s[r]]++;
            bool containsT = true;
            for (auto ch : freqMapT) {
                if (!freqMapWindow.contains(ch.first) || freqMapWindow[ch.first]<ch.second) {
                    containsT = false;
                    break;
                }
            }
            if (containsT) {
                if (r - l < minR - minL) {
                    minR = r;
                    minL = l;
                }
                if(l==r)
                    continue;
                freqMapWindow[s[l]]--;
                freqMapWindow[s[r]]--;
                if(freqMapWindow[s[l]] == 0)
                    freqMapWindow.erase(s[l]);
                l++;
                r--;
            }
        }
        if(minR==s.size())
            return "";
        return s.substr(minL, minR-minL+1);
    }
};
