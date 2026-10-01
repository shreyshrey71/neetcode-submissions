class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, int> mapForS, mapForT;
        for(int i=0; i<s.length(); i++){
            mapForS[s[i]]++;
            mapForT[t[i]]++;
        }
        for(auto i : mapForS){
            if(mapForT[i.first]!=i.second)
                return false;
        }
        return true;
    }
};
