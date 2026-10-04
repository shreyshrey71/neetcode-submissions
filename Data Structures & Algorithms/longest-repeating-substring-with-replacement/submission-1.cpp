class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> uniqueElements;
        int maxSize = 0;
        int maxFreq = 0;
        for (int l = 0, r = 0, j = 0; r < s.size(); r++) {
            uniqueElements[s[r]]++;
            maxFreq = max(maxFreq, uniqueElements[s[r]]);
            while(r-l+1>maxFreq+k) {
                uniqueElements[s[l]]--;
                if(uniqueElements[s[l]]==0)
                    uniqueElements.erase(s[l]);
                l++;
            }
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
