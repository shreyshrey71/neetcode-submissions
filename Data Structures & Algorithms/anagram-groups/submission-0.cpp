class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> superMap;
        for(int i=0; i<strs.size();i++){
            map<char,int> charMap;
            for(int j=0; j<strs[i].length();j++){
                charMap[strs[i][j]]++;
            }
            superMap[charMap].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto& pair : superMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};
