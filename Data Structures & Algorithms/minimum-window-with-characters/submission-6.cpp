class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> freqMapS, freqMapT;
        int need=0, have=0, minSize=INT_MAX, minPos=-1;
        for(char ch:t){
            if(!freqMapT.contains(ch))
                need++;
            freqMapT[ch]++;
        }
        for(int l=0, r=0; r<s.size();r++){
            if(!freqMapT.contains(s[r])){
                continue;
            }
            freqMapS[s[r]]++;
            if(freqMapS[s[r]]==freqMapT[s[r]])
                have++;
            while(have==need){
                if(minSize>r-l+1){
                    minSize=r-l+1;
                    minPos=l;
                }
                if(freqMapT.contains(s[l]))
                    freqMapS[s[l]]--;
                if(freqMapT.contains(s[l])&&freqMapT[s[l]]>freqMapS[s[l]])
                    have--;
                l++;
            }
        }
        if(minPos==-1)
            return "";
        return s.substr(minPos, minSize);
    }
};
