class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)
            return true;
        else if(s.length()%2==1)
            return false;
        stack<char> st;
        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(st.empty())
                return false;
            else if((st.top()=='(' && ch == ')')||(st.top()=='{' && ch == '}')||(st.top()=='[' && ch == ']'))
                st.pop();
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};
