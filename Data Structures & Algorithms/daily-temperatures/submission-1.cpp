class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> result(temperatures.size());
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            if(st.empty())
                result[i] = 0;
            else
                result[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }
        return result;
    }
};
