class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)
            return s.size();
        int l=0, r=1, maxSubstringLength=0;
        unordered_set<char> uniqueChars;
        uniqueChars.insert(s[l]);
        while(r<s.size()){
            if(uniqueChars.contains(s[r])){
                maxSubstringLength = max(maxSubstringLength, (int) uniqueChars.size());
                while(uniqueChars.contains(s[r])){
                    uniqueChars.erase(s[l]);
                    l++;
                }
            } 
            uniqueChars.insert(s[r]);
            r++;
        }
        maxSubstringLength = max(maxSubstringLength, (int) uniqueChars.size());
        return maxSubstringLength;
    }
};
