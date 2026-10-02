class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> width(heights.size(),0);
        stack<int> st;
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            width[i] = i - ((st.empty())? 0 : st.top() + 1);
            st.push(i);
        }
        cout<<endl;
        st = stack<int>();
        int largestArea=-1;
        for(int i=heights.size() -1; i>=0; i--) {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            width[i] += ((st.empty())? heights.size() - 1 : st.top() - 1) - i + 1;
            st.push(i);
            largestArea = max(largestArea, width[i]*heights[i]);
        }
        return largestArea;
    }
};
