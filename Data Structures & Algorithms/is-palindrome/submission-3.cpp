class Solution {
public:
    bool isValidAlphaNum(char ch){
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        for(int l=0, r = s.size()-1;l<r; l++, r--){
            while(!isValidAlphaNum(s[l]))
                l++;
            while(!isValidAlphaNum(s[r]))
                r--;
            if(l<r && tolower(s[l])!=tolower(s[r]))
                return false;
        }
        return true;
    }
};
