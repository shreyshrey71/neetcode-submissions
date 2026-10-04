class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> uniqueElements;
        int maxSize = 0;
        for (int l = 0, r = 0, j = 0; r < s.size(); r++) {
            uniqueElements[s[r]]++;
            int mFreq = 0;
            for(auto e : uniqueElements)
                mFreq = max(mFreq, e.second);
            while(r-l+1>mFreq+k) {
                uniqueElements[s[l]]--;
                if(uniqueElements[s[l]]==0)
                    uniqueElements.erase(s[l]);
                l++;
                for(auto e : uniqueElements)
                    mFreq = max(mFreq, e.second);
            }
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
