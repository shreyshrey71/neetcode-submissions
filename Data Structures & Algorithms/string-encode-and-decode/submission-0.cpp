class Solution {
public:

    string DELIM = "#";

    string encode(vector<string>& strs) {
        string encoded_string;
        for(auto& str : strs) {
            encoded_string += to_string(str.size());
            encoded_string += DELIM;
            encoded_string += str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string str = s;
        if(s == "")
            return strs;
        for(size_t pos = str.find(DELIM); pos<str.length();pos = str.find(DELIM)){
            int len = atoi(str.substr(0,pos).c_str());
            strs.push_back(str.substr(pos+1, len));
            str = str.substr(pos+1+len, str.length());
        }
        return strs;
    }
};
