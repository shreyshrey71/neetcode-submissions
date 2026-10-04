class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        vector<int> set1(26,0), set2(26,0);
        int l=0, r=0;
        for(; r<s1.size();r++){
            set1[s1[r]-'a']++;
            set2[s2[r]-'a']++;
        }
        while(r<s2.size()){
            cout<<l<<" "<<r<<endl;
            if(set1 == set2){
                return true;
            }
            set2[s2[l]-'a']--;
            set2[s2[r]-'a']++;
            l++;
            r++;
        }
        if(set1==set2)
            return true;
        return false;
    }
};
